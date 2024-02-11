#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct clientes Clientes;

/*Funcao que preenche os dados dos clientes e os armazena em um arquivo e no vetor*/
void Escrever_dados();

Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes);

#endif // CLIENTES_H
