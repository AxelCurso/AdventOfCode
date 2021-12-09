#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

bool sortBasins(char i, char j){
    return (i > j);
}

void printGrid(std::vector< std::vector< int > > grid){
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector< std::vector< int > > fillAdjacent(std::vector< std::vector< int > > nines, int x, int y){
    std::vector< std::vector< int > >   ret;

    // std::cout << "x: " << x << " | y: " << y << std::endl;
    ret = nines;
    ret[y][x] = 1;
    // printGrid(nines);
    // std::cout << "trying y-1" << std::endl;
    if (y-1 >= 0 && nines[y-1][x] == 0){
        // std::cout << "   y-1" << std::endl;
        ret = fillAdjacent(ret, x, y-1);
    }
    // std::cout << "trying y+1" << std::endl;
    if (y+1 < nines.size() && nines[y+1][x] == 0){
        ret = fillAdjacent(ret, x, y+1);
        // std::cout << "   y+1" << std::endl;
    }
    // std::cout << "trying x-1" << std::endl;
    // std::cout << " x-1 >= 0: " << (x-1 >= 0) << std::endl;
    // std::cout << " nines[y][x-1] == 0: " << (nines[y][x-1] == 0) << std::endl;
    if (x-1 >= 0 && nines[y][x-1] == 0){
        ret = fillAdjacent(ret, x-1, y);
        // std::cout << "   x-1" << std::endl;
    }
    // std::cout << "trying x+1" << std::endl;
    if (x+1 < nines[0].size() && nines[y][x+1] == 0){
        ret = fillAdjacent(ret, x+1, y);
        // std::cout << "x+1" << std::endl;
    }
    return ret;
}

int getBasinSize(std::vector< std::vector< int > > grid){
    int count;

    count = 0;
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            if (grid[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}

int getSingleBasin(int y, int x, std::vector< std::vector< int > > nines){
    nines = fillAdjacent(nines, x, y);
    // printGrid(nines);
    // std::cout << std::endl;
    return getBasinSize(nines);
}

int getBasins(std::vector< std::vector< int > > grid){
    int                                 count;
    std::vector< std::vector< int > >   nines;
    std::vector< int >                  tmpVec;

    for (int i = 0; i < grid.size(); i++){
        tmpVec.clear();
        for (int j = 0; j < grid[i].size(); j++){
            if (grid[i][j] == 9){
                tmpVec.push_back(9);
            } else {
                tmpVec.push_back(0);
            }
        }
        nines.push_back(tmpVec);
    }
    printGrid(nines);
    tmpVec.clear();
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            if (j == 0){
                if (i == 0){
                    if (grid[i][j] < grid[i+1][j] && grid[i][j] < grid[i][j+1]){
                        tmpVec.push_back(getSingleBasin(i, j, nines));
                    }
                } else if (i == grid.size()-1){
                    if (grid[i][j] < grid[i-1][j] && grid[i][j] < grid[i][j+1]){
                        tmpVec.push_back(getSingleBasin(i, j, nines));
                    }
                } else {
                    if (grid[i][j] < grid[i][j+1] && grid[i][j] < grid[i-1][j] && grid[i][j] < grid[i+1][j]){
                        tmpVec.push_back(getSingleBasin(i, j, nines));
                    }
                }
            } else if (j == grid[i].size()-1){
                if (i == 0){
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i+1][j]){
                        tmpVec.push_back(getSingleBasin(i, j, nines));
                    }
                } else if (i == grid.size()-1){
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i-1][j]){
                        tmpVec.push_back(getSingleBasin(i, j, nines));
                    }
                } else {
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i-1][j] && grid[i][j] < grid[i+1][j]){
                        tmpVec.push_back(getSingleBasin(i, j, nines));
                    }
                }
            } else {
                if (i == 0){
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i][j+1] && grid[i][j] < grid[i+1][j]){
                        tmpVec.push_back(getSingleBasin(i, j, nines));
                    }
                } else if (i == grid.size()-1){
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i][j+1] && grid[i][j] < grid[i-1][j]){
                        tmpVec.push_back(getSingleBasin(i, j, nines));
                    }
                } else {
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i][j+1] && grid[i][j] < grid[i-1][j] && grid[i][j] < grid[i+1][j]){
                        tmpVec.push_back(getSingleBasin(i, j, nines));
                    }
                }
            }
        }
    }
    std::sort(tmpVec.begin(), tmpVec.begin()+tmpVec.size(), sortBasins);
    count = tmpVec[0];
    count *= tmpVec[1];
    count *= tmpVec[2];
    return count;
}

int main(int argc, char const *argv[]) {
    std::vector< std::vector< int > >  grid;
    std::vector< int >  tmpVec;
    std::string in;
    std::string tmpString;

    while (std::cin >> in){
        tmpVec.clear();
        for (int i = 0; i < in.length(); i++){
            tmpString = "";
            tmpString += in[i];
            tmpVec.push_back(atoi(tmpString.c_str()));
        }
        grid.push_back(tmpVec);
    }
    // printGrid(grid);
    std::cout /*<< "Res: "*/ << getBasins(grid) << std::endl;
    return 0;
}
