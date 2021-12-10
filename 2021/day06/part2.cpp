#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int                 in;
    char                comma;
    std::vector<int>    lanternfish;
    std::vector<int>    nbLanternfishPerDay;
    int                 nbToPush;
    long long int       count;
    long long int       tmp;

    while (std::cin >> in){
        std::cin >> comma;
        lanternfish.push_back(in);
    }
    for (int i = 0; i < 256; i++){
        nbLanternfishPerDay.push_back(0);
    }
    for (int i = 0; i < lanternfish.size(); i++){
        tmp = (256-lanternfish[i])/7;
        for (int j = 0; j < tmp; j++){
            nbLanternfishPerDay[j*7+lanternfish[i]]++;
        }
        count += tmp;
    }
    std::cout << "1 / 256   ->   " << count << std::endl;
    for (int i = 1; i < 256; i++){
        tmp = (256-i)/7;
        count += tmp;
        for (int j = 0; j < tmp; j++){
            nbLanternfishPerDay[j*7+i]++;
        }
        std::cout << i+1 << " / 256   ->   " << count << std::endl ;
        // std::cout << i << " / 256   ->   " << lanternfish[i] << std::endl ;
        // nbToPush = 0;
        // for (int j = 0; j < lanternfish.size(); j++){
        //     if (lanternfish[j]){
        //         lanternfish[j]--;
        //     } else {
        //         lanternfish[j] = 6;
        //         nbToPush++;
        //     }
        // }
        // for (int j = 0; j < nbToPush; j++){
        //     lanternfish.push_back(8);
        // }
    }
    count = 0;
    for (int i = 0; i < 256; i++){
        count += nbLanternfishPerDay[i];
    }
    // std::cout << "Res: " << lanternfish.size() << std::endl;
    std::cout << "Res: " << count << std::endl;
    return 0;
}
