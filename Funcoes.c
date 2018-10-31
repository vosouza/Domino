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
    Func�o para organizar as pe�as em ordem crescente ou decrescente
    considerando o lado esquedo ou direito das pe�as

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
/*
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

>>>>>>> a5b363ee2b208b4461fda894d37fcb6db6e8ac6a
}
*/















