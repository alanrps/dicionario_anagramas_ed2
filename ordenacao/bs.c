#include <string.h>
#include "../lista/lista.h"

void bubble_sort(char *str){
    char temp;
    int i, j;
    int n = strlen(str);

    for (i = 0; i < n-1; i++) {
		for (j = i + 1; j < n; j++) {
			if (str[i] > str[j]) {
					temp = str[i];
					str[i] = str[j];
					str[j] = temp;
			}
		}
	}
}

void bubble_sort_palavras(ILISTA* L){
    int i;
	ILISTA_EL* k = L->primeiro;
	ILISTA_EL* j;

    char* aux;

    for (i = 0; i < L->tamanho - 1; i++) { 
		for (j = k->prox; j->prox != NULL; j = j->prox) { 
			if (strcmp(k->dado->palavra, j->dado->palavra) > 0) {
					strcpy(aux, k->dado->palavra);
					stpcpy(k->dado->palavra, j->dado->palavra);
					stpcpy(j->dado->palavra, aux);
			}
		}
		k = k->prox;
	}
}
