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

int main() {
  Escrever_dados(); // Chama a função para escrever os dados dos clientes no
                    // arquivo
  FILE *Arquivo_Clientes =
      fopen("Clientes.txt", "r"); // Abre o arquivo para leitura

  // Verifica se o arquivo foi aberto corretamente
  if (Arquivo_Clientes == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1; // Retorna 1 para indicar erro
  }

  // Determina o número de clientes lidos do arquivo
  int Quantidade_Clientes = contarClientes(Arquivo_Clientes);

  // Aloca memória para os clientes
  Clientes **Clientes_Var =
      (Clientes **)malloc(sizeof(Clientes *) * Quantidade_Clientes);
  for (int i = 0; i < Quantidade_Clientes; i++) {
    Clientes_Var[i] = (Clientes *)malloc(sizeof(Clientes));
  }

  // Lê os dados dos clientes do arquivo
  int i = 0;
  while (fscanf(Arquivo_Clientes, " %[^\n]s", Clientes_Var[i]->Nome) != EOF) {
    fscanf(Arquivo_Clientes, " %[^\n]s", Clientes_Var[i]->Endereco);
    fscanf(Arquivo_Clientes, "%d", &Clientes_Var[i]->Codigo_de_Cliente);
    i++;
  }

  fclose(Arquivo_Clientes); // Fecha o arquivo

  // Ordena os clientes pelo nome usando o algoritmo de ordenação insertion sort
  insertionSort(Clientes_Var, Quantidade_Clientes);

  // Exibe os dados dos clientes ordenados pelo nome
  printf("\nDados dos clientes ordenados pelo nome:\n");
  printf("----------------------------------------\n");
  for (int i = 0; i < Quantidade_Clientes; i++) {
    printf("Nome: %s\n", Clientes_Var[i]->Nome);
    printf("Endereco: %s\n", Clientes_Var[i]->Endereco);
    printf("Codigo de Cliente: %d\n", Clientes_Var[i]->Codigo_de_Cliente);
    printf("----------------------------------------\n");
  }

  // Libera a memória alocada para os clientes
  free(Clientes_Var);

  return 0; // Retorna 0 para indicar sucesso
}