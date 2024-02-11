#include <stdio.h>
#include <stdlib.h>

/*Renomeacao do tipo estruturado cliente que armazena vetores para os dados*/
typedef struct clientes Clientes;

/*Funcao que preenche os dados dos clientes e os armazena em um arquivo e no vetor*/
void escrever_dados();

void insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes);
