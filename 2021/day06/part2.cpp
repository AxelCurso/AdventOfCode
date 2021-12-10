#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

void printVec(std::vector<long long int> v){
    for (int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

long long int getLf(std::vector<long long int> v){
    long long int count = 0;
    for (int i = 0; i < v.size(); i++){
        count += v[i];
    }
    return count;
}

int main(int argc, char const *argv[]) {
    int                 in;
    char                comma;
    std::vector<int>    lanternfish;
    std::vector<long long int>    lfPerDay;
    long long int            nbToPush;
    int                 nbRounds;

    nbRounds = 256;
    while (std::cin >> in){
        std::cin >> comma;
        lanternfish.push_back(in);
    }
    for (int i = 0; i < 9; i++){
        lfPerDay.push_back(0);
    }
    for (int i = 0; i < lanternfish.size(); i++){
        lfPerDay[lanternfish[i]]++;
    }
    printVec(lfPerDay);
    for (int i = 0; i < nbRounds; i++){
        nbToPush = lfPerDay[0];
        lfPerDay[0] = lfPerDay[1];
        lfPerDay[1] = lfPerDay[2];
        lfPerDay[2] = lfPerDay[3];
        lfPerDay[3] = lfPerDay[4];
        lfPerDay[4] = lfPerDay[5];
        lfPerDay[5] = lfPerDay[6];
        lfPerDay[6] = lfPerDay[7];
        lfPerDay[7] = lfPerDay[8];

        lfPerDay[6] += nbToPush;
        lfPerDay[8] = nbToPush;

        std::cout << i+1 << ": ";
        printVec(lfPerDay);
    }
    std::cout << "Res: " << getLf(lfPerDay) << std::endl;
    return 0;
}
