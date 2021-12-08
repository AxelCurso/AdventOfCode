#include <iostream>
#include <string.h>

bool isInRange(std::string str){
    return (str.length() == 2 || str.length() == 3 || str.length() == 4 || str.length() == 7);
}

int main(int argc, char const *argv[]) {
    int         count;
    std::string in;

    count = 0;
    while (std::cin >> in){
        std::cin >> in;
        std::cin >> in;
        std::cin >> in;
        std::cin >> in;
        std::cin >> in;
        std::cin >> in;
        std::cin >> in;
        std::cin >> in;
        std::cin >> in;
        // |
        std::cin >> in;
        // inputs
        std::cin >> in;
        std::cout << in;
        if (isInRange(in)){
            count++;
        }
        std::cin >> in;
        std::cout << in;
        if (isInRange(in)){
            count++;
        }
        std::cin >> in;
        std::cout << in;
        if (isInRange(in)){
            count++;
        }
        std::cin >> in;
        std::cout << in;
        if (isInRange(in)){
            count++;
        }
        std::cout << std::endl;
    }
    std::cout << "Res: " << count << std::endl;
    return 0;
}
