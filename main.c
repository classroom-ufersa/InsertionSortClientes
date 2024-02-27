#include "cliente.h"

int main() {

  clock_t Tempo_Inicial, Tempo_Final;
  double Tempo_Total;
  Tempo_Inicial = clock();

  int permanencia, contador;
  char Escolha;
  int Quantidade_Clientes = Contador_Clientes();
  Clientes *Clientes_Var = (Clientes *)malloc(sizeof(Clientes) * Quantidade_Clientes);
  if (Clientes_Var == NULL) {
    printf("Erro na alocação de memória!!!");
    exit(1);
  }

  Ler_Dados(Clientes_Var, Quantidade_Clientes); 
  do  {
    permanencia = 0; 
    printf("Caso desege cadastrar algun cliente digite \"S\"\n");
    scanf(" %c", &Escolha);
    Escolha = toupper(Escolha); 

    if (Escolha == 'S'){
      Clientes_Var = (Clientes *)realloc(Clientes_Var, (Quantidade_Clientes + 1) * sizeof(Clientes));

      system("cls");
      printf("Digite o nome do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Nome);
      printf("Digite o endereco do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Endereco);
      printf("Digite o codigo do cliente\n");
      scanf("%lli", &Clientes_Var[Quantidade_Clientes].Codigo_de_Cliente);

      Quantidade_Clientes++;
      permanencia = 1;
    }
  } while (permanencia == 1);

  for (contador = 0; contador < Quantidade_Clientes; contador++)  {
    string_maiuscula_minuscula(Clientes_Var[contador].Nome);
  }

  for (contador = 0; contador < Quantidade_Clientes; contador++)  {
    Tratamento_de_Dado(Clientes_Var[contador].Nome);
  }

  Clientes_Var = insertionSort(Clientes_Var, Quantidade_Clientes);

  Escrever_dados(Clientes_Var, Quantidade_Clientes);

  free(Clientes_Var);

  Tempo_Total = (double)(Tempo_Final - Tempo_Inicial) / CLOCKS_PER_SEC;
  printf("Tempo de execução: %.9f segundos\n", Tempo_Total);

  return 0;
}
