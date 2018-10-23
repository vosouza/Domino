#include <stdio.h>
#include <stdlib.h>
#include "Dados.h"

int main()
{
    Tabuleiro T[28];
    Tabuleiro mP1[28], mP2[28], M[28];

    inicializarMesa(M);
    inicializarMao(mP1, mP2);

    imprimirTabuleiro(M);
    return 0;
}
