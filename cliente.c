#include "cliente.h"

int Contador_Clientes(){
  char linha[200];
  int Quantidade_Clientes = 0;
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt");
  if (Arquivo_Clientes == NULL) {
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  while (fgets(linha, 200, Arquivo_Clientes) != NULL) {
    if (strstr(linha, "Dados dos clientes:")) {
      Quantidade_Clientes++;
    }
  }
  fclose(Arquivo_Clientes);
  return Quantidade_Clientes;
}

void Ler_Dados(Clientes *Clientes_Var, int Quantidade_Clientes){
  int contador;
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt");
  if (Arquivo_Clientes == NULL) {
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  for (contador = 0; contador < Quantidade_Clientes; contador++) {
    fscanf(Arquivo_Clientes, "Dados dos clientes:\nNome: %[^\n]\nEndereco: %[^\n]\nCodigo de Cliente: %d\n\n", Clientes_Var[contador].Nome, Clientes_Var[contador].Endereco, &Clientes_Var[contador].Codigo_de_Cliente);
  }
  fclose(Arquivo_Clientes);
}

void Escrever_dados(Clientes *Clientes_Var, int Quantidade_Clientes){
  int contador;
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "wt");
  if (Arquivo_Clientes == NULL)  {
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  for (contador = 0; contador < Quantidade_Clientes; contador++)  {
    fprintf(Arquivo_Clientes, "Dados dos clientes:\n");
    fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador].Nome);
    fprintf(Arquivo_Clientes, "Endereco:  %s\n", Clientes_Var[contador].Endereco);
    fprintf(Arquivo_Clientes, "Codigo de Cliente:  %d\n\n", Clientes_Var[contador].Codigo_de_Cliente);
  }
  fclose(Arquivo_Clientes);
}

void string_maiuscula_minuscula(char *Nome){
  int Contador;
  Nome[0] = toupper(Nome[0]);
  for (Contador = 1; Nome[Contador] != '\0'; Contador++)  {
    if (isspace(Nome[Contador - 1]))  {
      Nome[Contador] = toupper(Nome[Contador]);
    } else  {
      Nome[Contador] = tolower(Nome[Contador]);
    }
  }
}

Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes){
  int i, j;
  Clientes key;

  for (i = 1; i < Quantidade_Clientes; i++)  {
    key = Clientes_Var[i];
    j = i - 1;

    while (j >= 0 && strcmp(Clientes_Var[j].Nome, key.Nome) > 0){
      Clientes_Var[j + 1] = Clientes_Var[j];
      j--;
    }
    Clientes_Var[j + 1] = key;
  }

  return Clientes_Var;
}
