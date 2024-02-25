#ifndef CLIENTE_H
#define CLIENTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct clientes {
    char Nome[80];
    char Endereco[80];
    long long int Codigo_de_Cliente;
} Clientes; /*Cria Tipo estruturado Clientes e preenche seu campo
**Recebe: Informações dos clientes (Nome, Endereço e codigo do cliente)
**Retorna: Nada, ele apenas define uma estrutura de dados*/

int Contador_Clientes();/*Função responsável por contar o numero de Clientes no arquivo "Clientes.txt"
**Recebe:nenhum parâmetro
**Retorna: Um inteiro representando a quantidade de clintes no arquivo*/

void Ler_Dados(Clientes *Clientes_Var, int Quantidade_Clientes);/*Função para ler dados dos clientes no arquivo "clintes.txt" e armazena em uma estrutura de dados
**Recebe: Um ponteiro para uma estrutura do tipo Clientes (Clientes_Var) e um inteiro representando a quantidade de clientes
**Retorna:Nada, pois os dados são armazenados diretamente na estrutura passada por referência*/

void Escrever_dados(Clientes *Clientes_Var, int Quantidade_Clientes);/*Função para escrever os dados dos clientes no arquivo "Clientes.txt"
**Recebe:Um ponteiro para uma estrutura do tipo Clientes (Clientes_Var) e um inteiro representando a quantidade de clientes
**Retorna: Nada, pois os dados são escritos diretamente no arquivo*/

void string_maiuscula_minuscula(char *str);/*Função para converter a primeira letra de cada palavra em uma string para maiúscula e as demais letras para minúscula
**Recebe: Um ponteiro para uma string contendo o nome
**Retorna: Nada, pois a conversão é feita diretamente na string passada por referência*/

Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes);/*Função que implementa o algoritmo de ordenação Insertion Sort para ordenar os clientes por nome
**Recebe: Um ponteiro para um array de estruturas do tipo Clientes (Clientes_Var) e um inteiro representando a quantidade de clientes
**Retorna: Um ponteiro para o array de clientes após a ordenação*/

#endif /* CLIENTE_H */
