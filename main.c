#include "cliente.h"

int main() {
  // Aloca memória para armazenar os dados dos clientes
  int Quantidade_Clientes = Contador_Clientes();
  Clientes *Clientes_Var = (Clientes *)malloc(sizeof(Clientes) * Quantidade_Clientes);
  if (Clientes_Var == NULL) {
    printf("Erro na alocação de memória!!!");
    exit(1);
  }

  Ler_Dados(Clientes_Var, Quantidade_Clientes);
  printf("dentro do ler_dados == %d\n", Quantidade_Clientes);

  // Chama a função Escrever_dados que foi implementada no cliente.c
  Escrever_dados(Clientes_Var, Quantidade_Clientes);

  // Libera a memória alocada
  free(Clientes_Var);

  return 0;
}
