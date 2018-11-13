#ifndef Funcoes_H
#define Funcoes_H
#include "Dados.h"
#include "Tela.h"
#include<stdbool.h>

void inicializarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo, int Load);

void JogarPL(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo);

void JogarPc(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo);

void corrigirOrdem(Tabuleiro X[]);

void inserirPeca(Tabuleiro T[], Tabuleiro mP[], int posP, int posT);

bool checarMao(Tabuleiro T[], Tabuleiro mP[]);

void inserirPimeiraPeca(Tabuleiro T[], Tabuleiro mP1[]);

bool posValida(Tabuleiro T[], Tabuleiro mP[], int posP, int posT);

void moverTabuleiro(Tabuleiro T[]);

void semPeca(Tabuleiro mP[], Tabuleiro M[]);

bool turnoPC(Tabuleiro T[], Tabuleiro mP[]);

void organizarPeca(Tabuleiro mP[],int ordem ,int direcao);

void invertePeca(Tabuleiro mP[], int pos);

void salvarJogo(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo, int turno, char nomeArq[]);

int loadGame(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[]);
#endif
