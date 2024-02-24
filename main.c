#include "cliente.h"

int main() {
  // Aloca memória para armazenar os dados dos clientes
  int permanencia;
  char Escolha;
  int Quantidade_Clientes = Contador_Clientes();
  Clientes *Clientes_Var = (Clientes *)malloc(sizeof(Clientes) * Quantidade_Clientes);
  if (Clientes_Var == NULL) {
    printf("Erro na alocação de memória!!!");
    exit(1);
  }

  Ler_Dados(Clientes_Var, Quantidade_Clientes);

  do
  {
    permanencia = 0;
    printf("Caso desege cadastrar algun cliente digite \"S\"\n");
    scanf(" %c", &Escolha);
    Escolha = toupper(Escolha);
    if (Escolha == 'S'){
      printf("Digite o nome do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Nome);
      printf("Digite o endereco do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Nome);
      printf("Digite o codigo do cliente\n");
      scanf("%d", &Clientes_Var[Quantidade_Clientes].Nome);
      Quantidade_Clientes++;
      permanencia = 1;
    }
  }while(permanencia == 1);

  Clientes_Var = insertionSort(Clientes_Var, Quantidade_Clientes);

  // Chama a função Escrever_dados que foi implementada no cliente.c
  Escrever_dados(Clientes_Var, Quantidade_Clientes);

  // Libera a memória alocada
  free(Clientes_Var);

  return 0;
}
