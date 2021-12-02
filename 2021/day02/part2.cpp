#include <iostream>
#include <string.h>

int main(int argc, char const *argv[]) {
    int         depth;
    int         horizontal;
    int         aim;
    std::string str;
    int         input;

    depth = 0;
    horizontal = 0;
    aim = 0;
    while (std::cin >> str && std::cin >> input){
        if (str[0] == 'u'){
            aim -= input;
        } else if (str[0] == 'd'){
            aim += input;
        } else {
            horizontal += input;
            depth += aim * input;
        }
    }
    std::cout << "Response: " << horizontal*depth << std::endl;
    return 0;
}
