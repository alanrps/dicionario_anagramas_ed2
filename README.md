# Dicionário de Anagramas

## Descrição do Trabalho

Implementar um dicionário de anagramas para palavras da lingua portuguesa em **C**. Seu programa
deve receber uma única palavra pela linha de comando (sem acentos) e imprimir na saída a lista de todos
os seus anagramas em ordem alfabética, incluindo a própria palavra de entrada. Cada anagrama deve ser
impresso em sua própria linha. Desconsidere a diferença entre maiúsculas e minúsculas. Por exemplo, caso o
usuário entre com CEBOLA, a saída deve ser cebola e cabelo.
A busca pelos anagramas deve ser realizada em Θ(lg n), tal que n é o número de palavras no dicionário da
lingua portuguesa. O pré-processamento deve ocorrer no máximo em tempo Θ(n lg(n)).
O dicionário de palavras é fornecido. Para evitar ter que lidar com UTF-8 em C, o dicionário não contém
acentos.

## Exemplos
Os anagramas da palavra cebola são cebola e cabelo.
Os anagramas da palavra amor são amor, armo, oram, ramo, roam, e roma. (sim, roam é uma palavra da
lingua portuguesa.)

## Estrutura utilizada

- Árvore rubro-negra
- Lista encadeada


