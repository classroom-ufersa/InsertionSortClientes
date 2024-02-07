#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

struct clientes{
    char Nome[80];
    char Endereco[80];
    int Codigo_de_Cliente;
};

void Escrever_dados(){

    int Quantidade_Clientes;
    printf("Digite a Quantidade de Clientes:\t");
    scanf("%d", &Quantidade_Clientes);
    struct clientes *Clientes_Var = (struct clientes *)malloc(sizeof(struct clientes) * Quantidade_Clientes);
    FILE *Arquivo_Clientes = fopen("Clientes.txt", "wr");
    fclose(Arquivo_Clientes);
}
