#include "cliente.c"
#include <stdio.h>
#include <stdlib.h>

int contarClientes(FILE *arquivo) {
  int contador = 0;
  char linha[100]; // Supõe que uma linha terá no máximo 100 caracteres

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    if (linha[0] != '\n') // Ignora linhas em branco
      contador++;
  }

  rewind(arquivo); // Volta ao início do arquivo
  return contador;
}