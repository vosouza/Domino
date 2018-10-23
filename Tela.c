#include <stdio.h>
#include "Dados.h"
#include  "Tela.h"


void imprimirTabuleiro(Tabuleiro M[]){
    for(int i = 0; i < 28; i++){
        printf("%d | %d", M[i].p->e, M[i].p->d);
        printf("\n");
    }
}
