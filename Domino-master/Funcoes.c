#include "Dados.h"
#include "Tela.h"
#include "Funcoes.h"
#include<stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo, int Load){
    if(Load == 0){
        inicializarMao(mP1, mP2);
        inicializarMesa(M);
        inicializarTabuleiro(T);
        //inicializarTabuleiro();
        darMaos(mP1, mP2, M);
        corrigirOrdem(M);
    }else{
        inicializarMao(mP1, mP2);
        inicializarMesa(M);
        inicializarTabuleiro(T);
        Modo = loadGame( T,  M,  mP1,  mP2);
    }

    /*organizarSoma(mP1, 1, 1); // 1 - Crescente / 1 - Num esquerdo
    organizarSoma(mP2, 1, 1);*/

    //colocarPeca(T, pecaIni);

    if(Modo == 1){
        if(Load == 0)
            inserirPimeiraPeca(T, mP1);
        JogarPc(T, M, mP1, mP2, Modo);
    }else{
        if(Load == 0)
            inserirPimeiraPeca(T, mP1);
        JogarPL(T, M, mP1, mP2, Modo);
    }
}

void JogarPL(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){
    int cmd = -1, turno = 0;
    int ordem = 0, direcao = 0;
    bool insPeca = false;
    int pos[2];
    do{
        turno++;
        if(turno%2 == 0){
            //system("cls");
            imprimirTurno(turno);
            cmd = -1;
            cmd = Menu(T, mP1);
            switch(cmd){
                case(1):
                    insPeca = checarMao(T, mP1);
                    if(insPeca == true){
                        escolhaPecaTela(T, mP1, pos);
                        inserirPeca(T, mP1, pos[0], pos[1]);
                    }else{
                        semPecaTela();
                        semPeca(mP1, M);
                    }
                break;
                case(2):
                    organizarPecaTela(&ordem, &direcao);
                    organizarPeca(mP1, ordem - 1, direcao - 1);
                    turno--;
                break;
                case(3):
                    salvarJogoTela(T, M, mP1, mP2, turno, Modo);
                    turno--;
                break;
            }
        }else{
            //system("cls");
            imprimirTurno(turno);
            cmd = Menu(T, mP2);
            switch(cmd){
                case(1):
                    insPeca = checarMao(T, mP2);
                    if(insPeca == true){
                        escolhaPecaTela(T, mP2, pos);
                        inserirPeca(T, mP2, pos[0], pos[1]);
                    }else{
                        semPecaTela();
                        semPeca(mP2, M);
                    }
                break;
                case(2):
                    organizarPecaTela(&ordem, &direcao);
                    organizarPeca(mP2, ordem - 1, direcao - 1);
                    turno--;
                break;
                case(3):
                    salvarJogoTela(T, M, mP1, mP2, turno, Modo);
                    turno--;
                break;
            }
        }
    }while(cmd != 4);
}

void JogarPc(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){
    int cmd, turno = 0;
    int ordem = 0, direcao = 0;
    bool insPeca = false;
    int pos[2];
    do{
        cmd = -1;
        turno++;
        if(turno%2 == 0){
            //system("cls");
            cmd = Menu(T, mP1);
            switch(cmd){
                case(1):
                    insPeca = checarMao(T, mP1);
                    if(insPeca == true){
                        escolhaPecaTela(T, mP1, pos);
                        inserirPeca(T, mP1, pos[0], pos[1]);
                    }else{
                        semPecaTela();
                        semPeca(mP1, M);
                    }
                break;
                case(2):
                    organizarPecaTela(&ordem, &direcao);
                    organizarPeca(mP1, ordem - 1, direcao - 1);
                    turno--;
                break;
                case(3):
                    salvarJogoTela(T, M, mP1, mP2, turno, Modo);
                    turno--;
                break;
            }
        }else{
            //system("cls");
            turnoPCTela();
            insPeca = turnoPC(T, mP2);
            if(insPeca == false){
                semPecaPCTela();
                semPeca(mP2, M);
            }
        }
    }while(cmd != 4);
}



void corrigirOrdem(Tabuleiro X[]){
    int i = 0, j = 0;
    while(i < 28){
        if(X[i].p == NULL){
            j = i + 1;
            while(j < 28 && X[j].p == NULL){
                j++;
            }
            if(j != 28){
                X[i].p = X[j].p;
                X[j].p = NULL;
            }
        }
        i++;
    }
}

void inserirPeca(Tabuleiro T[], Tabuleiro mP[], int posP, int posT){
    if(posT == 1 && (mP[posP].p->d == T[0].p->e || mP[posP].p->e == T[0].p->e)){
        if(mP[posP].p->d != T[0].p->e || mP[posP].p->e == T[0].p->e)
            invertePeca(mP, posP);

        moverTabuleiro(T);
        T[0].p = mP[posP].p;
        mP[posP].p = NULL;
        corrigirOrdem(mP);
    }else{
        if(mP[posP].p->e != T[0].p->d || mP[posP].p->d == T[0].p->d)
            invertePeca(mP, posP);

        T[tamTotal(T)].p = mP[posP].p;
        mP[posP].p = NULL;
        corrigirOrdem(mP);
    }
}

bool checarMao(Tabuleiro T[], Tabuleiro mP[]){
    int tam = tamTotal(T);

    if(tam == 1){
        for(int i = 0; i < 28; i++){
            if(mP[i].p != NULL && ((mP[i].p->e == T[0].p->d) || (mP[i].p->d == T[0].p->e)))
                return true;
        }
    }else{
        if(tam > 1){
            for(int i = 0; i < 28; i++){
                if(mP[i].p != NULL){
                    if(mP[i].p->d == T[0].p->e)
                        return true;
                    else{
                        if(mP[i].p->e == T[tam - 1].p->d)
                            return true;
                    }
                }
            }
        }
    }

    return false;
}


void inserirPimeiraPeca(Tabuleiro T[], Tabuleiro mP1[]){
    for(int i = 0; i < 28; i++){
        if(mP1[i].p != NULL && mP1[i].p->d == mP1[i].p->e/*nAux < mP1[i].p->s*/){
            T[0].p = mP1[i].p;
            mP1[i].p = NULL;
            corrigirOrdem(mP1);
            return;
        }
    }

    Domino *aux;
    int nAux = -1, pos = -1;
    for(int i = 0; i < 28; i++){
        if(mP1[i].p != NULL && nAux < mP1[i].p->s){
            pos = i;
            nAux = mP1[i].p->s;
            aux = mP1[i].p;
        }
    }

    T[0].p = aux;
    mP1[pos].p = NULL;
    corrigirOrdem(mP1);
}

bool posValida(Tabuleiro T[], Tabuleiro mP[], int posP, int posT){
    if((posT == 1) && (tamTotal(T) == 1) && (((mP[posP].p->e == T[0].p->d) || (mP[posP].p->d == T[0].p->d)) || ((mP[posP].p->d == T[0].p->e) || (mP[posP].p->e == T[0].p->e)))){
        return true;
    }else{
        if(posT == 1 && tamTotal(T) > 1 && (mP[posP].p->d == T[0].p->e || mP[posP].p->e == T[0].p->e))
            return true;
        else{
            if(mP[posP].p->e == T[tamTotal(T) - 1].p->d || mP[posP].p->d == T[tamTotal(T) - 1].p->d)
                return true;
        }
    }

    return false;
}

void moverTabuleiro(Tabuleiro T[]){
    if(tamTotal(T) < 28){
        for(int i = tamTotal(T); 0 < i; i--){
            T[i].p = T[i - 1].p;
        }
        T[0].p = NULL;
    }
}

void semPeca(Tabuleiro mP[], Tabuleiro M[]){
    if(tamTotal(M) > 0){
        mP[tamTotal(mP)].p = M[tamTotal(M) - 1].p;
        M[tamTotal(M) - 1].p = NULL;
    }
}

bool turnoPC(Tabuleiro T[], Tabuleiro mP[]){
    bool posV = false;
    int i = 1, j;
    while(i < 3 && posV == false){
        j = 0;
        while(j < tamTotal(mP) && posV == false){
            posV = posValida(T, mP, j, i);
            j++;
        }
        i++;
    }
    if(posV == false){
        return false;
    }else{
        inserirPeca(T, mP, j - 1, i - 1);
        return true;
    }
}

// Ordem: 1 - Crescente // 0 - Decrescente
void organizarPeca(Tabuleiro mP[],int ordem ,int direcao){
    int j, k, fim;
    Tabuleiro peca;
    peca.p = NULL;
    fim = tamTotal(mP);
    if(ordem == 1){
        if(direcao == 1){
           for(j = 0; j < fim - 1; j++){
                for(k = 0; k < fim - 1; k++){
                    if(mP[k].p->e > mP[k+1].p->e){
                        peca.p = mP[k].p;
                        mP[k].p = mP[k+1].p;
                        mP[k+1].p = peca.p;
                    }
                }
           }
        }else if(direcao == 0){
            for(j = 0; j < fim - 1; j++){
                for(k = 0; k < fim - 1; k++){
                    if(mP[k].p->d > mP[k+1].p->d){
                        peca.p = mP[k].p;
                        mP[k].p = mP[k+1].p;
                        mP[k+1].p = peca.p;
                    }
                }
           }
        }
    }else if (ordem == 0){
        if(direcao == 1){
           for(j = 0; j < fim - 1; j++){
                for(k = 0; k < fim - 1; k++){
                    if(mP[k].p->e < mP[k+1].p->e){
                        peca.p = mP[k].p;
                        mP[k].p = mP[k+1].p;
                        mP[k+1].p = peca.p;
                    }
                }
           }
        }else if(direcao == 0){
            for(j = 0; j < fim - 1; j++){
                for(k = 0; k < fim - 1; k++){
                    if(mP[k].p->d < mP[k+1].p->d){
                        peca.p = mP[k].p;
                        mP[k].p = mP[k+1].p;
                        mP[k+1].p = peca.p;
                    }
                }
           }
        }
    }

}

void invertePeca(Tabuleiro mP[], int pos){
    int aux = mP[pos].p->e;
    mP[pos].p->e = mP[pos].p->d;
    mP[pos].p->d = aux;
}

void salvarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo, int turno, char nomeArq[]){
    FILE *arq;
    strcat(nomeArq, ".txt");
    arq = fopen(nomeArq, "w+");

    fprintf(arq, "%d", Modo); // Primeiro salvamos em que modo estamos
    fprintf(arq, "\n");
    fprintf(arq, "----------");
    fprintf(arq, "\n");

    fprintf(arq, "%d", turno); // Depois salvamos em que turno estamos
    fprintf(arq, "\n");
    fprintf(arq, "----------");
    fprintf(arq, "\n");

    for(int i = 0; i < tamTotal(T); i++){ // Depois salvamos as pecas do tabuleiro
         fprintf(arq, "%d %d", T[i].p->e, T[i].p->d);
         fprintf(arq, "\n");
    }

    fprintf(arq, "404 404");
    fprintf(arq, "\n");

    for(int i = 0; i < tamTotal(M); i++){ // Depois salvamos as pecas da mesa
         fprintf(arq, "%d %d", M[i].p->e, M[i].p->d);
         fprintf(arq, "\n");
    }

    fprintf(arq, "404 404");
    fprintf(arq, "\n");

    for(int i = 0; i < tamTotal(mP1); i++){ // Depois salvamos as pecas do jogador 1
         fprintf(arq, "%d %d", mP1[i].p->e, mP1[i].p->d);
         fprintf(arq, "\n");
    }

    fprintf(arq, "404 404");
    fprintf(arq, "\n");

    for(int i = 0; i < tamTotal(mP2); i++){ // Depois salvamos as pecas do jogador 2
         fprintf(arq, "%d %d", mP2[i].p->e, mP2[i].p->d);
         fprintf(arq, "\n");
    }

    fclose(arq);
}

int loadGame(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[]){
    char *nomeArq = malloc(sizeof(char)*100);
    char *aux = malloc(sizeof(char)*100);
    Tabuleiro peca;
    FILE *arq;
    int modo = 0, esquerda=0, direita=0,turno=0, contador=0;

    printf("Digite o nome do ultimo Save File para ser carregado: ");
    scanf("%s",nomeArq);

    arq = fopen(nomeArq,"rb");

    if(arq == NULL){
        printf("Esse arquivo nao existe, tente novamente!");
    }

    fscanf(arq,"%d",&modo);
    fscanf(arq,"%s", aux);
    fscanf(arq,"%d",&turno);
    fscanf(arq,"%s", aux);
    while(esquerda != 404 && direita != 404){
            fscanf(arq,"%d %d",esquerda,direita);
            peca.p->d = direita;
            peca.p->e = esquerda;
            T[contador].p->d = peca.p->d;
            T[contador].p->e = peca.p->e;
            contador++;
    }
    return 0;
}



