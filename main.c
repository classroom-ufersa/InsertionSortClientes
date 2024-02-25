#include "cliente.h"

int main() {
  // Aloca memória para armazenar os dados dos clientes
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
    permanencia = 0; // Torna falso a condição do loop, ou seja, caso não entre no if o loop se encerra
    printf("Caso desege cadastrar algun cliente digite \"S\"\n");
    scanf(" %c", &Escolha); // Recebe a letra escolhida pelo o usuario
    Escolha = toupper(Escolha); // Torna ela sempre maiuscula

    if (Escolha == 'S'){ // Verifica se foi digitado 's' ou 'S' 
      // Realoca a variavel clientes, afim de aumentar o vetor para receber os dados do novo cliente
      Clientes_Var = (Clientes *)realloc(Clientes_Var, (Quantidade_Clientes + 1) * sizeof(Clientes));

      system("cls"); // Limpa tela
      printf("Digite o nome do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Nome); // Recebe o nome do novo cliente
      printf("Digite o endereco do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Endereco); // Recebe o enderço do novo cliente
      printf("Digite o codigo do cliente\n");
      scanf("%d", &Clientes_Var[Quantidade_Clientes].Codigo_de_Cliente); // Recebe o enderço do novo cliente

      Quantidade_Clientes++; // Incrementa +1, afim de registrar o novo cliente cadastrado
      permanencia = 1; // Torna verdadeira a condição do loop
    }
  } while (permanencia == 1);

  for (contador = 0; contador < Quantidade_Clientes; contador++)  {
    string_maiuscula_minuscula(Clientes_Var[contador].Nome);
  }

  Clientes_Var = insertionSort(Clientes_Var, Quantidade_Clientes);

  // Chama a função Escrever_dados que foi implementada no cliente.c
  Escrever_dados(Clientes_Var, Quantidade_Clientes);

  // Libera a memória alocada
  free(Clientes_Var);

  return 0;
}
