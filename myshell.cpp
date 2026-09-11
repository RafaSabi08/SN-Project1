#include <iostream>
#include <string>
#include "param.hpp"
#include "parse.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    string input;
    bool isDebugOn = false;
    if(argc == 2) {
        if(string(argv[1]) == "-Debug"){
            isDebugOn = true;
        }
    }
    while(true) {
        cout << "$$$ ";
        getline(cin, input);
        if(input == "exit") {
            break;
        } else {
            Param param;
            parseTokens((char*)input.c_str(), &param);
        }

        if(isDebugOn) {
            // printParams();
        }
    }

    return 0;
}
