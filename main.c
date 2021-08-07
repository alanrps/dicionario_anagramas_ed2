#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arn/arn.h"
#include "ordenacao/bs.h"
#include "lista/lista.h"
#include "auxiliares/auxiliares.h"

int main (int argc, char **argv) {
    ARN* A = NULL;

    char palavra[46];
    char palavra_ordenada[46];

    FILE* dicionario = fopen("./dicionario/dicionario.txt", "r");

    if(dicionario == NULL){
      printf("Erro ao abrir arquivo");
      return 0;
    }

    char* result;
    while (!feof(dicionario)){
      result = fgets(palavra, 46, dicionario);

      if(result){
        minuscula(palavra);

        strcpy(palavra_ordenada, palavra);

        bubble_sort(palavra);
        ARN_Inserir(&A, palavra_ordenada, palavra);
      }
      else{
        break;
      }
    }

    fclose(dicionario);
    
    printf("Arquivo percorrido com sucesso: altura %d", ARN_Altura(A));

    // ARN_Imprimir(A, 2, '*');

    
    // Recebe palavra
    // printf("Digite uma palavra: ");
    // scanf("%s", palavra);

    // strcpy(p->palavra, palavra);

    // printf("%s", p->palavra);

    // Ordena palavra
    // bubble_sort(palavra);
    // printf("%s", palavra);

    // Manipula a árvore rubro negra
    // Chave -> Valor odenado
    // Valor -> Valor
    // ARN_Inserir(&A, "amor", "ramo");
    // ARN_Inserir(&A, "amor", "roma");
    // ARN_Inserir(&A, "guga", "guga");
    // ARN_Inserir(&A, 8, 8);
    // ARN_Inserir(&A, 5, 5);
    // ARN_Imprimir(A, 2, '*');

    // ARN* no = ARN_Buscar(A, "amor");

    // LST_Imprimir(no->valor);

    // if(dado->chave->palavra) printf("%s", dado->chave->palavra);


    // Cria lista e insere dados
    // ILISTA* lista = LST_Criar();
    // int dado1 = LST_Inserir(lista, "alan");
    // int dado2 = LST_Inserir(lista, "joao");
    // int dado3 = LST_Inserir(lista, "matheus");
    // LST_Imprimir(lista);

    // int resultado = LST_Buscar(lista, "matheus");
    // printf("%d", resultado);

    // Criar estrutura da palavra
    // Trocar valor da árvore pela lista

    // Inserção de palavra
    // 1- Buscar chave ordenada na árvore
    // - Se não existir "criar" a chave com a palavra ordenada, criar a lista e inserir a palavra 
    // - Se existir adicionar no array

    // Busca 
    // 1- Ordenar a palavra recebida
    // 2 - Buscar uma chave com a palavra
    // --> Caso encontre
    // - Ordenar array
    // - Imprimir cada valor em uma linha
    // --> Caso não encontre, retornar que não foi encontrado

    // Ler valores do arquivo e adicionar a árvore

  return 0;
}