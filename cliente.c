#include "cliente.h"

int Contador_Clientes(){ 
  char linha[200];  
  int Quantidade_Clientes = 0;
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt"); 
  if (Arquivo_Clientes == NULL) { 
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  while (fgets(linha, 200, Arquivo_Clientes) != NULL) { 
    if (strstr(linha, "Dados dos clientes:")) { 
     
      Quantidade_Clientes++;
    }
  }
  fclose(Arquivo_Clientes); 
  return Quantidade_Clientes; 
}

void Ler_Dados(Clientes *Clientes_Var, int Quantidade_Clientes){ 
  int contador; 
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "rt"); 
  if (Arquivo_Clientes == NULL) { 
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  for (contador = 0; contador < Quantidade_Clientes; contador++) { 
    fscanf(Arquivo_Clientes, "Dados dos clientes:\nNome: %[^\n]\nEndereco: %[^\n]\nCodigo de Cliente: %lli\n\n", Clientes_Var[contador].Nome, Clientes_Var[contador].Endereco, &Clientes_Var[contador].Codigo_de_Cliente);
  }
  fclose(Arquivo_Clientes); 
}

void Escrever_dados(Clientes *Clientes_Var, int Quantidade_Clientes){ 
  int contador; 
  FILE *Arquivo_Clientes = fopen("Clientes.txt", "wt"); 
  if (Arquivo_Clientes == NULL)  { 
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  for (contador = 0; contador < Quantidade_Clientes; contador++)  { 
    fprintf(Arquivo_Clientes, "Dados dos clientes:\n");
    fprintf(Arquivo_Clientes, "Nome:  %s\n", Clientes_Var[contador].Nome);
    fprintf(Arquivo_Clientes, "Endereco:  %s\n", Clientes_Var[contador].Endereco);
    fprintf(Arquivo_Clientes, "Codigo de Cliente:  %lli\n\n", Clientes_Var[contador].Codigo_de_Cliente);
  }
  fclose(Arquivo_Clientes);
}

void string_maiuscula_minuscula(char *Nome){ 
  int Contador; 
  Nome[0] = toupper(Nome[0]);  
  for (Contador = 1; Nome[Contador] != '\0'; Contador++)  { 
    if (isspace(Nome[Contador - 1]))  { 
      Nome[Contador] = toupper(Nome[Contador]);
    } else  { 
      Nome[Contador] = tolower(Nome[Contador]); 
    }
  }
}

void Tratamento_de_Dado_Nome(char *Nome){
  int Contador, Contador2; 
  for (Contador = 0; Nome[Contador] != '\0'; Contador++)  {
    if((Nome[Contador] < 65 || Nome[Contador] > 90) && (Nome[Contador] < 97 || Nome[Contador] > 122)){
       for(Contador2 = Contador;Nome[Contador2] != '\0';Contador2++){
        Nome[Contador2] = Nome[Contador2 + 1];
       }
       Contador--;
    }
  }
}

void Tratamento_de_Dado_Codigo(char *String_Codigo)
{
  int Contador, Contador2;
  for (Contador = 0; String_Codigo[Contador] != '\0'; Contador++)
  {
    if (String_Codigo[Contador] < 48 || String_Codigo[Contador] > 57)
    {
      for (Contador2 = Contador; String_Codigo[Contador2] != '\0'; Contador2++)
      {
        String_Codigo[Contador2] = String_Codigo[Contador2 + 1];
      }
      Contador--;
    }
  }
}

Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes){
  int count1, count2; 
  Clientes cliente_atual; 

  for (count1 = 1; count1 < Quantidade_Clientes; count1++)  { 
    cliente_atual = Clientes_Var[count1];
    count2 = count1 - 1; 


   while (count2 >= 0 && strcmp(Clientes_Var[count2].Nome, cliente_atual.Nome) > 0){ 
      Clientes_Var[count2+ 1] = Clientes_Var[count2];
      count2--; 
    }
    Clientes_Var[count2 + 1] = cliente_atual; 
  }

  return Clientes_Var; 
}