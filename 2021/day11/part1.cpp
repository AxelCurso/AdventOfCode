#include <iostream>
#include <vector>
#include <stdlib.h>

struct point_t {
    int x;
    int y;
};

bool inAlready(std::vector<point_t> a, point_t p){
    for (int i = 0; i < a.size(); i++){
        if (a[i].x == p.x && a[i].y == p.y){
            return true;
        }
    }
    return false;
}

std::vector<std::vector<int> > execStepOne(std::vector<std::vector<int> > board){
    std::vector<std::vector<int> >  ret;

    ret = board;
    for (int i = 0; i < ret.size(); i++){
        for (int j = 0; j < ret[i].size(); j++){
            ret[i][j]++;
        }
    }
    return ret;
}

std::vector<std::vector<int> > execStepTwo(std::vector<std::vector<int> > board, std::vector<point_t> already){
    std::vector<std::vector<int> >  ret;
    std::vector<point_t>            tmpAlready;
    bool    good;
    point_t p;

    ret = board;
    good = false;
    for (int i = 0; i < board.size() && !good; i++){
        for (int j = 0; j < board[i].size() && !good; j++){
            p.x = j;
            p.y = i;
            if (board[i][j] > 9 && !inAlready(already, p)){
                tmpAlready = already;
                tmpAlready.push_back(p);
                good = true;
                if (i == 0){
                    if (j == 0){
                        ret[i][j+1]++;
                        ret[i+1][j]++;
                        ret[i+1][j+1]++;
                    } else if (j == board[i].size()-1){
                        ret[i][j-1]++;
                        ret[i+1][j]++;
                        ret[i+1][j-1]++;
                    } else {
                        ret[i][j-1]++;
                        ret[i][j+1]++;
                        ret[i+1][j-1]++;
                        ret[i+1][j]++;
                        ret[i+1][j+1]++;
                    }
                } else if (i == board.size()-1){
                    if (j == 0){
                        ret[i][j+1]++;
                        ret[i-1][j]++;
                        ret[i-1][j+1]++;
                    } else if (j == board[i].size()-1){
                        ret[i][j-1]++;
                        ret[i-1][j]++;
                        ret[i-1][j-1]++;
                    } else {
                        ret[i][j-1]++;
                        ret[i][j+1]++;
                        ret[i-1][j-1]++;
                        ret[i-1][j]++;
                        ret[i-1][j+1]++;
                    }
                } else {
                    if (j == 0){
                        ret[i-1][j];
                        ret[i-1][j+1];
                        ret[i][j+1];
                        ret[i+1][j];
                        ret[i+1][j+1];
                    } else if (j == board[i].size()-1){
                        ret[i-1][j];
                        ret[i-1][j-1];
                        ret[i][j-1];
                        ret[i+1][j];
                        ret[i+1][j-1];
                    } else {
                        ret[i+1][j-1]++;
                        ret[i+1][j]++;
                        ret[i+1][j+1]++;
                        ret[i][j-1]++;
                        ret[i][j+1]++;
                        ret[i-1][j-1]++;
                        ret[i-1][j]++;
                        ret[i-1][j+1]++;
                    }
                }
            }
        }
    }
    if (good){
        ret = execStepTwo(ret, tmpAlready);
    }
    return ret;
}

std::vector<std::vector<int> > execStepThree(std::vector<std::vector<int> > board){
    std::vector<std::vector<int> >  ret;

    ret = board;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            if (board[i][j] > 9){
                ret[i][j] = 0;
            }
        }
    }
    return ret;
}

void printBoard(std::vector<std::vector<int> > board){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            if (board[i][j] == 0){
                std::cout << "* ";
            } else {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int getFlashCount(std::vector<std::vector<int> > board){
    int     ret;

    ret = 0;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            if (board[i][j] > 9){
                ret++;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int> >  energyLvl;
    std::vector<int>        tmpVec;
    std::vector<point_t>    already;
    char    in;
    int     boardSize;
    int     stepNb;
    int     count;

    boardSize = 10;
    stepNb = 10;

    for (int i = 0; i < boardSize; i++){
        tmpVec.clear();
        for (int j = 0; j < boardSize; j++){
            std::cin >> in;
            tmpVec.push_back(atoi(&in));
        }
        energyLvl.push_back(tmpVec);
    }
    count = 0;
    for (int i = 0; i < stepNb; i++){
        energyLvl = execStepOne(energyLvl);
        already.clear();
        energyLvl = execStepTwo(energyLvl, already);
        count += getFlashCount(energyLvl);
        energyLvl = execStepThree(energyLvl);
        printBoard(energyLvl);
        std::cout << "After step " << i+1 << ": " << count << " flashes!" << std::endl << std::endl;
    }
    return 0;
}
