#include <iostream>
#include <string.h>

int main(int argc, char const *argv[]) {
    int             vert;
    int             hori;
    std::string     str;
    int             input;

    vert = 0;
    hori = 0;
    while (std::cin >> str && std::cin >> input){
        if (str[0] == 'f'){
            hori += input;
        } else if (str[0] == 'u'){
            vert -= input;
        } else {
            vert += input;
        }
    }
    std::cout << "Response: " << vert*hori << std::endl;
    return 0;
}
