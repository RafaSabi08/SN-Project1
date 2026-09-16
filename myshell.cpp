#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include "param.hpp"
#include "parse.hpp"

int main(int argc, char const *argv[])
{
    bool isDebugOn = false;
    if (argc == 2 && strcmp(argv[1], "-Debug") == 0) {
        isDebugOn = true;
    }

    char *line = NULL;
    size_t bufferSize = 0;

    while (true) {
        Param param;
        printf("$$$ ");
        fflush(stdout);

        ssize_t charsRead = getline(&line, &bufferSize, stdin);
        if (charsRead == -1) {
            break;
        }

        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[length - 1] = '\0';
        }

        if (strcmp(line, "exit") == 0) {
            break;
        }

        parseTokens(line, &param);

        if (isDebugOn) {
            param.printParams();
        }

        char **args = param.getArguments();

        if (args[0] == NULL) {
            continue;  // usuario so apertou Enter
        }

        pid_t pid = fork();
        fflush(stdout);

        if (pid == 0) {
            execvp(args[0], args);
            fprintf(stderr, "myshell: comando nao encontrado: %s\n", args[0]);
            exit(1);
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        } else {
            perror("myshell: fork falhou");
        }
    }

    free(line);
    return 0;
}