#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

struct t_point {
    int x;
    int y;
};

struct t_ventsLine {
    t_point start;
    t_point finish;
};

bool isStraight(t_ventsLine vl){
    return (vl.start.x == vl.finish.x || vl.start.y == vl.finish.y);
}

t_point getMaxXnY(std::vector<t_ventsLine> vVL){
    int     x;
    int     y;
    t_point ret;

    x = -1;
    y = -1;
    for (int i = 0; i < vVL.size(); i++){
        if (x < vVL[i].start.x){
            x = vVL[i].start.x;
        }
        if (x < vVL[i].finish.x){
            x = vVL[i].finish.x;
        }
        if (y < vVL[i].start.y){
            y = vVL[i].start.y;
        }
        if (y < vVL[i].finish.y){
            y = vVL[i].finish.y;
        }
    }
    ret.x = x;
    ret.y = y;
    return ret;
}

std::vector<std::vector<int> > lineAddedToGrid(std::vector<std::vector<int> > grid, t_ventsLine vl){
    std::vector<std::vector<int> >  ret;

    ret = grid;
    if (vl.start.x == vl.finish.x){
        if (vl.start.y < vl.finish.y){
            for (int y = vl.start.y; y <= vl.finish.y; y++){
                ret[y][vl.start.x]++;
            }
        } else {
            for (int y = vl.finish.y; y <= vl.start.y; y++){
                ret[y][vl.start.x]++;
            }
        }
    } else {
        if (vl.start.x < vl.finish.x){
            for (int x = vl.start.x; x <= vl.finish.x; x++){
                ret[vl.start.y][x]++;
            }
        } else {
            for (int x = vl.finish.x; x <= vl.start.x; x++){
                ret[vl.start.y][x]++;
            }
        }
    }
    return ret;
}

int getOverlap(std::vector<std::vector<int> > grid){
    int count;

    count = 0;
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            if (grid[i][j] > 1){
                count++;
            }
        }
    }
    return count;
}

void printPoint(t_point p){
    std::cout << p.x << "," << p.y << std::endl;
}

void printVentsLine(t_ventsLine vl){
    std::cout << vl.start.x << "," << vl.start.y << ":" << vl.finish.x << "," << vl.finish.y << std::endl;
}

void printGrid(std::vector<std::vector<int> > g){
    for (int i = 0; i < g.size(); i++){
        for (int j = 0; j < g[i].size(); j++){
            std::cout << g[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    std::string                     in;
    size_t                          pos;
    t_ventsLine                     tmpVL;
    std::vector<t_ventsLine>        vVL;
    std::vector<t_ventsLine>        vOnlyStraights;
    t_point                         maxXnY;
    std::vector<std::vector<int> >  grid;
    std::vector<int>                tmpVec;

    while (std::cin >> in){
        // its the first point
        pos = in.find(",");
        tmpVL.start.x = atoi(in.substr(0, pos).c_str());
        in.erase(0, pos+1);
        tmpVL.start.y = atoi(in.c_str());

        std::cin >> in;
        // ->

        std::cin >> in;
        // its the second point
        pos = in.find(",");
        tmpVL.finish.x = atoi(in.substr(0, pos).c_str());
        in.erase(0, pos+1);
        tmpVL.finish.y = atoi(in.c_str());

        vVL.push_back(tmpVL);
    }
    for (int i = 0; i < vVL.size(); i++){
        if (isStraight(vVL[i])){
            vOnlyStraights.push_back(vVL[i]);
        }
    }
    maxXnY = getMaxXnY(vOnlyStraights);
    for (int i = 0; i < maxXnY.y+1; i++){
        tmpVec.clear();
        for (int j = 0; j < maxXnY.x+1; j++){
            tmpVec.push_back(0);
        }
        grid.push_back(tmpVec);
    }
    for (int i = 0; i < vOnlyStraights.size(); i++){
        grid = lineAddedToGrid(grid, vOnlyStraights[i]);
    }
    std::cout << "Res: " << getOverlap(grid) << std::endl;
    return 0;
}
