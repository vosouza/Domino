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

    x = numPecas(mP1);
    printf("\n\n%d\n\n",x);
    imprimirTabuleiro(mP1);
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
            printf("(%d..%d)",mp[num].p->e,mp[num].p->d);
        }

    }
    return pcs;
}

void agruparPecas(){
}
