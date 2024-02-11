#include <stdio.h>
#include <stdlib.h>

#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct clientes Clientes;

/*Funcao que preenche os dados dos clientes e os armazena em um arquivo e no vetor*/
void escrever_dados();

void insertionSort(Clientes **Clientes_Var, int Quantidade_Clientes);

#endif // CLIENTES_H
