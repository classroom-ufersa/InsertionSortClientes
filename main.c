#include "cliente.h"

int main() {

  int permanencia, contador; //Criacao de duas variaveis inteiras, uma vai servir de contador em um loop e a outra vai controlar outro loop.
  char Escolha; //Criação de uma variavel para checar a escolha do usuario.
  int Quantidade_Clientes = Contador_Clientes(); //Chama a função Contador_Clientes para obter a quantidade de clientes dentro do arquivo.
 
  Clientes *Clientes_Var = (Clientes *)malloc(sizeof(Clientes) * Quantidade_Clientes);   // Aloca memória para armazenar os dados dos clientes.
  if (Clientes_Var == NULL) { //verifica se a alocacao foi bem sucedida, se não, aparece uma mensagem de erro na tela e o programa e encerrado.
    printf("Erro na alocação de memória!!!");
    exit(1);
  }

  Ler_Dados(Clientes_Var, Quantidade_Clientes); //Chama a função Ler_Dados

  do  {
    permanencia = 0; // Torna falso a condição do loop, ou seja, caso não entre no if o loop se encerra.
    printf("Caso desege cadastrar algun cliente digite \"S\"\n");
    scanf(" %c", &Escolha); // Recebe a letra escolhida pelo o usuario
    Escolha = toupper(Escolha); // Torna ela sempre maiuscula

    if (Escolha == 'S'){ // Verifica se foi digitado 's' ou 'S' 
      // Realoca(altera o tamanho) a variavel clientes, com a intenção de aumentar o vetor para receber os dados do novo cliente
      Clientes_Var = (Clientes *)realloc(Clientes_Var, (Quantidade_Clientes + 1) * sizeof(Clientes));

      system("cls"); // Limpa tela
      printf("Digite o nome do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Nome); // Recebe o nome do novo cliente.
      printf("Digite o endereco do cliente\n");
      scanf(" %[^\n]", Clientes_Var[Quantidade_Clientes].Endereco); // Recebe o endereço do novo cliente.
      printf("Digite o codigo do cliente\n");
      scanf("%d", &Clientes_Var[Quantidade_Clientes].Codigo_de_Cliente); // Recebe o enderço do novo cliente.

      Quantidade_Clientes++; //Incrementa +1, afim de registrar o novo cliente cadastrado.
      permanencia = 1; //Torna verdadeira a condição do loop, afim de permanecer nele.
    }
  } while (permanencia == 1); //Verifica se a condição de permanencie e verdadeira.

  for (contador = 0; contador < Quantidade_Clientes; contador++)  { //Entra no loop que vai percorrer todos os clientes, tornando o nome em formato padrão.
    string_maiuscula_minuscula(Clientes_Var[contador].Nome);
  }

  Clientes_Var = insertionSort(Clientes_Var, Quantidade_Clientes); //chama a função insertionSort para ordenar o array de estruturas.

  //Chama a função Escrever_dados para escrever os clientes no arquivo.
  Escrever_dados(Clientes_Var, Quantidade_Clientes);

  //Libera a memória alocada.
  free(Clientes_Var);

  return 0;
}
