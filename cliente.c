Cliente.c

#include "cliente.h"

// Definição da estrutura clientes
struct clientes{
  char Nome[80];
  char Endereco[80];
  int Codigo_de_Cliente;
};

void Contador_de_Clientes(int *Quantidade_clientes){
  char linha[200];
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt");
  if (Arquivo_Clientes == NULL) {
    printf("Erro na abertura do arquivo!!!");
    exit(1);
  }
  while (fgets(linha, 200, Arquivo_Clientes)) {
    if (strstr(linha, "Dados dos clientes"))  {
      Quantidade_clientes++;
    }
  }
  fclose(Arquivo_Clientes);
}

void Ler_Arquivo(Clientes *Clientes_Var, int *Quantidade_clientes){
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt");
  int contador;
  for (contador = 0; contador < *Quantidade_clientes; contador++){
    fscanf(Arquivo_Clientes, "Dados dos clientes %*d:\nNome: %s\nEndereco: %s\nCodigo de Cliente: %d\n\n", Clientes_Var[contador].Nome, Clientes_Var[contador].Endereco, Clientes_Var[contador].Codigo_de_Cliente);
  }
  fclose(Arquivo_Clientes);
}

// Função para escrever os dados dos clientes em um arquivo
void Escrever_dados(Clientes *Clientes_Var, int *Quantidade_clientes){
  int contador;
  // Abre o arquivo para escrita
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "wt");
  if (Arquivo_Clientes == NULL)
  {
    printf("Erro na abertura do arquivo!!!");
    exit(1);
  }

  // Escreve os dados dos clientes ordenados no arquivo
  for (contador = 0; contador < *Quantidade_clientes; contador++)
  {
    fprintf(Arquivo_Clientes, "Dados dos clientes %d:\n", contador + 1);
    fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador].Nome);
    fprintf(Arquivo_Clientes, "Endereco:  %s\n", Clientes_Var[contador].Endereco);
    fprintf(Arquivo_Clientes, "Codigo de Cliente:  %d\n\n", Clientes_Var[contador].Codigo_de_Cliente);
  }

  // Fecha o arquivo
  fclose(Arquivo_Clientes);
}

// Função que converte uma string para o formato de capitalização mista
void string_maiuscula_minuscula(char *str) {
  int i;
  // pega a primeira letra de qualquer nome e transforma em maiuscula obrigatoriamente maiuscula
  str[0] = toupper(str[0]);
  for (i = 1; str[i] != '\0'; i++)  {

     // Se o caractere passado for um espaço
    if (isspace(str[i - 1])) {                         
      str[i] = toupper(str[i]); // Transforma a letra na posição i em maiúscula
    }
     // se for uma letra qualquer
    else {                          
      str[i] = tolower(str[i]); // Transforma a letra na posição i em minúscula
    }
  }
}

// Função de ordenação insertionSort
void insertionSort(Clientes *Clientes_Var, int *Quantidade_Clientes)
{
  int i, j;
  // cria a variavel que vai servir de parametro na verificação abaixo
  Clientes key;

  // começa um for que percorre todos os clientes exitentes
  // começa em 1, pois necessita de um mais cliente a esquerda (que no caso e 0), para se efutar a comparação
  for (i = 1; i < *Quantidade_Clientes; i++)
  {
    key = Clientes_Var[i];
    j = i - 1;

    // Comparação completa dos nomes usando strcmp, verificando se Key.Nome tem letras "menores" que Clientes_Var[j].Nome
    while (j >= 0 && strcmp(Clientes_Var[j].Nome, key.Nome) > 0)  {
      // sobrescreve o conteudo do vetor na posição mais a direita de j, pelo conteudo do vetor na posição j
      // lembrando que se o loop for verdadeiro apenas 1 vez, a posição j + 1 = i
      Clientes_Var[j + 1] = Clientes_Var[j];
      // decrementa 1 em j para continuar a verificação com na posição ainda mais a esquerda
      j--;
    }
    // sobrescreve o conteudo do vetor na posição mais a direita de j + 1, pela key
    // resaltando que soma-se +1 a j, pois ao final do loop se decrementa 1 de j
    Clientes_Var[j + 1] = key;
  }
}
