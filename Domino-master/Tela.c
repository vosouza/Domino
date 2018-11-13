#include <stdio.h>
#include "Dados.h"
#include "Tela.h"
#include "Funcoes.h"
#include<stdbool.h>

void imprimirTabuleiro(Tabuleiro M[]){
    for(int i = 0; i < 28; i++){
        if(i > 0 && M[i].p != NULL)
            printf(" - ");

        if(M[i].p != NULL){
            printf("[%d | %d]", M[i].p->e, M[i].p->d);
        }
    }
    printf("\n");
}

void imprimirMao(Tabuleiro mP[]){
    for(int i = 0; i < 28; i++){
        if(mP[i].p != NULL){
            printf("%d ) [%d | %d]", (i + 1), mP[i].p->e, mP[i].p->d);
            printf("\n");
        }
    }
}

int Menu(Tabuleiro T[28], Tabuleiro mP[28]){
    int cmd;
    printf("Tabuleiro:\n");
    imprimirTabuleiro(T);

    printf("Mao Jogador:\n");

    imprimirMao(mP);

    while(cmd > 4 || cmd < 1){
        printf("\nDigite:\n\t1 - Para jogar\n\t2 - Para organizar pecas\n\t3 - Para salvar\n\t4 - Para sair\n");
        fflush(stdin);
        scanf("%d", &cmd);
        fflush(stdin);
    }

    return cmd;
}

void escolhaPecaTela(Tabuleiro T[], Tabuleiro mP[], int pos[]){
    bool posV = false;
    while(posV != true){
        printf("Escolha no inicio ou no fim do tabuleiro para inserir a peca (Se hover apenas uma peca escolha o inicio):\n\t 1 - Inicio\n\t 2 - Fim\n");
        fflush(stdin);
        scanf("%d", &pos[1]);
        fflush(stdin);
        printf("Escolha qual peca deseja inserir:\n");
        fflush(stdin);
        scanf("%d", &pos[0]);
        fflush(stdin);
        pos[0] = pos[0] - 1;

        posV = posValida(T, mP, pos[0], pos[1]);

        if(posV == false)
            printf("Escolha uma possicao valida\n");
    }
}

void semPecaTela(){
    printf("Voce nao possui peca para jogar, compre uma peca!\n");
}

void turnoPCTela(){
    printf("Turno do computador!\n");
}

void semPecaPCTela(){
    printf("O computador nao posuia nenhuma peca para por, portanto ele comprou uma!\n");
}

void imprimirTurno(int turno){
    if(turno % 2 == 0)
        printf("\tTurno Player 1\n");
    else
        printf("\tTurno Player 2\n");
}

int modoJogo(){
    int modo = 0;
    while(modo > 3 || modo < 1){
        printf("\t1 - Single Player\n\t2 - Multiplayer\n\t3 - Load Save\n");
        scanf("%d", &modo);
        if(modo > 3 || modo < 1){
            printf("\tEscolha um modo existente!\n");
        }
    }

    return modo;
}

void organizarPecaTela(int *ordem, int *direcao){
    while(*ordem > 2 || *ordem < 1){
        printf("\n\tOrdena de forma:\n\t1 - Decrescente\n\t2 - Crescente\n");
        scanf("%d", ordem);
        if(*ordem > 2 || *ordem < 1){
            printf("\tEscolha uma ordem existente!\n");
        }
    }

    while(*direcao > 2 || *direcao < 1){
        printf("\n\tOrdena de:\n\t1 - Numero da direita\n\t2 - Numero da esquerda\n");
        scanf("%d", direcao);
        if(*direcao > 2 || *direcao < 1){
            printf("\tEscolha uma direcao existente!\n");
        }
    }
}

void salvarJogoTela(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo, int turno){
    char nomeArq[20];
    printf("\n\tDigite o nome do save file:\n");
    scanf("%s", nomeArq);

    salvarJogo(T, M, mP1, mP2, Modo, turno, nomeArq);
}
