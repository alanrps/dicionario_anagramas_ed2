#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arn/arn.h"
#include "ordenacao/bs.h"
#include "lista/lista.h"
#include "auxiliares/auxiliares.h"

int main (int argc, char *argv[]) {
    ARN* A = NULL;

    char palavra[46];
    char palavra_ordenada[46];
    char* palavra_entrada = argv[1]; 

    FILE* dicionario = fopen("./dicionario/dicionario.txt", "r");

    if(dicionario == NULL){
      printf("Erro ao abrir arquivo");
      return 0;
    }

    char* result;
    while (!feof(dicionario)){
      result = fgets(palavra, 46, dicionario);

      if(result){
        palavra[strlen(palavra) - 1] = 0;
        
        minuscula(palavra);

        strcpy(palavra_ordenada, palavra);

        bubble_sort(palavra_ordenada);

        ARN* no = ARN_Buscar(A, palavra_ordenada);

        if(no){
          int valueFound = LST_Buscar(no->valor, palavra);

          if(!valueFound)
            LST_Inserir(no->valor, palavra);
        }else{
          ARN_Inserir(&A, palavra_ordenada, palavra);
        }
      }
      else{
        break;
      }
    }

    fclose(dicionario);

    minuscula(palavra_entrada);
    bubble_sort(palavra_entrada);

    ARN* no = ARN_Buscar(A, palavra_entrada);

    if(no){
      // LST_Imprimir(no->valor);
      bubble_sort_palavras(no->valor);
      LST_Imprimir(no->valor);
    }
    else
      printf("Nenhum anagrama encontrado");

  return 0;
}
