#include "cliente.c"

int main(){
  Clientes *Clientes_var = (Clientes*) malloc(sizeof(Clientes));

  Clientes_var = ler_arquivo();
  //Chama a função Escrever_dados que foi implementada no cliente.c
  Escrever_dados(); 
  
  return 0;
}
