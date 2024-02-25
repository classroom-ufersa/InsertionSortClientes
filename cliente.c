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
  int count1, count2; //Criacao de duas variaveis inteiras, para controlar um loop.
  Clientes cliente_atual; //Uma estrutura temporária para armazenar o cliente atual durante a ordenação.
// começa um for que percorre todos os clientes exitentes
  // começa em 1, pois necessita de um mais cliente a esquerda (que no caso e 0), para se efutar a comparação 
  for (count1 = 1; count1 < Quantidade_Clientes; count1++)  { 
    cliente_atual = Clientes_Var[count1]; //Armazena o cliente atual em cliente_atual.
    count2 = count1 - 1; //Inicializa count2 com o índice anterior ao cliente atual.

   while (count2 >= 0 && strcmp(Clientes_Var[count2].Nome, cliente_atual.Nome) > 0){ 
// Comparação completa dos nomes usando strcmp, verificando se cliente_atual.Nome tem letras "menores" que Clientes_Var[count2].Nome

      Clientes_Var[count2+ 1] = Clientes_Var[count2];
      // decrementa 1 em count2 para continuar a verificação com na posição ainda mais a esquerda
      count2--; 
    }
    Clientes_Var[count2 + 1] = cliente_atual; // sobrescreve o conteudo do vetor na posição mais a direita de count2 + 1, pelo cliente_atual
     // resaltando que soma-se +1 a count2, pois ao final do loop se decrementa 1 de count2
  }

  return Clientes_Var; //Retorna o ponteiro para o array Clientes_Var após a ordenação.
}
