#include "cliente.h"

int Contador_Clientes(){ //funcao para contar o número de clientes há no arquivo:
  char linha[200];  // essa variavel é usada para armazenar temporariamente cada linha lida do arquivo "Clientes.txt"
  int Quantidade_Clientes = 0;
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt"); //abre o arquivo txt para leitura
  if (Arquivo_Clientes == NULL) { //verifica se o arquivo foi aberto corretamente, se nao, aparece uma mensagem de erro na tela e o programa e encerrado
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  while (fgets(linha, 200, Arquivo_Clientes) != NULL) { //esse loop e feito para ler uma linha do arquivo e armazená-la na variavel linha.
    if (strstr(linha, "Dados dos clientes:")) { // Verifica se há na linha a string "Dados dos clientes:".
      //Se a condição for verdadeira, quer dizer que há mais um cliente, então encrementa +1 na quantidade de clientes.
      Quantidade_Clientes++;
    }
  }
  fclose(Arquivo_Clientes); //fecha o arquivo
  return Quantidade_Clientes; //retorna a quantidade de clientes que há no arquivo
}

void Ler_Dados(Clientes *Clientes_Var, int Quantidade_Clientes){ //criação da função ler dados dos clientes
  int contador; //criacao de um contador, para determinar quantas vezes o loop deve acontecer
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt"); //abre o arquivo para para em modo leitura
  if (Arquivo_Clientes == NULL) { //verifica se o arquivo foi aberto corretamente, se nao, aparece uma mensagem de erro na tela e o programa e encerrado
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  for (contador = 0; contador < Quantidade_Clientes; contador++) { // percorre todos os clientes do arquivo
    //Usa fscanf para ler os dados dos cliente no arquivo.
    fscanf(Arquivo_Clientes, "Dados dos clientes:\nNome: %[^\n]\nEndereco: %[^\n]\nCodigo de Cliente: %lli\n\n", Clientes_Var[contador].Nome, Clientes_Var[contador].Endereco, &Clientes_Var[contador].Codigo_de_Cliente);
  }
  fclose(Arquivo_Clientes); //fecha o arquivo
}

void Escrever_dados(Clientes *Clientes_Var, int Quantidade_Clientes){ //criação de uma função para colocar os dados dos clientes no arquivo txt
  int contador; //crianção de um contador
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "wt"); //abertura de um arquivo em modo de escrita
  if (Arquivo_Clientes == NULL)  { //Verifica se o arquivo foi aberto corretamente, se nao, aparece uma mensagem de erro na tela e o programa e encerrado
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  for (contador = 0; contador < Quantidade_Clientes; contador++)  { //criacao de um loop que vai cadatrar os dados de todos os clientes no arquivo de texto
    fprintf(Arquivo_Clientes, "Dados dos clientes:\n");
    fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador].Nome);
    fprintf(Arquivo_Clientes, "Endereco:  %s\n", Clientes_Var[contador].Endereco);
    fprintf(Arquivo_Clientes, "Codigo de Cliente:  %lli\n\n", Clientes_Var[contador].Codigo_de_Cliente);
  }
  fclose(Arquivo_Clientes); //Fecha o arquivo de texto.
}

void string_maiuscula_minuscula(char *Nome){ //Criacao de uma funcao para mudar a primeira letra do 
  int Contador; //Criacao de uma variavel para ser utilizada no loop.
  Nome[0] = toupper(Nome[0]);  //Converte o primeiro caractere da string para maiúscula
  for (Contador = 1; Nome[Contador] != '\0'; Contador++)  { //Um loop eh inciado ele vai percorrer a string a partir do segundo caractere (Contador = 1) até encontrar o caractere nulo que indica o fim da string ('\0').
    if (isspace(Nome[Contador - 1]))  { //Verifica se o caractere anterior (Nome[Contador - 1]) é um espaço em branco. Se for, converte o caractere atual para maiúscula usando toupper.
      Nome[Contador] = toupper(Nome[Contador]);
    } else  { // se nao converte para minúscula usando tolower.
      Nome[Contador] = tolower(Nome[Contador]); 
    }
  }
}

Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes){
  int count1, count2; //Criacao de duas variaveis inteiras, para controlar um loop.
  Clientes cliente_atual; //Uma estrutura temporária para armazenar o cliente atual durante a ordenação.

  for (count1 = 1; count1 < Quantidade_Clientes; count1++)  { //O loop  começa a partir do segundo elemento (índice 1)  e vai percorrer até o último elemento do array.
    cliente_atual = Clientes_Var[count1]; //Armazena o cliente atual em key.
    count2 = count1 - 1; //Inicializa j com o índice anterior ao cliente atual.

   while (count2 >= 0 && strcmp(Clientes_Var[count2].Nome, cliente_atual.Nome) > 0){ //Percorre a string Nome e enquanto j é maior ou igual a 0 e o nome do cliente em Clientes_Var[count2] é maior que o nome em cliente_atual vai mover o cliente em Clientes_Var[count2] para a próxima posição (Clientes_Var[count2+ 1]).
      Clientes_Var[count2+ 1] = Clientes_Var[count2];
      count2--; //Decrementa count2.
    }
    Clientes_Var[count2 + 1] = cliente_atual; //Insere o cliente armazenado em cliente_atual na posição correta no array.
  }

  return Clientes_Var; //Retorna o ponteiro para o array Clientes_Var após a ordenação.
}