#include "cliente.c"

int main(){
  int permanencia, escolha;
  Clientes *Clientes_var = (Clientes*) malloc(sizeof(Clientes));

  Clientes_var = ler_arquivo(Clientes_var);

do
{
  permanencia = 0;
  printf("Caso deseje cadastrar um novo cliente digite 1\n");
  scanf("%d", escolha);
  if(escolha == 1){
  printf("Digite o nome do cliente:\n");
  scanf(" %[^\n]", Clientes_Var[contador].Nome);
  string_maiuscula_minuscula(Clientes_Var[contador].Nome);

  printf("Digite o endereco do cliente:\n");
  scanf(" %[^\n]", Clientes_Var[contador].Endereco);

  printf("Digite o codigo do cliente:\n");
  scanf("%d", &Clientes_Var[contador].Codigo_de_Cliente);

  permanencia = 1
  }
} while (permanencia == 1)

  //Chama a função Escrever_dados que foi implementada no cliente.c
  Escrever_dados(); 
  
  return 0;
}
