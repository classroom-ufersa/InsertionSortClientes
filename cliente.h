#ifndef CLIENTE_H
#define CLIENTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct clientes {
    char Nome[80];
    char Endereco[80];
    long long int Codigo_de_Cliente;
} Clientes;

int Contador_Clientes();
void Ler_Dados(Clientes *Clientes_Var, int Quantidade_Clientes);
void Escrever_dados(Clientes *Clientes_Var, int Quantidade_Clientes);
void string_maiuscula_minuscula(char *str);
Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes);

#endif /* CLIENTE_H */
