#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>

int main(int argc, char const *argv[]) {
    std::vector<std::string>    oxy;
    std::vector<std::string>    coo;
    std::string                 tmp;
    std::vector<std::string>    tmpVector;
    int                         i;
    int                         notI;
    int                         j;
    int                         k;

    while (std::cin >> tmp){
        oxy.push_back(tmp);
        coo.push_back(tmp);
    }
    for (j = 0; j < oxy[0].length() && oxy.size() > 1; j++){
        i = 0;
        notI = 0;
        for (k = 0; k < oxy.size(); k++){
            if (oxy[k][j] == '1'){
                i++;
            } else {
                notI++;
            }
        }
        tmpVector.clear();
        for (k = 0; k < oxy.size(); k++){
            if (i >= notI && oxy[k][j] == '1'){
                tmpVector.push_back(oxy[k]);
            } else if (i < notI && oxy[k][j] == '0'){
                tmpVector.push_back(oxy[k]);
            }
        }
        oxy = tmpVector;
    }
    for (j = 0; j < coo[0].length() && coo.size() > 1; j++){
        i = 0;
        notI = 0;
        for (k = 0; k < coo.size(); k++){
            if (coo[k][j] == '1'){
                i++;
            } else {
                notI++;
            }
        }
        tmpVector.clear();
        for (k = 0; k < coo.size(); k++){
            if (notI <= i && coo[k][j] == '0'){
                tmpVector.push_back(coo[k]);
            } else if (i < notI && coo[k][j] == '1'){
                tmpVector.push_back(coo[k]);
            }
        }
        coo = tmpVector;
    }
    j = 0;
    k = 0;
    for (i = oxy[0].length()-1; i >= 0; i--){
        j += (oxy[0][i] == '1') ? pow(2, oxy[0].length()-1-i) : 0;
        k += (coo[0][i] == '1') ? pow(2, oxy[0].length()-1-i) : 0;
    }
    std::cout << "Oxygen: " << j << std::endl;
    std::cout << "Co2: " << k << std::endl;
    std::cout << "Res: " << j * k << std::endl;
    return 0;
}
