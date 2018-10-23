#include <stdio.h>
#include "Dados.h"
#include  "Tela.h"


void imprimirTabuleiro(Tabuleiro M[]){
    for(int i = 0; i < 28; i++){
        if(M[i].p != NULL){
            printf("%d | %d", M[i].p->e, M[i].p->d);
            printf("\n");
        }
    }
}

void imprimirMao(Tabuleiro mP[]){
    for(int i = 0; i < 7; i++){
        if(mP[i].p != NULL){
            printf("%d | %d", mP[i].p->e, mP[i].p->d);
            printf("\n");
        }
    }
}
