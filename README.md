# Problemática  
Implementar um algoritmo que manipula um tipo estruturado **Clientes** e mantém os clientes ordenados por código em um arquivo usando **Insertion Sort**.

## Desenvolvedores
> [Daniel Neres ](https://github.com/DanielNeres)
> 
> [Francisco Porfirio ](https://github.com/Porfirio24)
>
> [Letícia Vieira Gonçalves](https://github.com/LeticiaVieirg)
>
> [Maria Isabelly de Lima Sousa](https://github.com/isabellymrl)

## Requisitos atendidos
- [x] A cada execução do programa os dados são carregados e armazenados em um arquivo de texto.
- [x] Cada novo cliente cadastrado é inserido em ordem alfabética.
- [x] Computação do tempo de execução do processo de ordem.
- [x] Arquivo texto atualizado e mantém os nomes armazenados em ordem alfabética.
- [x] Informado a complexidade do algoritmo Insertion Sort

***

# Tabela de conteudo
> [Problemática](#problemática)
> 
> [Compilação e execução](#compilação-e-execução)
> 
> [Insertion Sort](#strings-com-insertion-sort)
> 
> [Implementação](#implementação)
> 
> [Análise Big-O](#análise-de-complexidade-do-tempo)

***

# Compilação e execução
```shell
git clone https://github.com/classroom-ufersa/InsertionSortClientes.git
cd strings_com_insertion_sort
cd c
gcc -o main main.c
./main
```
***

# Strings com insertion sort
**Ordenação de strings com Inserion Sort**
O Insertion Sort, ou "Ordenação por Inserção", é um algoritmo de ordenação por inserção que realiza iteração pelos índices do array.

***

## Como funciona o Insertion Sort
> Imagine uma professora organizando alunos em uma fila por idade, do mais novo para o mais velho. Ela começa com o primeiro aluno (primeira posição do vetor) e considera ele como ordenado. Em seguida, ela pega cada aluno subsequente (segunda posição em diante) e o coloca na posição correta em relação aos alunos anteriores, movendo-os conforme necessário. Esse processo continua até que todos os alunos estejam ordenados por idade, do mais novo para o mais velho.
> 
> ![Insertion Sort](https://markbowman.org/LCC/SortInsertion.gif)

***

# Implementação
**Insertion Sort**
```C
Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes) {
  int i, j;
  // cria a variavel que vai servir de parametro na verificação abaixo
  Clientes key;

  // começa um for que percorre todos os clientes exitentes
  // começa em 1, pois necessita de um mais cliente a esquerda (que no caso e 0), para se efutar a comparação 
  for (i = 1; i < Quantidade_Clientes; i++) {
    key = Clientes_Var[i];
    j = i - 1;

    // Comparação completa dos nomes usando strcmp, verificando se Key.Nome tem letras "menores" que Clientes_Var[j].Nome
    while (j >= 0 && strcmp(Clientes_Var[j].Nome, key.Nome) > 0) {
      // sobrescreve o conteudo do vetor na posição mais a direita de j, pelo conteudo do vetor na posição j
      // lembrando que se o loop for verdadeiro apenas 1 vez, a posição j + 1 = i
      Clientes_Var[j + 1] = Clientes_Var[j];
      // decrementa 1 em j para continuar a verificação com na posição ainda mais a esquerda
      j--;
    }
     // sobrescreve o conteudo do vetor na posição mais a direita de j + 1, pela key
     // resaltando que soma-se +1 a j, pois ao final do loop se decrementa 1 de j
    Clientes_Var[j + 1] = key;
  }
  return Clientes_Var;
}
```

***

# Análise de complexidade do tempo
## Big-O
O pior e médio caso do algoritmo de ordenação Insertion Sort é T(n) = O(n²), indicando que o tempo de execução cresce quadraticamente conforme o tamanho da entrada aumenta. O melhor caso desse algoritmo é T(n) = O(n), quando a entrada está parcialmente ordenada, resultando em um crescimento linear no tempo de execução em relação ao tamanho da entrada.
```latex
   T(n) = c1 + (c2+c3+c4+c8)(n-1) + n(n-1)(c5+c6+c7)

    T(n) = c + b(n-1) + n(n-1)*a

    T(n) = c + bn - b + an² - an

    T(n) = bn + an² - an

    T(n) = n + n² - n

    T(n) = n²

    T(n) = O(n²)
 ```
