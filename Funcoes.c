#include "Dados.h"
#include "Tela.h"
#include "Funcoes.h"

void organizarPeca(Tabuleiro mp[],int crescente ,int esquerda);

void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){
    inicializarMao(mP1, mP2);
    inicializarMesa(M);
    imprimirTabuleiro(M);

    darMaos(mP1, mP2, M);
    organizarPeca(mP2,1,1);
    imprimirMao(mP2);

    if(Modo == 1){

    }
}


void organizarPeca(Tabuleiro mp[],int crescente ,int esquerda){
    int j , k;
    Tabuleiro peca;
    if(crescente == 1){
        if(esquerda == 1){
            for(j = 0;j<=28;j++){
                peca.p->e = mp[j].p->e;
                k=j-1;
                while(peca.p->e < mp[k].p->e){
                    mp[k+1]=mp[k];
                    k=k-1;
                }
                mp[k-1].p->e = peca.p->e;
            }
        }
    }
}
