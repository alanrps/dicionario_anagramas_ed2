//ARVORE RUBRO NEGRA
#pragma once

typedef enum { RUBRO, NEGRO } Link;
#include "../auxiliares/auxiliares.h"

typedef struct ARN {
  struct ARN *esq;
  struct ARN *dir;
  // int chave;
  // Lista valor;
  String* chave;
  int valor;
  Link cor;
} ARN;

void ARN_Inserir(ARN **A, char* chave, int valor);
ARN* ARN_Buscar(ARN* A, char* chave);
void ARN_Imprimir(ARN* A, int inicio, char direcao);
// void ARN_Sort(int* v, int n, float *altura);
// int ARN_Altura(ARN *A);