#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arn.h"
#include "../lista/lista.h"

ARN* ARN_Buscar(ARN* A, char* chave) {
  if (A == NULL) return NULL;

  if (strcmp(chave, A->chave->palavra) == 0) return A;
  
  if (strcmp(chave, A->chave->palavra) < 0) return ARN_Buscar(A->esq, chave);
  
  return ARN_Buscar(A->dir, chave);
}

static ARN* ARN_Criar(char* chave, char* valor){
  ARN *no = malloc(sizeof(ARN));
  String* p = calloc(47, sizeof(String));

  no->chave = p; // Aponta para a posição alocada na heap
  strcpy(no->chave->palavra, chave); // Copia o valor da string recebida

  no->valor = LST_Criar(); // Cria a lista de Strings
  LST_Inserir(no->valor, valor); // Insere o primeiro elemento

  no->cor = RUBRO;
  no->dir = NULL;
  no->esq = NULL;

  return no;
}

void ARN_Imprimir(ARN* A, int inicio, char direcao) {
  int i;
  
  if (A == NULL) return;

  for(i = 0; i < inicio; i++){
    printf("\t");
  }

  printf("(%c) %s\n", direcao, A->chave->palavra);

  ARN_Imprimir(A->dir, inicio + 1, 'd');
  ARN_Imprimir(A->esq, inicio - 1, 'e');
}

static inline int eh_rubro(ARN *A){
  if(A == NULL) return 0;
  return (A->cor == RUBRO) ? 1 : 0;
}

static void rot_dir(ARN **A){
  ARN *h = *A;
  ARN *x = h->esq;
  
  h->esq = x->dir;
  x->dir = h;
  x->cor = h->cor;
  h->cor = RUBRO;

  *A = x;
}

static void rot_esq(ARN **A){
  ARN *h = *A;
  ARN *x = h->dir;

  h->dir = x->esq;
  x->esq = h;
  x->cor = h->cor;
  h->cor = RUBRO;

  *A = x;
}

static void invercao_cores(ARN *A){
  A->cor = RUBRO;
  A->esq->cor = NEGRO;
  A->dir->cor = NEGRO;
}

void ARN_Inserir_Recursivo(ARN **A, char* chave, char* valor){
  if(*A == NULL){
    *A = ARN_Criar(chave, valor);
    return;
  }

  // 0 - Se as duas são iguais
  // < 0 Se a primeira for menor que a segunda(s1 < s2)
  // > 0 Se a primeira for maior que a segunda(s2 < s1)
  int comp_chaves = strcmp(chave, (*A)->chave->palavra);

  if(comp_chaves == 0){
    LST_Inserir((*A)->valor, valor);
  }

  //chave < (*A)->chave
  //chave > (*A)->chave

  if(strcmp(chave, (*A)->chave->palavra) < 0) // Se a chave passada for menor do que a encontrada
    ARN_Inserir_Recursivo(&(*A)->esq, chave, valor);
  
  if(strcmp(chave, (*A)->chave->palavra) > 0)
    ARN_Inserir_Recursivo(&(*A)->dir, chave, valor); // Se a chave passada for menor do que a encontrada
  
  if(eh_rubro((*A)->dir) && !eh_rubro((*A)->esq)){
    rot_esq(A);
  }
  
  if(eh_rubro((*A)->esq) && eh_rubro((*A)->esq->esq)){
    rot_dir(A);
  }

  if(eh_rubro((*A)->esq) && eh_rubro((*A)->dir)){
    invercao_cores(*A);
  }
}

void ARN_Inserir(ARN **A, char* chave, char* valor){
  ARN_Inserir_Recursivo(A, chave, valor);
  (*A)->cor = NEGRO;
}

// int ARN_Altura(ARN *A){
//   if(A == NULL) return 0;

//   int alt_d = ARN_Altura(A->dir);
//   int alt_e = ARN_Altura(A->esq);

//   if(alt_e < alt_d){
//     if(A->cor == NEGRO) return alt_d+1;
//   }
//   else{
//     if(A->cor == NEGRO) return alt_e+1;
//   }
// }

// static void ARN_Sort_R(ARN *A, int *v, int *i){
//   if(A == NULL) return;
//   ARN_Sort_R(A->esq, v, i);
//   v[(*i)] = A->chave;
//   *i += 1;
//   ARN_Sort_R(A->dir, v, i);
//   free(A); 
// }

// void ARN_Sort(int* v, int n, float *altura){
//   ARN *A = NULL;
//   for(int i = 0; i < n; i++) ARN_Inserir(&A , v[i], 0);

//   *altura += ARN_Altura(A);

//   int x = 0;
//   ARN_Sort_R(A, v, &x);
// }