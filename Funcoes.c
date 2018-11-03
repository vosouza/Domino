#include "Dados.h"
#include "Tela.h"
#include "Funcoes.h"
#include "stdio.h"
void organizarPeca(Tabuleiro mp[],int crescente ,int esquerda);
int agruparPecas(Tabuleiro pecas[]);
void organizarSoma(Tabuleiro mp[]);

void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){

    inicializarMao(mP1, mP2);
    inicializarMesa(M);
//    inicializarTabuleiro();
//    imprimirTabuleiro(M);

    darMaos(mP1, mP2, M);
    imprimirMao(mP1);

    printf("\n\n");
    organizarPeca(mP1,1,1);
    organizarSoma(mP1);
    imprimirMao(mP1);

}
/*
    Funcão para organizar as peças em ordem crescente ou decrescente
    considerando o lado esquedo ou direito das peças

    entrada: Tabuleiro mp, crescente(inteiro), esquerda(inteiro)
    saida: Tabuleiro mp

*/
void organizarPeca(Tabuleiro mp[],int crescente ,int esquerda){
    int j,k,fim;
    Tabuleiro peca;
    peca.p = NULL;
    fim = agruparPecas(mp);
    if(crescente == 1){
        if(esquerda == 1){
           for(j=0;j<fim-1;j++){
                for(k=0;k<fim-1;k++){
                    if(mp[k].p->e > mp[k+1].p->e){
                        peca.p = mp[k].p;
                        mp[k].p = mp[k+1].p;
                        mp[k+1].p = peca.p;
                    }
                }
           }
        }else if(esquerda == 0){
            for(j=0;j<fim-1;j++){
                for(k=0;k<fim-1;k++){
                    if(mp[k].p->d > mp[k+1].p->d){
                        peca.p = mp[k].p;
                        mp[k].p = mp[k+1].p;
                        mp[k+1].p = peca.p;
                    }
                }
           }
        }
    }else if (crescente == 0){
        if(esquerda == 1){
           for(j=0;j<fim-1;j++){
                for(k=0;k<fim-1;k++){
                    if(mp[k].p->e < mp[k+1].p->e){
                        peca.p = mp[k].p;
                        mp[k].p = mp[k+1].p;
                        mp[k+1].p = peca.p;
                    }
                }
           }
        }else if(esquerda == 0){
            for(j=0;j<fim-1;j++){
                for(k=0;k<fim-1;k++){
                    if(mp[k].p->d < mp[k+1].p->d){
                        peca.p = mp[k].p;
                        mp[k].p = mp[k+1].p;
                        mp[k+1].p = peca.p;
                    }
                }
           }
        }
    }

}
/*
    Funcão para agrupar os dados do vetor retirando as variaveis nulas
    que estão entre as variaveis nao nulas
    A funcao tambem devolve o numero de pecas que o vetor contem

    entrada: Tabuleiro pecas
    saida: int i

*/
int agruparPecas(Tabuleiro pecas[]){
    int x,i = 0;
    Tabuleiro aux[28];
    for(x=0;x<28;x++){
        if(pecas[x].p != NULL){
           aux[i].p = pecas[x].p;
           i++;
        }
    }
    for(x=0;x<=i-1;x++){
        pecas[x].p = aux[x].p;
    }
    return i;
}

/*
    Funcão para organizar as peças em ordem crescente considerando a somas dos dois lados
    da peça de domino

    entrada: Tabuleiro mp
    saida: Tabuleiro mp

*/
void organizarSoma(Tabuleiro mp[]){
    int j,k,fim;
    Tabuleiro peca;
    peca.p = NULL;
    fim = agruparPecas(mp);
    for(j=0;j<fim-1;j++){
        for(k=0;k<fim-1;k++){
            if(mp[k].p->s < mp[k+1].p->s){
                peca.p = mp[k].p;
                mp[k].p = mp[k+1].p;
                mp[k+1].p = peca.p;

            }
        }
    }
}

