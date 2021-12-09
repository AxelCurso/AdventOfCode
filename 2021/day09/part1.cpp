#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>

void printGrid(std::vector< std::vector< int > > grid){
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int getRisks(std::vector< std::vector< int > > grid){
    int count;

    count = 0;
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            if (j == 0){
                if (i == 0){
                    if (grid[i][j] < grid[i+1][j] && grid[i][j] < grid[i][j+1]){
                        count += grid[i][j] + 1;
                    }
                } else if (i == grid.size()-1){
                    if (grid[i][j] < grid[i-1][j] && grid[i][j] < grid[i][j+1]){
                        count += grid[i][j] + 1;
                    }
                } else {
                    if (grid[i][j] < grid[i][j+1] && grid[i][j] < grid[i-1][j] && grid[i][j] < grid[i+1][j]){
                        count += grid[i][j] + 1;
                    }
                }
            } else if (j == grid[i].size()-1){
                if (i == 0){
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i+1][j]){
                        count += grid[i][j] + 1;
                    }
                } else if (i == grid.size()-1){
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i-1][j]){
                        count += grid[i][j] + 1;
                    }
                } else {
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i-1][j] && grid[i][j] < grid[i+1][j]){
                        count += grid[i][j] + 1;
                    }
                }
            } else {
                if (i == 0){
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i][j+1] && grid[i][j] < grid[i+1][j]){
                        count += grid[i][j] + 1;
                    }
                } else if (i == grid.size()-1){
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i][j+1] && grid[i][j] < grid[i-1][j]){
                        count += grid[i][j] + 1;
                    }
                } else {
                    if (grid[i][j] < grid[i][j-1] && grid[i][j] < grid[i][j+1] && grid[i][j] < grid[i-1][j] && grid[i][j] < grid[i+1][j]){
                        count += grid[i][j] + 1;
                    }
                }
            }
        }
    }
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
    std::cout << "Res: " << getRisks(grid) << std::endl;
    return 0;
}
