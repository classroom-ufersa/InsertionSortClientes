#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
  
//Definicao da struct clientes 
struct clientes{
    char nome[80];
    char endereco[80];
    int codigo_cliente;
};

//Criacao da funcao Escrever_dados, que vai pedir os dados do cliente ao usuario.
void escrever_dados(){

    int quantidade_clientes; int contador;
    printf("===Cadastro de clientes===");

    //Pergunta ao usuario a quantidade de clientes que ele quer cadastrar os dados.
    printf("Digite a Quantidade de clientes que deseja cadastrar:\t"); 
    scanf("%d", &quantidade_clientes);

    //Criacao do malloc para guardar um espaço na memoria para a quantidade de clientes
    Clientes *clientes_var = (Clientes*)malloc(sizeof(Clientes) *quantidade_clientes);  

    //Criacao do for para pedir os dados do cliente ate que quantidade de clientes que usuario digitou chegue no limite imposto no loop.
    for (contador = 0; contador < quantidade_clientes; contador++) {

        printf("Digite o nome do cliente:\n");
        scanf(" %[^\n]", clientes_var[contador].nome);

        printf("Digite o endereco do cliente:\n");
        scanf(" %[^\n]", clientes_var[contador].endereco);

        printf("Digite o codigo do cliente:\n");
        scanf("%d", &clientes_var[contador].codigo_cliente);

      //Chama a funcao insertionSort para que a cada cliente cadastrado, os nomes sejam colocados em ordem alfabetica.
        void insertionSort(clientes_var, contador); 
    }

   //Criacao do FILE para manipular um arquivo txt e armazenar nesse arquivo os dados do cliente.
    FILE *arquivo_clientes = fopen("clientes.txt", "wr");

   //Criacao de um for para amazenar os dados do cliente em um arquivo txt de acordo com a quantidade de clientes que o usuario vai cadastrar.
    for (contador = 0; contador < quantidade_clientes; contador++){
        
        fprintf(arquivo_clientes, "Dados dos clientes %d:\n", contador + 1);
        fprintf(arquivo_clientes, "Nome:  %s\n", clientes_var[contador].nome);
        fprintf(arquivo_clientes, "Endereco:  %s\n", clientes_var[contador].endereco);
        fprintf(arquivo_clientes, "Codigo de Cliente:  %d\n", clientes_var[contador].codigo_cliente);
    }

    //Depois de terminar de usar o arquivo, o arquivo eh fechado usando fclose, liberando assim os recursos associados a ele.
    fclose(arquivo_clientes);
}

 //Criacao da funcao insertionSort para ordenacao de elementos, nesse caso dos nomes dos clientes em ordem alfabetica.
void insertionSort(Clientes *clientes_var, int quantidade_clientes){

    int contador1, contador2;
    char key;
    for (contador1 = 1; contador1 < quantidade_clientes; contador1++) {
        key = clientes_var[contador1].nome[0];
        contador2 = contador1 - 1;

        while (contador2 >= 0 && clientes_var[contador2].nome[0] > key) {
            clientes_var[contador2 + 1] = clientes_var[contador2];
            contador2 = contador2 - 1;
        }
        clientes_var[contador2 + 1] = clientes_var[contador1];
    }
}
