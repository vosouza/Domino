#include <stdio.h>
#include "Dados.h"
#include  "Tela.h"


void imprimirTabuleiro(Tabuleiro M[])
{
    for(int i = 0; i < 28; i++)
    {
        printf("%d | %d", M[i].p->e, M[i].p->d);
        printf("\n");
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
