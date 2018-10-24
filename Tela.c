#include <stdio.h>
#include "Dados.h"
#include  "Tela.h"



void imprimirTabuleiro(Tabuleiro M[]){
    for(int i = 0; i < 28; i++){
        if(M[i].p != NULL){
            printf("%d | %d", M[i].p->e, M[i].p->d);
            printf("\n");
        }
    }
}

void imprimirMao(Tabuleiro mP[]){
    for(int i = 0; i < 7; i++){
        if(mP[i].p != NULL){
            printf("%d | %d", mP[i].p->e, mP[i].p->d);
            printf("\n");
        }

    }
}

int numJogadores()
{
int numeroJogadores;
    printf("para jogar com a maquina digite 1 \n\npara jogar com outro jogador digite 2");
    scanf("%d",&numeroJogadores);
    while (numeroJogadores<0 && numeroJogadores>2)
    {
        printf("numero de jogadores invalido\n\nDigite Novamente");
        scanf("%d",&numeroJogadores);
    }
    return numeroJogadores;
}

int JogarPLTela(){
    int opcaoEscolhida;
    printf("Certo, vamos as opções.\n");

    printf("para escolher um peça, digite 1\n");
    printf("para salvar o jogo , digite 2\n");
    printf("para sair do jogo , digite 3\n");
    return opcaoEscolhida

}
