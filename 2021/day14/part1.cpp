#include <iostream>
#include <vector>
#include <string.h>
#include <utility>
#include <algorithm>

struct transformation_t {
    std::pair<char, char>   start;
    char                    finish;
};

std::string doStep(std::string p, std::vector<transformation_t> ts){
    std::string ret;

    ret = p[0];
    for (int i = 1; i < p.size(); i++){
        for (int j = 0; j < ts.size(); j++){
            if (ts[j].start.first == p[i-1] && ts[j].start.second == p[i]){
                ret += ts[j].finish;
                ret += p[i];
                break;
            }
        }
    }
    return ret;
}

std::pair<int, int> getMinMax(std::string p){
    std::vector<int>    all;
    int                 tmp;
    char                current;

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
    std::vector<transformation_t>   transformations;
    std::pair<int, int>             minMax;
    transformation_t                tmp;
    std::string                     in;
    std::string                     polymer;
    int                             nbRounds;

    nbRounds = 10;
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
        polymer = doStep(polymer, transformations);
        // std::cout << i+1 << ": " << polymer << std::endl;
    }
    std::sort(polymer.begin(), polymer.begin()+polymer.size());
    std::cout << polymer << std::endl;
    minMax = getMinMax(polymer);
    std::cout << "min: " << minMax.first << ", max: " << minMax.second << std::endl;
    std::cout << "Res: " << minMax.second-minMax.first << std::endl;
    return 0;
}
