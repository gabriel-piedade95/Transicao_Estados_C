#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FILA.h"


int potencia(int base, int expoente){

    if (expoente == 0){

        return 1;
    }
    else {

        return (base * potencia(base, expoente - 1));
    }

};

int binarioParaDecimal(int * b){

    int r = 0;
    int i = 0;
    for(i; i < 11; i++){
        
        r = r + (potencia(2, (10 - i)) * b[i]);

    };

    return r;

};

int * numeroBinario(int n){

    int * lista;
    lista = (int *)  malloc(11 * sizeof(int));

    int i = 10;

    for (i; i >= 0; i--){
        
        lista[i] = n%2;
        n = n/2;

    };

    return lista;

};

int ** listaBinario(int n){

    int ** lista;
    int tam = potencia(2, n);
    lista = (int**) malloc( tam * (sizeof(int) * n));
    int i = 0;

    for(i; i < tam; i++){

        lista[i] = numeroBinario(i);

    }

    return lista;
};


int ** alocaMatriz(int lins, int cols){

    int ** mtz = malloc(lins * sizeof(int *));
    int i;

    for (i = 0; i < lins; i++){

        mtz[i] = malloc(cols * sizeof(int));
    }

    return mtz;
};

void liberaMatriz(int ** mtz, int lins){
    
    int i;
    for (i = 0; i < lins; i++){

        free(mtz[i]);
    }

    free(mtz);
};


int ** leDados(char * path, char * dado, int ** mtz){
    
    FILE * arq;

    char buffer[100];
    char c;
    int i, j, lins, cols;
    

    strcat(strcpy(buffer, path), dado);

    arq = fopen(buffer, "r");

    if (arq == NULL){
        printf("Arquivo não encontrado\n");
       return mtz;
    }

    fscanf(arq, "%d %d", &lins, &cols);
    mtz = alocaMatriz(lins, cols);

    for (i = 0; i < lins; i++){

        for (j = 0; j < cols; j++){

            fscanf(arq, "%d", &mtz[i][j]);
            
        }
    }
    fclose(arq);
    return mtz;
    
};


int ** abreArquivo(char * path_arquivo, int ** mtz, int n_ams, int n_genes){
    
    FILE * arq;

    
    char c;
    int i, j;
    

    arq = fopen(path_arquivo, "r");

    if (arq == NULL){
        printf("Arquivo não encontrado\n");
       return mtz;
    }

    mtz = alocaMatriz(n_ams, n_genes);

    for (i = 0; i < n_ams; i++){

        for (j = 0; j < n_genes; j++){

            fscanf(arq, "%d", &mtz[i][j]);
            
        }
    }
    
    rewind(arq);
    fclose(arq);
    return mtz;
    
};




void imprimeMatriz(int ** mtz, int n, int m){

    int i, j;

    for (i = 0; i < n; i++){

        for (j = 0; j < m; j++){

            printf("%d " , mtz[i][j]);
        }

        printf("\n");
    }
};

void imprimeLista(int * lst, int n){

    int i;

    for (i = 0; i < n; i++){

        printf("%d\n", lst[i]);
    }

};

void zeraMatriz(int ** mtz, int tam){

    int i, j;

    for(i = 0; i < tam; i++){

        for(j = 0; j < tam; j++){

            mtz[i][j] = 0;
        }
    }

};

void zeraLista(int * lst, int tam){

    int i;
    for(i = 0; i < tam; i++){
        lst[i] = 0;

    }
};

