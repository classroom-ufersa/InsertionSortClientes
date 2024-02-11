#include <stdio.h>
#include "cliente.h"
#include <stdlib.h>

    struct clientes {
  char Nome[80];
  char Endereco[80];
  int Codigo_de_Cliente;
};

void Escrever_dados() {

  int Quantidade_Clientes;
  int contador; int i;
  printf("Digite a Quantidade de Clientes:\t");
  scanf("%d", &Quantidade_Clientes);
 Clientes **Clientes_Var = (Clientes **)malloc(sizeof(Clientes *) * Quantidade_Clientes);
if (Clientes_Var == NULL) {
    printf("Erro ao alocar memória para os clientes.\n");
    // Trate o erro de acordo com a necessidade, como encerrar o programa ou retornar um código de erro
    exit(1); // Ou outro valor de erro adequado
}

for(i=0; i<Quantidade_Clientes; i++){
        Clientes_Var[i] = (Clientes*) malloc(sizeof(Clientes));
      }
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "w+");

  for (contador = 0; contador < Quantidade_Clientes; contador++) {
    // fprintf(Arquivo_Clientes, "Dados dos clientes:\n");

    printf("Digite o nome do cliente:\n");
    scanf(" %[^\n]", Clientes_Var[contador]->Nome);
    fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador]->Nome);

    printf("Digite o endereco do cliente:\n");
    scanf(" %[^\n]", Clientes_Var[contador]->Endereco);
    fprintf(Arquivo_Clientes, "Endereco:  %s\n",
            Clientes_Var[contador]->Endereco);

    printf("Digite o codigo do cliente:\n");
    scanf("%d", &Clientes_Var[contador]->Codigo_de_Cliente);
    fprintf(Arquivo_Clientes, "Codigo de Cliente:  %d\n",
            Clientes_Var[contador]->Codigo_de_Cliente);
  }

  fclose(Arquivo_Clientes);
}

void insertionSort(Clientes **Clientes_Var, int Quantidade_Clientes) {
  int Contador1, Contador2;
  char key;
  for (Contador1 = 1; Contador1 < Quantidade_Clientes; Contador1++) {
    key = Clientes_Var[Contador1]->Nome[0];
    Contador2 = Contador1 - 1;

    while (Contador2 >= 0 && Clientes_Var[Contador2]->Nome[0] > key) {
      Clientes_Var[Contador2 + 1]->Nome[0] = Clientes_Var[Contador2]->Nome[0];
      Contador2 = Contador2 - 1;
    }
    Clientes_Var[Contador2 + 1]->Nome[0] = key;
  }
}