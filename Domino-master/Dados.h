#ifndef Dados_H
#define Dados_H
typedef struct{
    int d;
    int e;
    int s;
}Domino;


typedef struct{
    Domino *p;
}Tabuleiro;

void inicializarTabuleiro(Tabuleiro T[]);

void inicializarMesa(Tabuleiro M[]);

void inicializarMao(Tabuleiro mP1[], Tabuleiro mP2[]);

void darMaos(Tabuleiro mP1[], Tabuleiro mP2[], Tabuleiro M[]);

int tamTotal(Tabuleiro X[]);

#endif
