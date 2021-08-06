#include <stdio.h>
#include <stdlib.h>
#include "arn/arn.h"
#include "ordenacao/bs.h"
#include "lista/lista.h"

int main (int argc, char **argv) {
    ARN* A = NULL;

    char* palavra;

    // Recebe palavra
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    // Ordena palavra
    bubble_sort(palavra);
    printf("%s", palavra);

    // Manipula a árvore rubro negra
    ARN_Inserir(&A, 10, 10);
    ARN_Inserir(&A, 1, 1);
    ARN_Inserir(&A, 8, 8);
    ARN_Inserir(&A, 5, 5);

    ARN_Imprimir(A, 2, '*');

    // Cria lista e insere dados
    ILISTA* lista = LST_Criar();
    int dado1 = LST_Inserir(lista, 10);
    int dado2 = LST_Inserir(lista, 20);
    int dado3 = LST_Inserir(lista, 30);
    LST_Imprimir(lista);

  return 0;
}