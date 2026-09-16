#include <cstdio>
#include <cstdlib>
#include <cstring>
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
    }

    free(line);
    return 0;
}