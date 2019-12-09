#include <stdio.h>
#include <stdlib.h>

struct  Data{
    int     *d;
    int     *afterCalc;
    int     len;
};

void    getData(char *file, Data &data){
    FILE    *fptr;
    char    c;
    int     i;
    bool    inNum;

    if ((fptr = fopen(file, "r")) == NULL){
       printf("Error! Can open the file just one time");
       exit(1);
    }
    data.len = 0;
    while ((c = fgetc(fptr)) != EOF){
        if (c == '\n'){
            data.len++;
        }
    }
    data.d = (int*)malloc(sizeof(int) * data.len);
    data.afterCalc = (int*)malloc(sizeof(int) * data.len);
    fseek(fptr, 0, SEEK_SET);
    i = 0;
    inNum = false;
    while ((c = fgetc(fptr)) != EOF){
        if (c == '\n'){
            i++;
            inNum = false;
        } else if (!inNum){
            data.d[i] = c - '0';
            inNum = true;
        } else {
            data.d[i] *= 10;
            data.d[i] += c - '0';
        }
    }
    fclose(fptr);
}

void    getValues(Data &data){
    int     i;

    for (i = 0; i < data.len; i++){
        data.afterCalc[i] = data.d[i] / 3 - 2;
    }
}

int     getFuel(Data &data){
    int     i;
    int     value;

    value = 0;
    for (i = 0; i < data.len; i++){
        value += data.afterCalc[i];
    }
    return (value);
}

int     main(int ac, char **av){
    Data    data;

    if (ac != 2){
        printf("Usage: ./a.out file.txt (fill contains the values for the calculation of the fuel)\n");
        exit(1);
    }
    getData(av[1], data);
    getValues(data);
    printf("%i\n", getFuel(data));
    return (0);
}
