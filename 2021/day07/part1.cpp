#include <iostream>
#include <vector>
#include <algorithm>

int abs(int x){
    if (x > 0){
        return x;
    } else {
        return -x;
    }
}

int getFuelCost(std::vector<int> v, int value){
    int cost;

    cost = 0;
    for (int i = 0; i < v.size(); i++){
        cost += abs(v[i]-value);
    }
    return cost;
}

int main(int argc, char const *argv[]) {
    int                 in;
    char                comma;
    std::vector<int>    crabsPos;
    std::vector<int>    fuelCosts;

    while (std::cin >> in){
        crabsPos.push_back(in);
        std::cin >> comma;
    }
    std::sort(crabsPos.begin(), crabsPos.begin()+crabsPos.size());
    for (int i = crabsPos[0]; i <= crabsPos[crabsPos.size()-1]; i++){
        fuelCosts.push_back(getFuelCost(crabsPos, i));
        std::cout << "Horizontal pos: " << i << "   ->   Fuel costs: " << fuelCosts[i-crabsPos[0]] << std::endl;
    }
    std::sort(fuelCosts.begin(), fuelCosts.begin()+fuelCosts.size());
    std::cout << "Res: " << fuelCosts[0] << std::endl;
    return 0;
}
