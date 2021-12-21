#include <iostream>
#include <vector>
#include <string.h>
#include <utility>
#include <algorithm>
#include <chrono>

struct transformation_t {
    std::pair<char, char>   start;
    char                    finish;
};

std::string doStep(std::string p, std::vector<transformation_t> ts){
    std::string ret;

    ret = p[0];
    for (int i = 1; i < p.size(); i++){
        // std::cout << i << " ";
        for (int j = 0; j < ts.size(); j++){
            if (ts[j].start.first == p[i-1] && ts[j].start.second == p[i]){
                ret += ts[j].finish;
                ret += p[i];
                break;
            }
        }
    }
    // std::cout << std::endl;
    return ret;
}

std::pair<long long int, long long int> getMinMax(std::string p){
    std::vector<long long int>  all;
    long long int               tmp;
    char                        current;

    current = p[0];
    tmp = 0;
    for (int i = 0; i < p.size(); i++){
        if (p[i] == current){
            tmp++;
        } else {
            current = p[i];
            all.push_back(tmp);
            tmp = 1;
        }
    }
    std::sort(all.begin(), all.begin()+all.size());
    return std::make_pair(all[0], all[all.size()-1]);
}

int main(int argc, char const *argv[]) {
    std::vector<transformation_t>           transformations;
    std::pair<long long int, long long int> minMax;
    transformation_t                        tmp;
    std::string                             in;
    std::string                             polymer;
    int                                     nbRounds;

    nbRounds = 40;
    std::cin >> polymer;
    while (std::cin >> in){
        tmp.start.first = in[0];
        tmp.start.second = in[1];
        std::cin >> in;
        std::cin >> tmp.finish;
        transformations.push_back(tmp);
    }
    std::cout << polymer << std::endl;
    for (int i = 0; i < nbRounds; i++){
        auto start = std::chrono::high_resolution_clock::now();
        std::cout << i+1 << " / " << nbRounds << " => ";
        polymer = doStep(polymer, transformations);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
        std::cout << duration.count() << "s." << std::endl;
        // std::cout << i+1 << ": " << polymer << std::endl;
    }
    std::sort(polymer.begin(), polymer.begin()+polymer.size());
    std::cout << polymer << std::endl;
    minMax = getMinMax(polymer);
    std::cout << "min: " << minMax.first << ", max: " << minMax.second << std::endl;
    std::cout << "Res: " << minMax.second-minMax.first << std::endl;
    return 0;
}
