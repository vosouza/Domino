#include "Dados.h"
#include "Tela.h"
#include "Funcoes.h"
#include<stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
** Inicializa o jogo
**
** Parâmetros:
**      Tabuleiro T[] - Vetor de pecas de domino. O tabuleiro do jogo
**      Tabuleiro M[] - Vetor de pecas de domino. A mesa que contem todas as pecas a serem compradas
**      Tabuleiro mP1[] - Vetor de pecas de domino. A mao do player 1
**      Tabuleiro mP2[] - Vetor de pecas de domino. A mao do player 2
**      int Modo - Inteiro que indicara o modo de jogo (1  = SinglePlayer ou 2 = MultiPlayer)
**      int Lode - Indica se esta carregando um jogo antigo ou nao
**
** Retorno:
**      nenhum
*/

void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo, int Load){
    if(Load == 0){
        inicializarMao(mP1, mP2);
        inicializarMesa(M);
        inicializarTabuleiro(T);
        darMaos(mP1, mP2, M);
        corrigirOrdem(M);
    }else{
        inicializarMao(mP1, mP2);
        inicializarMesa(M);
        inicializarTabuleiro(T);
        Modo = loadGame( T, M, mP1, mP2);
    }

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

/*
** Menu para o modo MultiPlayer
**
** Parâmetros:
**      Tabuleiro T[] - Vetor de pecas de domino. O tabuleiro do jogo
**      Tabuleiro M[] - Vetor de pecas de domino. A mesa que contem todas as pecas a serem compradas
**      Tabuleiro mP1[] - Vetor de pecas de domino. A mao do player 1
**      Tabuleiro mP2[] - Vetor de pecas de domino. A mao do player 2
**      int Modo - Inteiro que indicara o modo de jogo (1  = SinglePlayer ou 2 = MultiPlayer)
**
** Retorno:
**      nenhum
*/

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
            cmd = -1;
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

/*
** Menu para o modo SinglePlayer
**
** Parâmetros:
**      Tabuleiro T[] - Vetor de pecas de domino. O tabuleiro do jogo
**      Tabuleiro M[] - Vetor de pecas de domino. A mesa que contem todas as pecas a serem compradas
**      Tabuleiro mP1[] - Vetor de pecas de domino. A mao do player 1
**      Tabuleiro mP2[] - Vetor de pecas de domino. A mao do player 2
**      int Modo - Inteiro que indicara o modo de jogo (1  = SinglePlayer ou 2 = MultiPlayer)
**
** Retorno:
**      nenhum
*/

void JogarPc(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo){
    int cmd, turno = 0;
    int ordem = 0, direcao = 0;
    bool insPeca = false;
    int pos[2];
    do{
        turno++;
        if(turno%2 == 0){
            //system("cls");
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
                    mostrarMaoOT(mP2);
                break;
                case(4):
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

/*
** Corrige os vetores agrupando os ponteiros, eliminando os NULL entre si
**
** Parâmetros:
**      Tabuleiro X[] - Um vetor de ponteiros do tipo Domino
**
** Retorno:
**      nenhum
*/

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

/*
** Insere uma paca da mao do jogador no tabuleiro
**
** Parâmetros:
**      Tabuleiro T[] - Vetor de pecas de domino. O tabuleiro do jogo
**      Tabuleiro mP[] - Vetor de pecas de domino. A mao do player
**      int posP - Inteiro que indica a posicao pa peca na mao do jogador
**      int posT - Inteiro que indica a posicao em que a peca sera inserida (1 = Inicio do Tabuleiro ou 2 = Fim do Tabuleiro)
**
** Retorno:
**      nenhum
*/

void inserirPeca(Tabuleiro T[], Tabuleiro mP[], int posP, int posT){
    if(posT == 1 && (mP[posP].p->d == T[0].p->e || mP[posP].p->e == T[0].p->e)){
        if(mP[posP].p->d != T[0].p->e || mP[posP].p->e == T[0].p->e)
            invertePeca(mP, posP);

        moverTabuleiro(T);
        T[0].p = mP[posP].p;
        mP[posP].p = NULL;
        corrigirOrdem(mP);
    }else{
        if(posT == 2 && (mP[posP].p->e != T[tamTotal(T) - 1].p->d || mP[posP].p->d == T[tamTotal(T) - 1].p->d))
            invertePeca(mP, posP);

        T[tamTotal(T)].p = mP[posP].p;
        mP[posP].p = NULL;
        corrigirOrdem(mP);
    }
}

/*
** Checa se existe uma peca valida na mao do jogador a ser inserida no tabuleiro
**
** Parâmetros:
**      Tabuleiro T[] - Vetor de pecas de domino. O tabuleiro do jogo
**      Tabuleiro mP[] - Vetor de pecas de domino. A mao do player
**
** Retorno:
**      True se existe peca ou false se nao existir
*/

bool checarMao(Tabuleiro T[], Tabuleiro mP[]){
    int tam = tamTotal(T);

    if(tam == 1){
        for(int i = 0; i < 28; i++){
            if(mP[i].p != NULL && (((mP[i].p->e == T[0].p->d) || (mP[i].p->d == T[0].p->e)) || ((mP[i].p->d == T[0].p->d) || (mP[i].p->e == T[0].p->e))))
                return true;
        }
    }else{
        if(tam > 1){
            for(int i = 0; i < 28; i++){
                if(mP[i].p != NULL){
                    if(mP[i].p->d == T[0].p->e || mP[i].p->e == T[0].p->e)
                        return true;
                    else{
                        if(mP[i].p->e == T[tam - 1].p->d || mP[i].p->d == T[tam - 1].p->d)
                            return true;
                    }
                }
            }
        }
    }

    return false;
}

/*
** Insere a maior peca com o mesmo numero do jogador 1 ou a maior peca
**
** Parâmetros:
**      Tabuleiro T[] - Vetor de pecas de domino. O tabuleiro do jogo
**      Tabuleiro mP[] - Vetor de pecas de domino. A mao do player
**
** Retorno:
**      nenhum
*/

void inserirPimeiraPeca(Tabuleiro T[], Tabuleiro mP1[]){
    int nAux = -1, pos = -1;
    for(int i = 0; i < 28; i++){
        if(mP1[i].p != NULL && mP1[i].p->d == mP1[i].p->e && mP1[i].p->d > nAux){
                nAux = mP1[i].p->d;
                pos = i;
        }
    }

    if(pos != -1){
        T[0].p = mP1[pos].p;
        mP1[pos].p = NULL;
        corrigirOrdem(mP1);
        return;
    }

    Domino *aux;
    nAux = -1;
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
            if(posT == 2 && (mP[posP].p->e == T[tamTotal(T) - 1].p->d || mP[posP].p->d == T[tamTotal(T) - 1].p->d))
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

    fprintf(arq, "%d", turno); // Depois salvamos em que turno estamos
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
    fprintf(arq, "404 404");
    fclose(arq);
}
int loadGame(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[]){
    FILE *arq;
    char *nomeArq = malloc(sizeof(char)*100);
    int modo=0, turno=0, esquerda=0, direita=0;

    printf("\nDigite o nome do Save File:");
    scanf("%s",nomeArq);

    arq = fopen(nomeArq, "r");

    fscanf(arq,"%d",&modo);
    fscanf(arq,"%d",&turno);

    //Pegar o Tabuleiro
    fscanf(arq,"%d %d",&esquerda, &direita);
    for(int i=0;esquerda!=404 && direita!=404;i++){
        T[i].p = malloc(sizeof(Tabuleiro));
        T[i].p->e = esquerda;
        T[i].p->d = direita;
        T[i].p->s = esquerda + direita;
        fscanf(arq,"%d %d",&esquerda, &direita);
    }

    fscanf(arq,"%d %d",&esquerda, &direita);
    for(int i=0;esquerda!=404 && direita!=404;i++){
        M[i].p = malloc(sizeof(Tabuleiro));
        M[i].p->e = esquerda;
        M[i].p->d = direita;
        M[i].p->s = esquerda + direita;
        fscanf(arq,"%d %d",&esquerda, &direita);
    }

    fscanf(arq,"%d %d",&esquerda, &direita);
    for(int i=0;esquerda!=404 && direita!=404;i++){
        mP1[i].p = malloc(sizeof(Tabuleiro));
        mP1[i].p->e = esquerda;
        mP1[i].p->d = direita;
        mP1[i].p->s = esquerda + direita;
        fscanf(arq,"%d %d",&esquerda, &direita);
    }

    fscanf(arq,"%d %d",&esquerda, &direita);
    for(int i=0;esquerda!=404 && direita!=404;i++){
        mP2[i].p = malloc(sizeof(Tabuleiro));
        mP2[i].p->e = esquerda;
        mP2[i].p->d = direita;
        mP2[i].p->s = esquerda + direita;
        fscanf(arq,"%d %d",&esquerda, &direita);
    }
    fclose(arq);

    return modo;
}
