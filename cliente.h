#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Renomeacao de um tipo estruturado para Clientes*/
typedef struct clientes Clientes;

void ler_arquivo(Clientes *Clientes_var);

/*Funcao que preenche os dados dos clientes e os armazena em um arquivo e no vetor*/
void Escrever_dados(Clientes *Clientes_var);

/*Funcao que converte uma string para o formato de capitalizacao mista, 
  Recebe como parametro o ponteiro do tipo caractere*/
void string_maiuscula_minuscula(char *str);

/*Implemetacao do algoritmo de ordenacao Insertion Sort, 
  Recebe como parametros o ponteiro de cliente e a quantidade do tipo inteiro*/
Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes);

#endif // CLIENTES_H
