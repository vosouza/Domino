#ifndef Dados_H
#define Dados_H
typedef struct{
    int d;
    int e;
}Domino;


typedef struct{
    Domino *p;
}Tabuleiro;


void inicializarMesa(Tabuleiro M[28]);


#endif
