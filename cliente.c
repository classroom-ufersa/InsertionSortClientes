#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
  
//Definicao da struct clientes 
struct clientes{
    char Nome[80];
    char Endereco[80];
    int Codigo_de_Cliente;
};

//Criacao da funcao Escrever_dados, que vai pedir os dados do cliente ao usuario.
void Escrever_dados(){

    int Quantidade_Clientes; int contador;
    printf("Digite a Quantidade de Clientes:\t"); //Pergunta ao usuario a quantidade de clientes que ele quer cadastrar os dados.
    scanf("%d", &Quantidade_Clientes);
    Clientes *Clientes_Var = (Clientes *)malloc(sizeof(Clientes) * Quantidade_Clientes); //Criacao do malloc para guardar um espaço na memoria para a quantidade de clientes.
  
    for (contador = 0; contador < Quantidade_Clientes; contador++) //Criacao do for para pedir os dados do cliente ate que quantidade de clientes que usuario digitou chegue no limite imposto no loop.
    {

        printf("Digite o nome do cliente:\n");
        scanf(" %[^\n]", Clientes_Var[contador].Nome);

        printf("Digite o endereco do cliente:\n");
        scanf(" %[^\n]", Clientes_Var[contador].Endereco);

        printf("Digite o codigo do cliente:\n");
        scanf("%d", &Clientes_Var[contador].Codigo_de_Cliente);

        void insertionSort(Clientes_Var, contador); //Chama a funcao insertionSort para que a cada cliente cadastrado, os nomes sejam colocados em ordem alfabetica.
    }

    FILE *Arquivo_Clientes = fopen("Clientes.txt", "wr"); //Criacao do FILE para manipular um arquivo txt e armazenar nesse arquivo os dados do cliente.
    for (contador = 0; contador < Quantidade_Clientes; contador++) //Criacao de um for para amazenar os dados do cliente em um arquivo txt de acordo com a quantidade de clientes que o usuario vai cadastrar.
    {
        
        fprintf(Arquivo_Clientes, "Dados dos clientes %d:\n", contador + 1);
        fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador].Nome);
        fprintf(Arquivo_Clientes, "Endereco:  %s\n", Clientes_Var[contador].Endereco);
        fprintf(Arquivo_Clientes, "Codigo de Cliente:  %d\n", Clientes_Var[contador].Codigo_de_Cliente);
    }
    fclose(Arquivo_Clientes); //Depois de terminar de usar o arquivo, o arquivo eh fechado usando fclose, liberando assim os recursos associados a ele.

}
 //Criacao da funcao insertionSort para ordenacao de elementos, nesse caso dos nomes dos clientes em ordem alfabetica.
void insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes)
{
    int Contador1, Contador2;
    char key;
    for (Contador1 = 1; Contador1 < Quantidade_Clientes; Contador1++) {
        key = Clientes_Var[Contador1].Nome[0];
        Contador2 = Contador1 - 1;

        while (Contador2 >= 0 && Clientes_Var[Contador2].Nome[0] > key) {
            Clientes_Var[Contador2 + 1] = Clientes_Var[Contador2];
            Contador2 = Contador2 - 1;
        }
        Clientes_Var[Contador2 + 1] = Clientes_Var[Contador1];
    }
}
