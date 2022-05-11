#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){


    char buffer[120];
    char * path2 = "/home/gpsp95/Documents/Analises_yeast/Transição_Estados_Analises/";
    char * pasta;
    int n = 1233;
    sprintf(pasta, "%d.txt", n);

    strcat(strcpy(buffer, path2),  pasta);
    printf("%s\n", buffer);

    return 0;
}