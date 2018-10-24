#include "Dados.h"
#include "Tela.h"

void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){

    inicializarMao(mP1, mP2);
    inicializarMesa(M);
//    inicializarTabuleiro();
    imprimirTabuleiro(M);

    darMaos(mP1, mP2, M);

    organizarSoma(mP1, 1, 1);
    organizarSoma(mP2, 1, 1);

    if()
    colocarPeca(T, pecaIni);

    if(Modo == 1){
        JogarPc(T, M, mP1, mP2);
    }else{
//        JogarPL(T, M, mP1, mP2);
    }
}

void JogarPc(Tabuleiro T, Tabuleiro M, Tabuleiro mP1, Tabuleiro mP2){
    int cmd;
    do{
        cmd = Menu();

    }while(cmd != 0);
}
