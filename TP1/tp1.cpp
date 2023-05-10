#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

int main() {
    std::ifstream osversionfile("/etc/os-release");
    std::string osversionline;
    while (std::getline(osversionfile, osversionline)) {
        std::cout << osversionline << std::endl;
    }
    osversionfile.close();

    std::ifstream mynamefile("/gabrielscota/GABRIEL.txt");
    std::string mynameline;
    while (std::getline(mynamefile, mynameline)) {
        std::cout << mynameline << std::endl;
    }
    mynamefile.close();

    system("/gabrielscota/shellscript.sh");
    return 0;
}
