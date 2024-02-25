#include "cliente.h"

int Contador_Clientes(){ //funcao para contar o número de vezes que a string "Dados dos clientes:
  char linha[200];  // essa variavel é usada para armazenar temporariamente cada linha lida do arquivo "Clientes.txt"
  int Quantidade_Clientes = 0; //inicializa a variavel com 0
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt"); //abre um aqruivo txt para leitura
  if (Arquivo_Clientes == NULL) { //verifica se o arquivo foi aberto corretamente, se nao, aparece uma mensagem de erro na tela e o programa eh encerrado
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  while (fgets(linha, 200, Arquivo_Clientes) != NULL) { //esse loop eh feito para ler uma linha do arquivo e armazená-la na variavel linha.
    if (strstr(linha, "Dados dos clientes:")) { //lenr o arquivo linha por linha e usando a função strstr para buscar a string dentro de cada linha
        // se apareceu a string "Dados dos clientes" se sim, a cada vez que aparecer,o contador Quantidade_Clientes eh incrementado
      Quantidade_Clientes++;
    }
  }
  fclose(Arquivo_Clientes); //fecha o arquivo
  return Quantidade_Clientes; //retorna quantas vezes "Dados de clientes" apareceu
}

void Ler_Dados(Clientes *Clientes_Var, int Quantidade_Clientes){ //criacao da função ler dados dos clientes
  int contador; //criacao de um contador, para determinar quantas vezes o loop deve acontecer
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

void Escrever_dados(Clientes *Clientes_Var, int Quantidade_Clientes){ //criação de uma função para colocar os dados dos clientes no arquivo txt
  int contador; //criancao de uma variavel inteira 
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "wt");
  if (Arquivo_Clientes == NULL)  {
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  for (contador = 0; contador < Quantidade_Clientes; contador++)  { //criacao de um loop que vai cadatrar os dados dos clientes no arquivo de texto, até Quantidade_Clientes-1
    fprintf(Arquivo_Clientes, "Dados dos clientes:\n");
    fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador].Nome);
    fprintf(Arquivo_Clientes, "Endereco:  %s\n", Clientes_Var[contador].Endereco);
    fprintf(Arquivo_Clientes, "Codigo de Cliente:  %d\n\n", Clientes_Var[contador].Codigo_de_Cliente);
  }
  fclose(Arquivo_Clientes); //fecha o arquivo de texto
}

void string_maiuscula_minuscula(char *Nome){ //criacao de uma funcao para mudar a primeira letra do 
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
