#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int                 in;
    char                comma;
    std::vector<int>    lanternfish;
    int                 nbToPush;

    while (std::cin >> in){
        std::cin >> comma;
        lanternfish.push_back(in);
    }
    for (int i = 0; i < 80; i++){
        nbToPush = 0;
        for (int j = 0; j < lanternfish.size(); j++){
            if (lanternfish[j]){
                lanternfish[j]--;
            } else {
                lanternfish[j] = 6;
                nbToPush++;
            }
        }
        for (int j = 0; j < nbToPush; j++){
            lanternfish.push_back(8);
        }
    }
    std::cout << "Res: " << lanternfish.size() << std::endl;
    return 0;
}
