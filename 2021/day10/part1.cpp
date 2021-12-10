#include <iostream>
#include <string.h>
#include <stack>

char findError(std::string str){
    std::stack<char>    s;

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
                return str[i];
            }
        }
    }
    return ' ';
}

int main(int argc, char const *argv[]) {
    std::string in;
    int         ptsBrace;
    int         ptsSquareBracket;
    int         ptsBracket;
    int         ptsPointedBracket;
    char        resFromIn;
    int         count;

    ptsBrace = 3;
    ptsSquareBracket = 57;
    ptsBracket = 1197;
    ptsPointedBracket = 25137;
    while (std::cin >> in){
        resFromIn = findError(in);
        if (resFromIn == ')'){
            count += ptsBrace;
        } else if (resFromIn == ']'){
            count += ptsSquareBracket;
        } else if (resFromIn == '}'){
            count += ptsBracket;
        } else if (resFromIn == '>'){
            count += ptsPointedBracket;
        }
    }
    std::cout << "Res: " << count << std::endl;
    return 0;
}
