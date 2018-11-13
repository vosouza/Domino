#include <stdio.h>
#include <stdlib.h>
#include "Dados.h"
#include "Tela.h"
#include "Funcoes.h"

int main()
{
    Tabuleiro T[28];
    Tabuleiro mP1[28], mP2[28], M[28];
    int modo, Load = 0;

    modo = modoJogo();

    if(modo == 3){
        Load = 1;
    }

    inicializarJogo(T, M, mP1, mP2, modo, Load);

    printf("Fim do Programa~\n");

    return 0;
}
