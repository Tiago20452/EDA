#include "mobilidade.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Criar nova Mobilidade
Mobilidade* criarmobilidade(Mobilidade* inicio, int cod, char tipo[], float longi, float lat, float bat, float aut) 
{
 if(!existeMobilidade(inicio, cod))
 {Mobilidade * novo = malloc(sizeof(struct meio));
  if (novo != NULL)
  {novo->codigo = cod;
   strcpy(novo->tipo,tipo);
   novo->longitude = longi;
   novo->latitude = lat;
   novo->bateria = bat;
   novo->autonomia = aut;
   return (novo);
  } 
 } else return(inicio);
}

// Existe Mobilidade?
int existeMobilidade(Mobilidade* inicio, int cod)
{while(inicio!=NULL)
  {if (inicio->codigo == cod) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

// Remover uma Mobilidade a partir do seu codogo
Mobilidade* remover_mobilidade(Mobilidade* inicio, int cod) 
{
 Mobilidade *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual-> codigo == cod) // remove o 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->codigo!=cod)) 
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

// listar na consola o conteúdo da lista ligada de Mobilidades
void listarMobilidades(Mobilidade * inicio)
{while (inicio != NULL)
 {printf("%d %s %f %f %f %f\n",inicio->codigo, inicio->tipo, inicio->longitude, inicio->latitude, inicio->bateria, inicio->autonomia);
  inicio = inicio->seguinte;
 }
}

// Ler Mobilidades
Mobilidade * lerMobilidades()
{
    FILE* fp;
    int cod;
    char tipo[50];
    float bat, aut, longi, lat;
    Mobilidade* aux = NULL;

    fp = fopen("mobilidades.txt", "r");
    if (fp != NULL) 
    {while (!feof(fp))
     { fscanf(fp, "%d;%[^\n]s;%f;%f;%f;%f\n", &cod, tipo, &longi, &lat, &bat, &aut);
       aux = criarmobilidade(aux, cod, tipo, longi, lat, bat, aut);
     }
        fclose(fp);
    }
    return(aux);
}

//Guardar Mobilidade
int guardarMobilidade(Mobilidade* inicio)
{FILE* fp;
 fp = fopen("mobilidades.txt","w");
 if (fp!=NULL)
 {
 Mobilidade* aux = inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%s;%f;%f;%f;%f\n", aux->codigo, aux->tipo, aux->longitude, aux->latitude, aux->bateria, aux->autonomia);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

int guardarMobilidade_Bin(Mobilidade *inicio)
{
    FILE *fp;
    fp = fopen("mobilidades.bin", "wb");
    if (fp != NULL)
    {
        Mobilidade *aux = inicio;
        while (aux != NULL)
        {
            fwrite(aux, sizeof(Mobilidade), 1, fp);
            aux = aux->seguinte;
        }
        fclose(fp);
        return (1);
    }
    return (0);
}
