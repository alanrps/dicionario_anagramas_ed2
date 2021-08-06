//ARVORE RUBRO NEGRA
#pragma once
typedef enum { RUBRO, NEGRO } Link;

typedef struct ARN {
  struct ARN *esq;
  struct ARN *dir;
  int valor;
  // Lista valor;
  int chave;
  Link cor;
} ARN;

void ARN_Inserir(ARN **A, int chave, int valor);
void ARN_Sort(int* v, int n, float *altura);
int ARN_Altura(ARN *A);
ARN* ARN_Buscar(ARN* A, int chave);
void ARN_Imprimir(ARN* A, int inicio, char direcao);