# Problemática  
- [x] Implementar um algoritmo que manipula um tipo estruturado **Clientes** e mantém os clientes ordenados por código em um arquivo usando **Insertion Sort**.

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
> 
> [Análise da Complexidade do Espaço](#análise-da-complexidade-do-espaço) 

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

# Strings com Insertion Sort
**Ordenação de strings com Inserion Sort**
- [x] O Insertion Sort, ou "Ordenação por Inserção", é um dos algoritmos de classificação por comparação usados ​​para classificar elementos, iterando um elemento por vez e colocando o elemento em sua posição correta. O algoritmo de classificação por inserção garante que os primeiros k elementos sejam classificados após a k-ésima iteração.
- [x] Implementa-se um loop que se repete sobre um array, iniciando a partir do segundo elemento (índice 1) e percorre todos os elementos até o final. Dentro deste loop, existe outro loop while que compara o elemento atual com o elemento anterior e, caso o elemento atual for menor que o anterior, as posições são trocadas. Diante disso, o loop while continua até que o elemento atual esteja na posição correta.

**Propriedades do Insertion Sort**
- Online: Classificar os elementos à medida que os recebe. Caso seja acrescentado mais alguns elementos às listas, é feito apenas a iteração nos elementos recém-adicionados.
- No lugar: O espaço é constante e não requer espaço extra. Este algoritmo classifica os elementos no lugar.
- Estável: Não troca os elementos se seus valores forem iguais. 
- Adaptável: A algoritmo de classificação é adaptativo se levar menos tempo, se os elementos de entrada ou subconjunto de elementos já estiverem classificados. Sendo assim, o tempo de execução do melhor caso é O(N) e o pior tempo de execução é O(N^2). A classificação por inserção é um dos algoritmos de classificação adaptativa.

***

## Como funciona o Insertion Sort
- [x] Imagine uma professora organizando alunos em uma fila por idade, do mais novo para o mais velho. Ela começa com o primeiro aluno (primeira posição do vetor) e considera ele como ordenado. Em seguida, ela pega cada aluno subsequente (segunda posição em diante) e o coloca na posição correta em relação aos alunos anteriores, movendo-os conforme necessário. Esse processo continua até que todos os alunos estejam ordenados por idade, do mais novo para o mais velho.
Suponha que temos a seguinte fila de alunos desorganizada, representada por um vetor de idades: [5, 2, 4, 6, 1, 3].

### Inicialização (resultado inicial):
- [x] Fila inicial: [5, 2, 4, 6, 1, 3].

### Implementação (implementação do algoritmo):
- [x] A professora considera o primeiro aluno (idade 5) como ordenado.
Pega o segundo aluno (idade 2) e o coloca na posição correta em relação ao primeiro aluno.
- [x] Fila: [2, 5, 4, 6, 1, 3].

### Ordenação:
- [x] O terceiro aluno (idade 4) é comparado com os alunos anteriores e inserido na posição correta.
- [x] Fila: [2, 4, 5, 6, 1, 3].

### Resultados intermediários:
- [x] O quarto aluno (idade 6) é comparado com os alunos anteriores e não precisa ser movido.
- [x] Fila: [2, 4, 5, 6, 1, 3].

### Resultado final:
- [x] O quinto aluno (idade 1) é comparado com os alunos anteriores e movido para a posição correta.
- [x] Fila: [1, 2, 4, 5, 6, 3].

### Conclusão:
- [x] O sexto aluno (idade 3) é comparado com os alunos anteriores e movido para a posição correta.
- [x] Fila final ordenada: [1, 2, 3, 4, 5, 6].

![Insertion Sort](https://markbowman.org/LCC/SortInsertion.gif)

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

**Pior Caso**
Pior Caso Complexidade: T(n) = O(n²). Classificar um array em ordem cresccente quando ele está em ordem decrescente é o pior cenário. Indica que o tempo de execução cresce quadraticamente conforme o tamanho da entrada aumenta.
```latex
   T(n) = c1 + (c2+c3+c4+c8)(n-1) + n(n-1)(c5+c6+c7)

    T(n) = c + b(n-1) + n(n-1)*a

    T(n) = c + bn - b + an² - an

    T(n) = bn + an² - an

    T(n) = n + n² - n

    T(n) = n²

    T(n) = O(n²)
 ```

**Caso Médio**
Caso Médio Complexidade: T(n)= O(n²). Acontece quando os elementos de um array ocorrem em ordem confusa, que não é crescente nem decrescente. 

**Melhor Caso**
Melhor Caso Complexidade: T(n) = O(n). Existe apenas n número de comparações, neste caso, complexa realidade é linear. Ocorre quando a entrada está parcialmente ordenada, resultando em um crescimento linear no tempo de execução em relação ao tamanho da entrada.

# Análise da Complexidade do Espaço
```shell
struct clientes{ //Espaco constante
  char Nome[80]; // 80 bytes de espaço - Cada caractere oculpa 1 byte
  char Endereco[80]; //80 bytes
  int Codigo_de_Cliente; // 4 bytes - inteiro
};

void Escrever_dados() { //Espaço constante - função
  int Quantidade_Clientes; //4 bytes
  int contador; // 4 bytes

 Clientes *Clientes_Var = (Clientes *)malloc(sizeof(Clientes) * Quantidade_Clientes); 
 O(Quantidade_Clientes).
  
FILE *Arquivo_Clientes = fopen("Clientes.txt", "w+"); //Espaço constante - operação de abertura de arquivo

LOOP for (contador = 0; contador < Quantidade_Clientes; contador++) { //O(Quantidade_Clientes)

Clientes_Var = insertionSort(Clientes_Var, Quantidade_Clientes); //oculpa um espaco constante

  fclose(Arquivo_Clientes); //Espaço constante - operação de fechamento de arquivo
  
  free(Clientes_Var); //Espaço constante - operação de liberação de memória.

void string_maiuscula_minuscula(char *str) { //Espaço constante - chamada de uma função
  int i; //4 bytes, espaco constante
//A complexidade de espaço dessa função é O(1), pois não depende do tamanho da entrada str

Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes) {
  int i, j; //duas variaveis inteiras, cada um oculpa 4 bytes, epaço constante
  // cria a variavel que vai servir de parametro na verificação abaixo
 
 Clientes key; //A variável key é uma estrutura Clientes, que ocupa um espaço fixo
// a complexidade de espaço dessa função é O(1), pois não depende do tamanho da entrada Clientes_Var ou Quantidade_Clientes.

```

Portanto, a complexidade de espaço total do código é dominada pela alocação de memória na função Escrever_dados(), resultando em O(Quantidade_Clientes) em termos de quantidades significativas de memória alocada. As demais operações ocupam um espaço constante adicional.


##
S(P)=c + Sp
