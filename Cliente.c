#include "cliente.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Criar novo cliente
Cliente* criar_cliente(Cliente* inicio, int NIF, int tel, char nome[], char email[], char password[]) 
{
 if(!existeCliente(inicio, NIF))
 {Cliente * novo = malloc(sizeof(struct registo));
  if (novo != NULL)
  {novo->Numero_fiscal = NIF;
   novo->telefone, tel;
    strcpy(novo->nome, nome);
    strcpy(novo->email, email);
    strcpy(novo->password, password);
    return (novo);
  } 
 } else return(inicio);
}


// Determinar existência do 'codigo' na lista ligada 'inicio'
int existeCliente(Cliente* inicio, int NIF)
{while(inicio!=NULL)
  {if (inicio->Numero_fiscal == NIF) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}


// Remover um Cliente a partir do seu NIF
Cliente* remover_cliente(Cliente* inicio, int NIF) 
{
 Cliente *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual-> Numero_fiscal == NIF) // remove o 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->Numero_fiscal!=NIF)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   free(atual);
   return(inicio);
  }
 }
}


// listar na consola o conteúdo da lista ligada
void listarClientes(Cliente * inicio)
{while (inicio != NULL)
 {printf("%d %d %s %s %s\n",inicio->Numero_fiscal, inicio->telefone, inicio->nome, inicio->email, inicio ->password);
  inicio = inicio->seguinte;
 }
}


// Ler clientes
Cliente* lerClientes()
{
    FILE* fp;
    int NIF, telefone;
    char nome[50], email[50], password[20];
    Cliente* aux = NULL;

    fp = fopen("clientes.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d;%d;%[^,],%[^,],%[^\n]\n", &NIF, &telefone, nome, email, password) == 5) {
            aux = criar_cliente(aux, NIF, telefone, nome, email, password);
        }
        fclose(fp);
    }

    return(aux);
}


// Guarda os Clientes num ficheiro txt
int guardarCliente(Cliente* inicio)
{  FILE* fp;
 fp = fopen("clientes.txt","w");
 if (fp!=NULL)
    {
        Cliente* aux = inicio;
         while (aux != NULL)
            {
                fprintf(fp,"%d;%d;%s;%s;%s\n", aux->Numero_fiscal, aux->telefone, aux->nome, aux->email, aux->password);
                aux = aux->seguinte;
            }
                fclose(fp);
        return(1);
    }
 else return(0);
}


Cliente* loginCliente(Cliente *inicio, int NIF)
{
  while (inicio != NULL)
  {
    if (inicio->Numero_fiscal, NIF == 0)
     {
      return (inicio);
     }
    inicio = inicio->seguinte;
  }
    return 0;
}
