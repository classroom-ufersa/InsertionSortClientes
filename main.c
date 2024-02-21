#include "cliente.c"

int main()
{
  int permanencia, escolha;
  int *Quantidade_clientes;
  Clientes *Clientes_var = (Clientes *)malloc(sizeof(Clientes));

  Ler_Arquivo(Clientes_var, Quantidade_clientes);

  // Loop para coletar os dados dos clientes
  do
  {
    permanencia = 0;
    printf("Caso deseje cadastrar um novo cliente digite 1\n");
    scanf("%d", escolha);
    if (escolha == 1)
    {
      realloc(Quantidade_clientes, *Quantidade_clientes++);
      printf("Digite o nome do cliente:\n");
      scanf(" %[^\n]", Clientes_var[*Quantidade_clientes + 1].Nome);
      string_maiuscula_minuscula(Clientes_var[*Quantidade_clientes + 1].Nome);

      printf("Digite o endereco do cliente:\n");
      scanf(" %[^\n]", Clientes_var[*Quantidade_clientes + 1].Endereco);

      printf("Digite o codigo do cliente:\n");
      scanf("%d", &Clientes_var[*Quantidade_clientes + 1].Codigo_de_Cliente);

      permanencia = 1;
    }

  } while (permanencia == 1);
  // Chama a função insertionSort para ordenar os clientes pelo nome
  insertionSort(Clientes_var, Quantidade_clientes);

  // Chama a função Escrever_dados que foi implementada no cliente.c
  Escrever_dados(Clientes_var, Quantidade_clientes);

  // Libera a memória alocada
  free(Clientes_var);
  return 0;
}
