#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <utility>

void printPaper(std::vector<std::vector<char> > paper){
    for (int i = 0; i < paper.size(); i++){
        for (int j = 0; j < paper[i].size(); j++){
            std::cout << paper[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<char> > initPaper(std::vector<std::pair<int, int> > dots, int x, int y){
    std::vector<std::vector<char> > ret;
    std::vector<char>               tmp;

    for (int i = 0; i < y+1; i++){
        tmp.clear();
        for (int j = 0; j < x+1; j++){
            tmp.push_back('.');
        }
        ret.push_back(tmp);
    }
    for (int i = 0; i < dots.size(); i++){
        ret[dots[i].second][dots[i].first] = '#';
    }
    return ret;
}

int countDots(std::vector<std::vector<char> > paper){
    int count;

    count = 0;
    for (int i = 0; i < paper.size(); i++){
        for (int j = 0; j < paper[i].size(); j++){
            if (paper[i][j] == '#')
                count++;
        }
    }
    return count;
}

std::vector<std::vector<char> > foldHorizontal(std::vector<std::vector<char> > paper, int y){
    std::vector<std::vector<char> > ret;
    std::vector<char>               tmp;

    for (int i = 0; i < y; i++){
        tmp = paper[i];
        for (int j = 0; j < paper.size(); j++){
            if (paper[(y*2)-i][j] == '#')
                tmp[j] = '#';
        }
        ret.push_back(tmp);
    }
    return ret;
}

std::vector<std::vector<char> > foldVertical(std::vector<std::vector<char> > paper, int x){
    std::vector<std::vector<char> > ret;
    std::vector<char>               tmp;

    for (int i = 0; i < paper.size(); i++){
        tmp.clear();
        for (int j = 0; j < x; j++){
            if (paper[i][j] == '#' || paper[i][(x*2)-j] == '#')
                tmp.push_back('#');
            else
                tmp.push_back('.');
        }
        ret.push_back(tmp);
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    std::vector<std::pair<char, int> >  instructions;
    std::vector<std::pair<int, int> >   dots;
    std::vector<std::vector<char> >     paper;
    std::pair<char, int>    tmpInstruction;
    std::pair<int, int>     tmpDots;
    std::string in;
    int         xMax;
    int         yMax;
    size_t      pos;

    xMax = -1;
    yMax = -1;
    while (std::cin >> in && in != std::string("fold")){
        pos = in.find(",");
        tmpDots.first = atoi(in.substr(0, pos).c_str());
        tmpDots.second = atoi(in.substr(pos+1, in.size()).c_str());
        if (tmpDots.first > xMax)
            xMax = tmpDots.first;
        if (tmpDots.second > yMax)
            yMax = tmpDots.second;
        dots.push_back(tmpDots);
        // std::cout << "x: " << tmpDots.first << ", y: " << tmpDots.second << std::endl;
    }
    std::cin >> in;
    while (std::cin >> in){
        pos = in.find("=");
        tmpInstruction.first = in.c_str()[0];
        tmpInstruction.second = atoi(in.substr(pos+1, in.size()).c_str());
        std::cin >> in;
        std::cin >> in;
        instructions.push_back(tmpInstruction);
        // std::cout << "x: " << tmpInstruction.first << ", y: " << tmpInstruction.second << std::endl;
    }
    paper = initPaper(dots, xMax, yMax);
    printPaper(paper);
    if (instructions[0].first == 'x') {
        std::cout << "folding on vertical x: " << instructions[0].second << std::endl;
        paper = foldVertical(paper, instructions[0].second);
    }
    else {
        std::cout << "folding on horizontal y: " << instructions[0].second << std::endl;
        paper = foldHorizontal(paper, instructions[0].second);
    }
    // printPaper(paper);
    // if (instructions[1].first == 'x') {
    //     std::cout << "folding on vertical x: " << instructions[1].second << std::endl;
    //     paper = foldVertical(paper, instructions[1].second);
    // }
    // else {
    //     std::cout << "folding on horizontal y: " << instructions[1].second << std::endl;
    //     paper = foldHorizontal(paper, instructions[1].second);
    // }
    // printPaper(paper);
    std::cout << "Res: " << countDots(paper) << std::endl;
    return 0;
}
