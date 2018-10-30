#include "Dados.h"
#include "Tela.h"

void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){

    inicializarMao(mP1, mP2);
    inicializarMesa(M);
//    inicializarTabuleiro();
    imprimirTabuleiro(M);

    darMaos(mP1, mP2, M);

    organizarSoma(mP1, 1, 1); // 1 - Crescente / 1 - Num esquerdo
    organizarSoma(mP2, 1, 1);

    if()
    colocarPeca(T, pecaIni);

    if(Modo == 1){
        inserirPimeiraPeca(T, mP1, mP2);
        JogarPc(T, M, mP1, mP2);
    }else{
//        JogarPL(T, M, mP1, mP2);
    }
}

void JogarPc(Tabuleiro T, Tabuleiro M, Tabuleiro mP1, Tabuleiro mP2){
    int cmd, turno = 1;
    do{
        turno++;
        cmd = Menu();
        if(cmd == 1){
            inserirPeca(T, M, mP1, mP2, turno);
        }
    }while(cmd != 3);
}

void inserirPeca(Tabuleiro T, Tabuleiro M, Tabuleiro mP1, Tabuleiro mP2, int turno){
    bool comprar;
    if(turno%2 != 0){
        comprar = checarMao(T, mP1);
    }
}

bool checarMao(T, mP1){
    Domino *aux1, *aux2;
    int pos;
    aux1 = T[1].p;
    while(T[i].p != NULL)
}


void inserirPimeiraPeca(T, mP1){

}















