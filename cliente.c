#include <stdio.h>
#include "cliente.h"
#include <stdlib.h>
#include <string.h>

struct clientes
{
  char Nome[80];
  char Endereco[80];
  int Codigo_de_Cliente;
};

void Escrever_dados()
{
  int Quantidade_Clientes;
  int contador;

  printf("Digite a Quantidade de Clientes:\t");
  scanf("%d", &Quantidade_Clientes);

  Clientes *Clientes_Var = (Clientes *)malloc(sizeof(Clientes) * Quantidade_Clientes);
  if (Clientes_Var == NULL)
  {
    printf("Erro na alocacao!!!");
    exit(1);
  }

  FILE *Arquivo_Clientes = fopen("Clientes.txt", "w+");
  if (Arquivo_Clientes == NULL)
  {
    printf("Erro no arquivo!!!");
    exit(1);
  }

  for (contador = 0; contador < Quantidade_Clientes; contador++)
  {
    system("cls");
    printf("Digite o nome do cliente:\n");
    scanf(" %[^\n]", Clientes_Var[contador].Nome);

    printf("Digite o endereco do cliente:\n");
    scanf(" %[^\n]", Clientes_Var[contador].Endereco);

    printf("Digite o codigo do cliente:\n");
    scanf("%d", &Clientes_Var[contador].Codigo_de_Cliente);
  }

  Clientes_Var = insertionSort(Clientes_Var, Quantidade_Clientes);
  for (contador = 0; contador < Quantidade_Clientes; contador++)
  {
    fprintf(Arquivo_Clientes, "Dados dos clientes %d:\n", contador + 1);
    fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador].Nome);
    fprintf(Arquivo_Clientes, "Endereco:  %s\n", Clientes_Var[contador].Endereco);
    fprintf(Arquivo_Clientes, "Codigo de Cliente:  %d\n\n", Clientes_Var[contador].Codigo_de_Cliente);
  }

  fclose(Arquivo_Clientes); // fechar o arquivo
  free(Clientes_Var);       // Liberar memória alocada
}

Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes)
{
  int i, j;
  Clientes key;

  for (i = 1; i < Quantidade_Clientes; i++)
  {
    key = Clientes_Var[i];
    j = i - 1;

    // Comparação completa dos nomes usando strcmp
    while (j >= 0 && strcmp(Clientes_Var[j].Nome, key.Nome) > 0)
    {
      Clientes_Var[j + 1] = Clientes_Var[j];
      j--;
    }
    Clientes_Var[j + 1] = key;
  }
  return Clientes_Var;
}