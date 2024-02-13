#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct clientes Clientes;
/*Cria tipo estruturado Clientes e preenche seus campos
@Param nome: nome do cliente
@Param endereço: endereço do cliente
@param Codigo do cliente: Codigo que identifica o cliente
*/

void Escrever_dados();


void insertionSort(Clientes **Clientes_Var, int Quantidade_Clientes);

#endif // CLIENTES_H