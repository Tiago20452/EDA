#include "Mobilidade.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Criar nova Mobilidade
Mobilidade* criar_mobilidade(Mobilidade* inicio, int cod , char tipo[], char localizacao[], float bat, float aut) 
{
 if(!existeMobilidade(inicio, cod))
 {Mobilidade * novo = malloc(sizeof(struct mobilidade));
  if (novo != NULL)
  {novo->codigo = cod;
    strcpy(novo->tipo, tipo);
    strcpy(novo->localizacao, localizacao);
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
 {printf("%d %s %s %f %f\n",inicio->codigo, inicio->tipo, inicio->localizacao, inicio->bateria, inicio->autonomia);
  inicio = inicio->seguinte;
 }
}

// Ler Mobilidades
Mobilidade * lerMobilidades()
{
    FILE* fp;
    int cod;
    char tipo[50], localizacao[50];
    float bat, aut;
    Mobilidade* aux = NULL;

    fp = fopen("mobilidades.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d;%[^,],%[^\n];%f;%f\n", &cod, tipo, localizacao, &bat , &aut) == 5) {
            aux = criar_mobilidade(aux, cod, tipo, localizacao, bat, aut);
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
  fprintf(fp,"%d;%s;%s;%f;%f\n", aux->codigo, aux->tipo, aux->localizacao, aux->bateria, aux->autonomia);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

