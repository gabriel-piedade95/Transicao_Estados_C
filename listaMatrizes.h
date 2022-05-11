#include <stdio.h>
#include <stdlib.h>

struct noh {
    
    int gene;
    int linhas;
    int colunas;
    int ** matriz;
    struct noh * prox;

};

typedef struct noh noh;


struct lista {

    struct noh * inicio;
    struct noh * fim;
    int tam;
};

typedef struct lista lista;


lista * criaListaM(){
    
    lista * L = (lista*) malloc(sizeof(lista));
    
    L->inicio = NULL;
    L->fim = NULL;
    L->tam = 0;
    
    return L;

}

void liberaNoh(noh * N){

    int i;
    
    for (i = 0; i < N->linhas; i ++){
    
        free(N->matriz[i]);
    }
    
    free(N->matriz);
    free(N);
};



void liberaListaM(lista * L){

    int i;
    noh * aux;
    
    while(L->inicio != NULL){
    
        aux = L->inicio->prox;
        liberaNoh(L->inicio);
        L->inicio = aux;
        
    }
    
    free(L);

}

void insereNohLista(lista * L, int gene, int linhas, int colunas, int mtz){

    noh * novo = (noh*)malloc(sizeof(noh));
    int i, j;

    novo->gene = gene;
    novo->linhas =linhas;
    novo->colunas = colunas;

    for(i = 0; i < linhas; i++){

        for (j = 0; j < colunas; j++){

            novo->matriz[i][j] = mtz[i][j];
        }
    }

    
    novo->prox = NULL;
    
    if(L->inicio == NULL){
    
        L->inicio = novo;
    }
    
    else{
        
        
    
    }

};