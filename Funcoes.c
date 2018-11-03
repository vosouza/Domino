#include "Dados.h"
#include "Tela.h"
#include "stdio.h"
int numPecas(Tabuleiro mp[]);
void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){

    int x;

    inicializarMao(mP1, mP2);
    inicializarMesa(M);
//    inicializarTabuleiro();
    imprimirTabuleiro(M);

    darMaos(mP1, mP2, M);
    M[10].p = NULL;
    M[11].p = NULL;
    M[20].p = NULL;
    M[21].p = NULL;
    printf("\n");
    agruparPecas(M);
    imprimirTabuleiro(M);

   // organizarSoma(mP1, 1, 1);
    //organizarSoma(mP2, 1, 1);

   /* if()
    colocarPeca(T, pecaIni);

    if(Modo == 1){
        JogarPc(T, M, mP1, mP2);
    }else{
//        JogarPL(T, M, mP1, mP2);
    }*/
}

void JogarPc(Tabuleiro T, Tabuleiro M, Tabuleiro mP1, Tabuleiro mP2){
    int cmd;
    do{
        cmd = Menu();

    }while(cmd != 0);
}

void organizarMao(Tabuleiro mp[],int crescente, int esquerda){
    int num = 28;
    if(crescente){
        if(esquerda){

        }
    }

}

int numPecas(Tabuleiro mp[]){
    int num, pcs=0;
    for(num=0;num<28;num++){
        if(mp[num].p != NULL){
            pcs++;
        }

    }
    return pcs;
}

void agruparPecas(Tabuleiro mp[]){
    int num=0, vazio=0;
    Tabuleiro aux;
    for(num=0;num<28;num++){
        if(mp[num].p == NULL){
            mp[num].p = mp[num+1].p;
            mp[num+1].p = NULL;
        }

    }

}
