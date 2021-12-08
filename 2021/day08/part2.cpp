#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

bool sortString(char i, char j){
    return (i<j);
}

int solveDigits(std::vector< std::string > tens, std::vector< std::string > fours){
    std::string                 digits[10];
    std::vector< std::string >  tmp;
    int                         count;

    // init
    for (int i = 0; i < 10; i++){
        digits[i] = "";
    }

    // get the easy digits
    for (int i = 0; i < 10; i++){
        if (tens[i].length() == 2){
            digits[1] = tens[i];
        } else if (tens[i].length() == 3){
            digits[7] = tens[i];
        } else if (tens[i].length() == 4){
            digits[4] = tens[i];
        } else if (tens[i].length() == 7){
            digits[8] = tens[i];
        }
    }

    // get 0, 6 and 9 => len: 6
    tmp.clear();
    for (int i = 0; i < 10; i++){
        if (tens[i].length() == 6){
            tmp.push_back(tens[i]);
        }
    }
    // 6 misses 1 of the 2 chars from 1
    for (int i = 0; i < tmp.size(); i++){
        count = 0;
        for (int j = 0; j < 6; j++){
            if (tmp[i][j] == digits[1][0] || tmp[i][j] == digits[1][1]){
                count++;
            }
        }
        if (count != 2){
            digits[6] = tmp[i];
            tmp.erase(tmp.begin()+i);
            break;
        }
    }
    // 9 should have every chars from 4
    for (int i = 0; i < tmp.size(); i++){
        count = 0;
        for (int j = 0; j < 6; j++){
            if (tmp[i][j] == digits[4][0] || tmp[i][j] == digits[4][1] || tmp[i][j] == digits[4][2] || tmp[i][j] == digits[4][3]){
                count++;
            }
        }
        if (count == 4){
            digits[9] = tmp[i];
            tmp.erase(tmp.begin()+i);
            break;
        }
    }
    // 0 is the last one in tmp
    digits[0] = tmp[0];

    // get 2, 3 and 5 => len: 5
    tmp.clear();
    for (int i = 0; i < 10; i++){
        if (tens[i].length() == 5){
            tmp.push_back(tens[i]);
        }
    }
    // 2 needs 2 from 4 and 3,5 needs 3 from 4
    for (int i = 0; i < tmp.size(); i++){
        count = 0;
        for (int j = 0; j < 5; j++){
            if (tmp[i][j] == digits[4][0] || tmp[i][j] == digits[4][1] || tmp[i][j] == digits[4][2] || tmp[i][j] == digits[4][3]){
                count++;
            }
        }
        if (count == 2){
            digits[2] = tmp[i];
            tmp.erase(tmp.begin()+i);
            break;
        }
    }
    // 3 needs the 2 chars from 1
    for (int i = 0; i < tmp.size(); i++){
        count = 0;
        for (int j = 0; j < 6; j++){
            if (tmp[i][j] == digits[1][0] || tmp[i][j] == digits[1][1]){
                count++;
            }
        }
        if (count == 2){
            digits[3] = tmp[i];
            tmp.erase(tmp.begin()+i);
            break;
        }
    }
    // 5 is the last one in tmp
    digits[5] = tmp[0];

    // sort strings
    for (int i = 0; i < 10; i++){
        std::sort(digits[i].begin(), digits[i].begin()+digits[i].length(), sortString);
    }
    count = 0;
    for (int i = 0; i < 4; i++){
        std::sort(fours[i].begin(), fours[i].begin()+fours[i].length(), sortString);
        for (int j = 0; j < 10; j++){
            if (fours[i].compare(digits[j]) == 0){
                if (i == 0){
                    count += j*1000;
                } else if (i == 1){
                    count += j*100;
                } else if (i == 2){
                    count += j*10;
                } else if (i == 3){
                    count += j;
                }
                break;
            }
        }
    }

    // print for tests
    // for (int i = 0; i < 10; i++){
    //     std::cout << i << ": " << digits[i] << std::endl;
    // }
    return count;
}

int main(int argc, char const *argv[]) {
    std::vector< std::string >  tens;
    std::vector< std::string >  fours;
    std::string in;
    int         count;

    count = 0;
    while (std::cin >> in){
        tens.clear();
        tens.push_back(in);
        for (int i = 0; i < 9; i++){
            std::cin >> in;
            tens.push_back(in);
        }
        std::cin >> in; // |
        fours.clear();
        for (int i = 0; i < 4; i++){
            std::cin >> in;
            fours.push_back(in);
        }
        // std::cout << solveDigits(tens, fours) << std::endl;
        count += solveDigits(tens, fours);
    }
    std::cout << "Res: " << count << std::endl;
    return 0;
}
