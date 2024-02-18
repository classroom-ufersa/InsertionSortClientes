# Problemática  
Implementar um algoritmo que manipula um tipo estruturado **Clientes** e mantém os clientes ordenados por código em um arquivo usando **insertion sort**.
## Desenvolvedores
- [Daniel Neres ](https://github.com/DanielNeres)
- [Francisco Porfirio ](https://github.com/Porfirio24)
- [Letícia Vieira Gonçalves](https://github.com/LeticiaVieirg)
- [Maria Isabelly de Lima Sousa](https://github.com/isabellymrl)


# Tabela de conteudo
- [Problemática](#problemática)
- [Compilação e execução](#compilação-e-execução)
- [Insertion Sort](#strings-com-insertion-sort)
- [Implementação](#implementação)
- [Análise Big-O](#análise-de-complexidade-do-tempo)
- [Vantagens e Desvantagens](#vantagens-e-desvantagens)

# Compilação e execução
## C
```shell
git clone https://github.com/classroom-ufersa/InsertionSortClientes.git
cd strings_com_insertion_sort
cd c
gcc -o main main.c
./main
```

# Strings com insertion sort
**Ordenação de strings com Inserion Sort**
O Insertion Sort, ou "Ordenação por Inserção", é um algoritmo de ordenação por inserção que realiza iteração pelos índices do array.

## Como funciona o Insertion Sort

Imagine uma professora organizando alunos em uma fila por idade, do mais novo para o mais velho. Ela começa com o primeiro aluno (primeira posição do vetor) e considera ele como ordenado. Em seguida, ela pega cada aluno subsequente (segunda posição em diante) e o coloca na posição correta em relação aos alunos anteriores, movendo-os conforme necessário. Esse processo continua até que todos os alunos estejam ordenados por idade, do mais novo para o mais velho. 

![Insertion Sort](https://markbowman.org/LCC/SortInsertion.gif)
