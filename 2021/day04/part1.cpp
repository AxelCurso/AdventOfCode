#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

int checkWin(std::vector< std::vector< int > > b){
    int count;

    for (int i = 0; i < 5; i++){
        count = 0;
        for (int j = 0; j < 5; j++){
            if (b[i][j] == -1){
                count++;
            }
        }
        if (count == 5){
            return 1;
        }
        count = 0;
        for (int j = 0; j < 5; j++){
            if (b[j][i] == -1){
                count++;
            }
        }
        if (count == 5){
            return 1;
        }
    }
    return 0;
}

void printBoard(std::vector< std::vector< int > > b){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int getNotSelected(std::vector< std::vector< int > > b){
    int count;

    count = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (b[i][j] != -1){
                count += b[i][j];
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[]) {
    std::vector< std::vector< std::vector< int > > >    boards;
    std::vector< std::vector< int> >    tmpBoard;
    std::vector< int >  tmpLine;
    std::vector< int >  draws;
    std::string draw;
    std::string tmpDraw;
    int         nbBoards;
    int         tmp;
    size_t      pos;
    int         winningBoard;
    int         notSelected;
    int         i;
    int         b;

    std::cin >> draw;
    std::cout << "Draw: " << draw << std::endl;

    nbBoards = 100;
    while (std::cin >> tmp){
        tmpLine.push_back(tmp);
        if (tmpLine.size() == 5){
            tmpBoard.push_back(tmpLine);
            if (tmpBoard.size() == 5){
                boards.push_back(tmpBoard);
                tmpBoard.clear();
            }
            tmpLine.clear();
        }
    }
    std::cout << "Should be 100 boards: " << boards.size() << std::endl;

    while ((pos = draw.find(",")) != std::string::npos) {
        tmpDraw = draw.substr(0, pos);
        draw.erase(0, pos+1);
        draws.push_back(atoi(tmpDraw.c_str()));
    }
    draws.push_back(atoi(draw.c_str()));
    std::cout << "Size of the draw: " << draws.size() << std::endl;

    winningBoard = -1;
    for (i = 0; i < draws.size() && winningBoard == -1; i++){
        for (b = 0; b < nbBoards && winningBoard == -1; b++){
            for (int line = 0; line < 5 && winningBoard == -1; line++){
                for (int column = 0; column < 5 && winningBoard == -1; column++){
                    if (draws[i] == boards[b][line][column]){
                        boards[b][line][column] = -1;
                        if (checkWin(boards[b])){
                            std::cout << b << std::endl;
                            printBoard(boards[b]);
                            winningBoard = b;
                            break;
                        }
                    }
                }
            }
        }
    }
    notSelected = getNotSelected(boards[winningBoard]);
    std::cout << "notSelected: " << notSelected << " | lastDraw: " << draws[i-1] << std::endl;
    std::cout << "Res: " << notSelected * draws[i-1] << std::endl;
    return 0;
}
