#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

struct clientes{
    char Nome[80];
    char Endereco[80];
    int Codigo_de_Cliente;
}


Ler_dados(){

    fopen("Clientes.txt", "rt");
}