#include "Dados.h"
#include "Tela.h"
#include "Funcoes.h"
#include "stdio.h"
void organizarPeca(Tabuleiro mp[],int crescente ,int esquerda);
int agruparPecas(Tabuleiro pecas[]);

void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){

    inicializarMao(mP1, mP2);
    inicializarMesa(M);
//    inicializarTabuleiro();
//    imprimirTabuleiro(M);

    darMaos(mP1, mP2, M);
    imprimirMao(mP2);

    printf("\n\nxxxxxxx");

    organizarPeca(mP2,1,1);
    imprimirMao(mP2);

    //organizarSoma(mP1, 1, 1);
    //organizarSoma(mP2, 1, 1);

}

void organizarPeca(Tabuleiro mp[],int crescente ,int esquerda){
    int j,k,fim;
    Tabuleiro peca;
    peca.p = NULL;
    fim = agruparPecas(mp);
    if(crescente == 1){
        if(esquerda == 1){
           for(j=0;j<fim;j++){
                for(k=0;k<fim;k++){
                    if(mp[k].p->e > mp[k+1].p->e){
                        peca.p = mp[k].p;
                        mp[k].p = mp[k+1].p;
                        mp[k+1].p = peca.p;
                    }
                }
           }
        }
    }

}

int agruparPecas(Tabuleiro pecas[]){
    int x,i = 0;
    Tabuleiro aux[28];
    for(x=0;x<=28;x++){
        if(pecas[x].p != NULL){
           aux[i].p = pecas[x].p;
           i++;
        }
    }
    for(x=0;x<=i;x++){
        pecas[x].p = aux[x].p;
    }
    return i;
}
