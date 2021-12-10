#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

void printVec(std::vector<int> v){
    for (int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

long long int getLf(std::vector<int> v){
    int count = 0;
    for (int i = 0; i < v.size(); i++){
        count += v[i];
    }
    return count;
}

int main(int argc, char const *argv[]) {
    int                 in;
    char                comma;
    std::vector<int>    lanternfish;
    std::vector<int>    lfPerDay;
    int                 nbToPush;
    int                 nbRounds;

    nbRounds = 80;
    while (std::cin >> in){
        std::cin >> comma;
        lanternfish.push_back(in);
    }
    for (int i = 0; i < nbRounds; i++){
        lfPerDay.push_back(0);
    }
    for (int i = 0; i < lanternfish.size(); i++){
        lfPerDay[lanternfish[i]]++;
    }
    for (int i = 0; i < nbRounds; i++){
        lfPerDay[i+8] += lfPerDay[i];
        printVec(lfPerDay);
    }
    std::cout << "Res: " << getLf(lfPerDay) << std::endl;
    return 0;
}
