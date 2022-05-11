#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "transicao_estados.h"


int main(){

    /// ABRE ARQUIVOS ///

    char * mtz_arq = "mtz_wt_c.txt";
    char * estados_wt_arq = "estados_c.txt";
    char * path = "/home/gpsp95/Documents/Analises_yeast/dados/";
    char * path2 = "/home/gpsp95/Documents/Analises_yeast/Transição_Estados_Analises/";
    char * path3 = "/home/gpsp95/Área de Trabalho/projetos programação/TRANSICAO_ESTADOS_C/";
    

    ///ALOCA DADOS ////

    int ** mtz;
    int * bacias;
    int ** estados;
    int * listaAdj;
    int i, pontos, tam, n_genes, est;
    int ** est_wt;
    int ** genes_linhas;
    int n_amostras;
    int *** lista_mtzs;

    /// INICIA VARIAVEIS ///

    n_amostras = 1000;
    n_genes = 11;
    tam = potencia(2, n_genes);

    est_wt = leDados(path, estados_wt_arq, est_wt);
    mtz = leDados(path, mtz_arq, mtz);
    est = binarioParaDecimal(est_wt[13]);
    
    
    estados = listaBinario(n_genes);
    listaAdj = (int*) malloc(sizeof(int) * tam);
    zeraLista(listaAdj, tam);

    
    geraTransicoesEstados(listaAdj, mtz, n_genes, estados) ;
    bacias = baciasCalc(listaAdj, tam, est);
    
    lista_mtzs = abreLinhasGenes(path3, "gene_yeast.txt", 0, 11, lista_mtzs);



    //// LIBERA MEMORIA////
    liberaMatriz(mtz, n_genes);
    liberaMatriz(estados, tam);
    liberaMatriz(est_wt, 14);
    liberaListaMatrizes(lista_mtzs, n_genes);
    
    free(listaAdj);
    free(bacias);

    return 0;
}