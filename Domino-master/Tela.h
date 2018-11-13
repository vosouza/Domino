#ifndef Tela_H
#define Tela_H
#include "Dados.h"

void imprimirTabuleiro(Tabuleiro M[]);

void imprimirMao(Tabuleiro mP[]);

int Menu(Tabuleiro T[28], Tabuleiro mP[28]);

void escolhaPecaTela(Tabuleiro T[], Tabuleiro mP[], int pos[]);

void semPecaTela();

void turnoPCTela();

void semPecaPCTela();

void imprimirTurno(int turno);

int modoJogo();

void organizarPecaTela(int *ordem, int *direcao);

void salvarJogoTela(Tabuleiro T[], Tabuleiro M[], Tabuleiro mP1[], Tabuleiro mP2[], int Modo, int turno);

void mostrarMaoOT(Tabuleiro mP2[]);

#endif
