#include "Dados.h"
#include "Tela.h"

void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){
    inicializarMao(mP1, mP2);
    inicializarMesa(M);
    imprimirTabuleiro(M);

    darMaos(mP1, mP2, M);

    if(Modo == 1){

    }
}
