#include "aluguer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



Aluguer* novo_aluguer(Aluguer* inicio, char email[], int cod, char data[]) 
{
  
  Aluguer * novo = malloc(sizeof(struct aluguer));
  if (novo != NULL)
  {
    strcpy(novo->email, email);
    novo->codigo = cod;
    strcpy(novo->data_atual, data);

   return (novo);
  } 
} 

int guardarAluguer(Aluguer* inicio)
{
 FILE* fp;
 fp = fopen("alugueres.txt","w");
 if (fp!=NULL)
 {
 Aluguer* aux = inicio;
 
 while (aux != NULL)
 {
  
  fprintf(fp,"Email:%s;Codigo:%d;Data:%s\n", aux->email, aux->codigo, aux->data_atual);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

void listarAluguer(Aluguer * inicio)

{
  while (inicio != NULL)
  {
  printf("Email: %s; Codigo: %d; Data: %s\n",inicio->email, inicio->codigo, inicio->data_atual);
  inicio = inicio->seguinte;
  }
}


