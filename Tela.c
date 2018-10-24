#include <stdio.h>
#include "Dados.h"
#include  "Tela.h"

void imprimirTabuleiro(Tabuleiro M[]){
    for(int i = 0; i < 28; i++){
        if(M[i].p != NULL){
            printf("%d | %d", M[i].p->e, M[i].p->d, M[i].p->s);
            printf("\n");
        }
    }
}

void imprimirMao(Tabuleiro mP[]){
    for(int i = 0; i < 7; i++){
        if(mP[i].p != NULL){
            printf("%d ) %d | %d, soma %d", (i + 1), mP[i].p->e, mP[i].p->d, mP[i].p->s);
            printf("\n");
        }
    }
}

int Menu(Tabuleiro T[28], Tabuleiro mP[28]){
    printf("Tabuleiro:")
    imprimirTabuleiro(T);

    printf("Mao Jogador:\n");

    imprimirMao(mP);


}
