#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Dados.h"

void inicializarMesa(Tabuleiro M[28]){
    int k = 0, f = 0;
    Domino *aux;
    for(int i = 0; i < 28; i++){
        aux = (Domino*)malloc(sizeof(Domino));
        if(f == 7){
            k++;
            f = k;
            aux->d = k;
            aux->e = f;
            aux->s = aux->d + aux->e;
        }else{
            aux->d = k;
            aux->e  = f;
            aux->s = aux->d + aux->e;
        }
        M[i].p = aux;
        aux = NULL;
        f++;
    }
}

void inicializarMao(Tabuleiro mP1[], Tabuleiro mP2[]){
    for(int i = 0; i < 28; i++){
        mP1[i].p = NULL;
        mP2[i].p = NULL;
    }
}

void darMaos(Tabuleiro mP1[], Tabuleiro mP2[], Tabuleiro M[]){
    int aux = 0, i = 0, k = 0, cont = 0;
    srand(time(NULL));
    while(cont < 14){
        aux = rand()%28;
        if(cont < 7 && M[aux].p != NULL){
            mP1[i].p = M[aux].p;
            M[aux].p = NULL;
            i++;
            cont++;
        }else{
            if(cont >= 7 && M[aux].p != NULL){
                mP2[k].p = M[aux].p;
                M[aux].p = NULL;
                k++;
                cont++;
            }
        }
    }
}
