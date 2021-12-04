#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>

int main(int argc, char const *argv[]) {
    std::vector<std::string>    bins;
    std::string                 tmp;
    std::string                 subTmp;
    int                         i;
    int                         notI;
    int                         j;
    int                         k;

    while (std::cin >> tmp){
        bins.push_back(tmp);
    }
    subTmp = tmp;
    for (j = 0; j < bins[0].length(); j++){
        i = 0;
        notI = 0;
        for (k = 0; k < bins.size(); k++){
            if (bins[k][j] == '1'){
                i++;
            } else {
                notI++;
            }
        }
        tmp[j] = (i > notI) ? '1' : '0';
        subTmp[j] = (i > notI) ? '0' : '1';
    }
    std::cout << "tmp: " << tmp << std::endl;
    std::cout << "subTmp: " << subTmp << std::endl;
    j = 0;
    k = 0;
    for (i = tmp.length()-1; i >= 0; i--){
        j += (tmp[i] == '1') ? pow(2, tmp.length()-1-i) : 0;
        k += (subTmp[i] == '1') ? pow(2, tmp.length()-1-i) : 0;
    }
    std::cout << "gamma: " << j << std::endl;
    std::cout << "epsilon: " << k << std::endl;
    std::cout << "Res: " << j * k << std::endl;
    return 0;
}
