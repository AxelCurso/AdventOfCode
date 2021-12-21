#include <iostream>
#include <string.h>
#include <utility>

int main(int argc, char const *argv[]) {
    int         pos1;
    int         pos2;
    int         score1;
    int         score2;
    std::string in;
    int         die;
    int         tmp;

    score1 = 0;
    score2 = 0;
    std::cin >> in;
    std::cin >> in;
    std::cin >> in;
    std::cin >> in;
    std::cin >> in;
    pos1 = atoi(in.c_str());
    std::cin >> in;
    std::cin >> in;
    std::cin >> in;
    std::cin >> in;
    std::cin >> in;
    pos2 = atoi(in.c_str());

    die = 1;
    while (score1 < 1000 && score2 < 1000){
        tmp = (die % 100) + ((die+1) % 100) + ((die+2) % 100);
        die += 3;
        pos1 += tmp;
        pos1 %= 10;
        score1 += (pos1 == 0 ? 10 : pos1);
        if (score1 >= 1000)
            break;
        tmp = (die % 100) + ((die+1) % 100) + ((die+2) % 100);
        die += 3;
        pos2 += tmp;
        pos2 %= 10;
        score2 += (pos2 == 0 ? 10 : pos2);
    }
    std::cout << "Nb rolls: " << die-1 << std::endl;
    std::cout << "Player 1: " << score1 << std::endl;
    std::cout << "Player 2: " << score2 << std::endl;
    std::cout << "Res: " << (die-1) * (score1 < 1000 ? score1 : score2) << std::endl;
    return 0;
}
