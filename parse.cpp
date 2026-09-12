#include <iostream>
#include "parse.hpp"
#include "param.hpp"
#include <cstring>

void parseTokens(char* input, Param* param) {
    char* token = strtok(input, " \t\n");
    while(token != NULL) {
        if(token[0] == '<') {
            if(token[1] == '\0') {
                std::cerr << "Error: No input file specified after '<'" << std::endl;
                return;
            }
            param->setInputRedirect(token + 1);
        } else if(token[0] == '>') {
            if(token[1] == '\0') {
                std::cerr << "Error: No output file specified after '>'" << std::endl;
                return;
            }
            param->setOutputRedirect(token + 1);
        } else if(strcmp(token, "&") == 0) {
            param->setBackground(1);
        } else {
            param->addArgument(token);
        }
        token = strtok(NULL, " \t\n");
    }
}