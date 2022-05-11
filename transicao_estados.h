#include <stdio.h>
#include <stdlib.h>


int * geraTransicoesEstados(int * listaAdj, int ** mtz, int m, int ** estados){

    int i, j, est, est_ant, est_prox, r;
    
    int prox_bin[m];
    int tam = potencia(2,m);
    

    for(est = 0; est < tam; est++){
        est_ant = binarioParaDecimal(estados[est]);
        
        for (i = 0; i < m; i++){

            r = 0;
            for (j = 0; j < m; j++){
                r = r + (mtz[i][j] * estados[est][j]);

            }

            if(r == 0){
                prox_bin[i] = estados[est][i];
            }
            else{
                if(r > 0){
                    prox_bin[i] = 1;
                }
                if(r < 0){
                    prox_bin[i] = 0;
                }
            }
        }

        est_prox = binarioParaDecimal(prox_bin);

        listaAdj[est_ant] = est_prox;

    }
    
};

int tamanhoBacia(int * bac, int tam){
    
    int i;
    int soma;

    soma = 0;
    for(i = 0; i < tam; i++){

        if(bac[i] == 1){
            soma++;
        }
    }

    return soma;

};


int contaCiclos(int * lstAdj, int * bacia, int tam){

    int i, ciclos, Noh, prox, n;
    ciclos = 0;

    for (i = 0; i < tam; i++){
        if(bacia[i] == 1){
            Noh = i;
            prox = lstAdj[i];
            n = 0;

            while(Noh != prox){

                Noh = prox;
                prox = lstAdj[Noh];
                n++;
            }

            if(n > 0 && i == prox){
                ciclos++;
            }
        }
    }
    return ciclos;

};


int * baciasCalc(int * lstAdj, int tam, int est){

    int i, j;
    int visitados[tam];
    fila * F;
    int pontos, bac_tam, ciclos;
    int Noh;
    int bacia[tam];

    int * res = (int*) malloc(sizeof(int) * 3);
    zeraLista(res, 3);
    pontos = 0;
    bac_tam = 0;
    ciclos = 0;

    F = criaFila();
    zeraLista(visitados, tam);

    for(i = 0; i < tam; i++){

        if(visitados[i] == 0 && lstAdj[i] == i){

            insereNoh(F, i);
            visitados[i] = 1;
            pontos++;
            zeraLista(bacia, tam);
            bacia[i] = 1;

            while(!filaVazia(F)){

                Noh = removeNoh(F);
                for (j = 0; j < tam; j++){

                    if(lstAdj[j] == Noh && visitados[j] == 0){

                        insereNoh(F,j);
                        visitados[j] = 1;
                        bacia[j] = 1;

                    }
                }
            }

            if (bacia[est] == 1){

                bac_tam = tamanhoBacia(bacia, tam);
                
            }

            ciclos = ciclos + contaCiclos(lstAdj, bacia, tam);
           
        }
    }

    res[0] = pontos;
    res[1] = bac_tam;
    res[2] = ciclos;

    destroiFila(F);

    return res;
}




