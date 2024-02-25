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
    if (strstr(linha, "Dados dos clientes:")) { //Vai ler o arquivo linha por linha e usando a função strstr para buscar a string dentro de cada linha.
        //Se apareceu a string "Dados dos clientes" se sim, a cada vez que aparecer,o contador Quantidade_Clientes eh incrementado.
      Quantidade_Clientes++;
    }
  }
  fclose(Arquivo_Clientes); //fecha o arquivo
  return Quantidade_Clientes; //retorna quantas vezes "Dados de clientes" apareceu
}

void Ler_Dados(Clientes *Clientes_Var, int Quantidade_Clientes){ //criacao da função ler dados dos clientes
  int contador; //criacao de um contador, para determinar quantas vezes o loop deve acontecer
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt"); //abre o arquivo para para em modo leitura
  if (Arquivo_Clientes == NULL) { //verifica se o arquivo foi aberto corretamente, se nao, aparece uma mensagem de erro na tela e o programa eh encerrado
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  for (contador = 0; contador < Quantidade_Clientes; contador++) { //Enquanto o loop acontecer a funcao fscanf vai ser usada
    fscanf(Arquivo_Clientes, "Dados dos clientes:\nNome: %[^\n]\nEndereco: %[^\n]\nCodigo de Cliente: %d\n\n", Clientes_Var[contador].Nome, Clientes_Var[contador].Endereco, &Clientes_Var[contador].Codigo_de_Cliente); //Usa fscanf para ler os dados do cliente do arquivo.
  }
  fclose(Arquivo_Clientes); //fecha o arquivo
}

void Escrever_dados(Clientes *Clientes_Var, int Quantidade_Clientes){ //criação de uma função para colocar os dados dos clientes no arquivo txt
  int contador; //criancao de uma variavel inteira 
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "wt"); //abertura de um arquivo em modo de escrita
  if (Arquivo_Clientes == NULL)  { //Verifica se o arquivo foi aberto corretamente, se nao, aparece uma mensagem de erro na tela e o programa eh encerrado
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  for (contador = 0; contador < Quantidade_Clientes; contador++)  { //criacao de um loop que vai cadatrar os dados dos clientes no arquivo de texto, até o conatador for Quantidade_Clientes-1
    fprintf(Arquivo_Clientes, "Dados dos clientes:\n")
    fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador].Nome);
    fprintf(Arquivo_Clientes, "Endereco:  %s\n", Clientes_Var[contador].Endereco);
    fprintf(Arquivo_Clientes, "Codigo de Cliente:  %d\n\n", Clientes_Var[contador].Codigo_de_Cliente);
  }
  fclose(Arquivo_Clientes); //Fecha o arquivo de texto.
}

void string_maiuscula_minuscula(char *Nome){ //Criacao de uma funcao para mudar a primeira letra do 
  int Contador; //Criacao de uma variavel para ser utilizada no loop.
  Nome[0] = toupper(Nome[0]);  //Converte o primeiro caractere da string para maiúscula
  for (Contador = 1; Nome[Contador] != '\0'; Contador++)  { //Um loop eh inciado ele vai percorrer a string a partir do segundo caractere (Contador = 1) até encontrar o caractere nulo que indica o fim da string ('\0').
    if (isspace(Nome[Contador - 1]))  { //Verifica se o caractere anterior (Nome[Contador - 1]) é um espaço em branco. Se for, converte o caractere atual para maiúscula usando toupper.
      Nome[Contador] = toupper(Nome[Contador]);
    } else  {
      Nome[Contador] = tolower(Nome[Contador]); // se nao converte para minúscula usando tolower.
    }
  }
}

Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes){
  int i, j; //Criacao de duas variaveis inteiras, para controlar um loop.
  Clientes key; //Uma estrutura temporária para armazenar o cliente atual durante a ordenação.

  for (i = 1; i < Quantidade_Clientes; i++)  { //O loop  começa a partir do segundo elemento (índice 1)  evai percorrer até o último elemento do array.
    key = Clientes_Var[i]; //Armazena o cliente atual em key.
    j = i - 1; //Inicializa j com o índice anterior ao cliente atual.

   while (j >= 0 && strcmp(Clientes_Var[j].Nome, key.Nome) > 0){ //Percorre a string Nome e enquanto j é maior ou igual a 0 e o nome do cliente em Clientes_Var[j] é maior que o nome em key vai mover o cliente em Clientes_Var[j] para a próxima posição (Clientes_Var[j + 1]).
      Clientes_Var[j + 1] = Clientes_Var[j];
      j--; //Decrementa j
    }
    Clientes_Var[j + 1] = key; //Insere o cliente armazenado em key na posição correta no array.
  }

  return Clientes_Var; //Retorna o ponteiro para o array Clientes_Var após a ordenação.
}
