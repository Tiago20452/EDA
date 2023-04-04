#include "aluguer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


Aluguer* novo_aluguer(Aluguer* inicio, char email[], int cod, time_t data) 
{
 Aluguer * novo = malloc(sizeof(struct aluguer));
  if (novo != NULL)
  {
    strcpy(novo->email, email);
    novo->codigo = cod;
    time(&data);
    novo->data_aluguer = data;


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
  fprintf(fp,"%s;%d;%s\n", aux->email, aux->codigo, ctime(aux->data_aluguer));
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

void listarAluguer(Aluguer * inicio)

{while (inicio != NULL)
 {printf("%s %d\n",inicio->email, inicio->codigo, inicio->data_aluguer);
  inicio = inicio->seguinte;
 }
}


