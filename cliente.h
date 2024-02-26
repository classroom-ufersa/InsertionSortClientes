#ifndef CLIENTE_H
#define CLIENTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Renomeação de um tipo estruturado para Clientes,
   Recebe informações dos clientes*/
typedef struct clientes {
    char Nome[80];
    char Endereco[80];
    long long int Codigo_de_Cliente;
} Clientes;

/*Função responsável por contar o numero de clientes no arquivo "Clientes.txt,
  Não recebe algum parâmetro, e retorna um inteiro representando a quantidade de clientes no arquivo*/
int Contador_Clientes();

/*Função que ler os dados dos clientes armazenadas no arquivo "Clientes.txt" e armazena em uma estrutura de dados, 
  Recebe como parâmetros um ponteiro do tipo Clientes e um inteiro que representa a quantidade de clientes*/
void Ler_Dados(Clientes *Clientes_Var, int Quantidade_Clientes);

/*Função que escreve os dados dos clientes no arquivo "Clientes.txt"
  Recebe como parâmetros um ponteiro para uma estrutura do tipo Clientes e um inteiro representando a quantidade de clientes*/
void Escrever_dados(Clientes *Clientes_Var, int Quantidade_Clientes);

/*Função que converte a primeira letra de cada palavra em uma string para maiúscula e as demais letras para minúscula,
  Recebe como parâmetro um ponteiro para uma string contendo o nome*/
void string_maiuscula_minuscula(char *str);

void Tratamento_de_Dado(char *Nome);

/*Função que implementa o algoritmo de ordenação Insertion Sort para ordenar os clientes em ordem alfabética,
  Recebe como parâmtros um ponteiro para um array de estruturas do tipo Clientes e um inteiro representando a quantidade de clientes*/
Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes);

#endif /* CLIENTE_H */
