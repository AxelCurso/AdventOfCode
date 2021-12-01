#include <iostream>

int main(int argc, char const *argv[]) {
    int one;
    int two;
    int three;
    int tmp;
    int current;
    int previous;
    int ret;

    ret = 0;
    std::cin >> one;
    std::cin >> two;
    std::cin >> three;
    previous = one + two + three;
    while (std::cin >> tmp){
        //current = previous - one + tmp;
        one = two;
        two = three;
        three = tmp;
        current = one + two + three;
        if (current > previous){
            ret++;
        }
        previous = current;
    }
    std::cout << "Ret: " << ret << std::endl;
    return 0;
}
