#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura clientes
typedef struct {
  char Nome[80];
  char Endereco[80];
  int Codigo_de_Cliente;
} Clientes;

// Função para escrever os dados dos clientes em um arquivo
void Escrever_dados() {
  int Quantidade_Clientes;
  int contador;

  // Solicita a quantidade de clientes ao usuário
  printf("Digite a Quantidade de Clientes:\t");
  scanf("%d", &Quantidade_Clientes);

  // Aloca memória para armazenar os dados dos clientes
  Clientes *Clientes_Var = (Clientes *)malloc(sizeof(Clientes) * Quantidade_Clientes);
  if (Clientes_Var == NULL) {
    printf("Erro na alocação de memória!!!");
    exit(1);
  }

  // Abre o arquivo para escrita
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "w+");
  if (Arquivo_Clientes == NULL) {
    printf("Erro na abertura do arquivo!!!");
    exit(1);
  }

  // Loop para coletar os dados dos clientes
  for (contador = 0; contador < Quantidade_Clientes; contador++) {
    printf("Digite o nome do cliente:\n");
    scanf(" %[^\n]", Clientes_Var[contador].Nome);
    string_maiuscula_minuscula(Clientes_Var[contador].Nome);

    printf("Digite o endereco do cliente:\n");
    scanf(" %[^\n]", Clientes_Var[contador].Endereco);

    printf("Digite o codigo do cliente:\n");
    scanf("%d", &Clientes_Var[contador].Codigo_de_Cliente);
  }

  // Chama a função insertionSort para ordenar os clientes pelo nome
  Clientes_Var = insertionSort(Clientes_Var, Quantidade_Clientes);

  // Escreve os dados dos clientes ordenados no arquivo
  for (contador = 0; contador < Quantidade_Clientes; contador++) {
    fprintf(Arquivo_Clientes, "Dados dos clientes %d:\n", contador + 1);
    fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador].Nome);
    fprintf(Arquivo_Clientes, "Endereco:  %s\n", Clientes_Var[contador].Endereco);
    fprintf(Arquivo_Clientes, "Codigo de Cliente:  %d\n\n", Clientes_Var[contador].Codigo_de_Cliente);
  }

  // Fecha o arquivo
  fclose(Arquivo_Clientes);
  // Libera a memória alocada
  free(Clientes_Var);
}

//Funcao que converte uma string para o formato de capitalizacao mista
void string_maiuscula_minuscula(char *str) {
  int i;
  str[0] = toupper(str[0]);
  for (i = 1; str[i] != '\0'; i++) {
    if (isspace(str[i - 1])) { // Se o caractere passado for um espaço
      str[i] = toupper(str[i]); // Transforma a letra em maiúscula
    } else {
      str[i] = tolower(str[i]); // Transforma a letra em minúscula
    }
  }
}

// Função de ordenação insertionSort
Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes) {
  int i, j;
  Clientes key;

  for (i = 1; i < Quantidade_Clientes; i++) {
    key = Clientes_Var[i];
    j = i - 1;

    // Comparação completa dos nomes usando strcmp
    while (j >= 0 && strcmp(Clientes_Var[j].Nome, key.Nome) > 0) {
      Clientes_Var[j + 1] = Clientes_Var[j];
      j--;
    }
    Clientes_Var[j + 1] = key;
  }
  return Clientes_Var;
}
