#include "Aluguer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Aluguer* novo_aluguer(Aluguer* inicio, int cod, char data[]) 
{
 Aluguer * novo = malloc(sizeof(struct aluguer));
  if (novo != NULL)
  {novo->codigo = cod;
    strcpy(novo->data, data);
    
    return (novo);
  } 
} 

int guardarAluguer(Aluguer* inicio)
{FILE* fp;
 fp = fopen("alugueres.txt","w");
 if (fp!=NULL)
 {
 Aluguer* aux = inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%s\n", aux->codigo, aux->data);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

// listar na consola o conteúdo da lista ligada
void listarAluguer(Aluguer * inicio)
{while (inicio != NULL)
 {printf("%d %d %s %s %s\n",inicio->codigo, inicio->data);
  inicio = inicio->seguinte;
 }
}
