#include <stdio.h>
#include <stdlib.h>

struct noh {

    int valor;
    struct noh *prox;

};

typedef struct noh noh;



struct fila
{
    struct noh * inicio;
    struct noh * fim;  
};

typedef struct fila fila;


fila * criaFila(){

    fila * F = (fila*) malloc(sizeof(fila));

    if (F != NULL){

        F->inicio = NULL;
        F->fim = NULL;

    }

    return F;
}

void insereNoh(fila * F, int val){

    noh * novo = (noh*) malloc(sizeof(noh));

    novo->valor = val;
    novo->prox = NULL;

    if(F->inicio == NULL){

        F->inicio = novo;
        F->fim = novo;
    }

    else{

        F->fim->prox = novo;
        F->fim = novo;
    }   
}

int removeNoh(fila * F){
    
    int val = -1;

    if(F->inicio == NULL){

        return val;
    }

    else{
        noh * primeiro;
        primeiro = F->inicio;
        val = 0 + primeiro->valor;
        F->inicio = F->inicio->prox;
        free(primeiro);

    }

    return val;
}

int filaVazia(fila * F){

    if (F->inicio == NULL){

        return 1;
    }

    else{

        return 0;
    }
}

void imprimeFila(fila * F){

    if (F->inicio == NULL){
        printf("Fila Vazia\n");

    }

    else{
        noh * aux;
        aux = F->inicio;

        while(aux != NULL){
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
        free(aux);
    }
}


void destroiFila(fila * F){

    noh * aux;
    
    while (F->inicio != NULL){
        aux = F->inicio;
        F->inicio = F->inicio->prox;
        free(aux);
    }

    free(F);
}

