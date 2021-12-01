#include <iostream>

int main(int argc, char const *argv[]) {
    int current;
    int previous;
    int ret;

    ret = 0;
    std::cin >> previous;
    while (std::cin >> current){
        std::cout << current << std::endl;
        if (current >= previous){
            ret++;
        }
        previous = current;
    }
    std::cout << "Ret: " << ret << std::endl;
    return 0;
}
