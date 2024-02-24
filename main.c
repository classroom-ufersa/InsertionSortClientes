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

  int contador;
  for (contador = 0; contador < Quantidade_Clientes; contador++)
  {
    printf("nome do cliente %d e == %s\n", contador, Clientes_Var[contador].Nome);
  }

  do
  {
    permanencia = 0;
    printf("Caso desege cadastrar algun cliente digite \"S\"\n");
    scanf(" %c", &Escolha);
    Escolha = toupper(Escolha);
    if (Escolha == 'S'){
      Clientes_Var = realloc(Clientes_Var, (Quantidade_Clientes + 1) * sizeof(Clientes_Var));
      printf("Digite o nome do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Nome);
      printf("Digite o endereco do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Endereco);
      printf("Digite o codigo do cliente\n");
      scanf("%d", &Clientes_Var[Quantidade_Clientes].Codigo_de_Cliente);
      printf("nome do cliente %d e == %s\n", Quantidade_Clientes, Clientes_Var[Quantidade_Clientes].Nome);
      Quantidade_Clientes++;
      permanencia = 1;
    }
  }while(permanencia == 1);

  // Chama a função Escrever_dados que foi implementada no cliente.c
  Escrever_dados(Clientes_Var, Quantidade_Clientes);

  // Libera a memória alocada
  free(Clientes_Var);

  return 0;
}
