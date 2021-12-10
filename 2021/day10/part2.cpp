#include <iostream>
#include <string.h>
#include <stack>
#include <vector>
#include <algorithm>

bool sortVec(long long int a, long long int b){
    return (a < b);
}

long long int findCompletionIfNoError(std::string str){
    int                 ptsBrace;
    int                 ptsSquareBracket;
    int                 ptsBracket;
    int                 ptsPointedBracket;
    std::stack<char>    s;
    long long int       count;

    ptsBrace = 1;
    ptsSquareBracket = 2;
    ptsBracket = 3;
    ptsPointedBracket = 4;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<'){
            s.push(str[i]);
        } else {
            if (str[i] == ')' && s.top() == '('){
                s.pop();
            } else if (str[i] == ']' && s.top() == '['){
                s.pop();
            } else if (str[i] == '}' && s.top() == '{'){
                s.pop();
            } else if (str[i] == '>' && s.top() == '<'){
                s.pop();
            } else {
                return 0;
            }
        }
    }
    count = 0;
    while (!s.empty()){
        count *= 5;
        if (s.top() == '('){
            count += ptsBrace;
        } else if (s.top() == '['){
            count += ptsSquareBracket;
        } else if (s.top() == '{'){
            count += ptsBracket;
        } else if (s.top() == '<'){
            count += ptsPointedBracket;
        }
        s.pop();
    }
    // std::cout << count << std::endl;
    return count;
}

int main(int argc, char const *argv[]) {
    std::string                 in;
    long long int               resFromIn;
    std::vector<long long int>  count;

    while (std::cin >> in){
        resFromIn = findCompletionIfNoError(in);
        if (resFromIn){
            count.push_back(resFromIn);
        }
    }
    std::sort(count.begin(), count.begin()+count.size());
    for (int i = 0; i < count.size(); i++){
        std::cout << i << ": " << count[i] << std::endl;
    }
    std::cout << "Size of count: " << count.size() << std::endl;
    std::cout << "Res: " << count[count.size()/2] << std::endl;
    return 0;
}
