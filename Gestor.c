#include "gestor.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Criar novo Gestor
Gestor* criar_gestor(Gestor* inicio, int id , char nome[], char senha[]) 
{
 if(!existeGestor(inicio, id))
 {Gestor * novo = malloc(sizeof(struct gestor));
  if (novo != NULL)
  {novo->identificacao = id;
    strcpy(novo->nome, nome);
    strcpy(novo->senha, senha);
    return (novo);
  } 
 } else return(inicio);
}

// Existe gestor?
int existeGestor(Gestor* inicio, int id)
{while(inicio!=NULL)
  {if (inicio->identificacao == id) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

// Remover um Cliente a partir do seu id
Gestor* remover_gestor(Gestor* inicio, int id) 
{
 Gestor *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual-> identificacao == id) // remove o 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->identificacao!=id)) 
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

// listar na consola o conteúdo da lista ligada de Gestores
void listarGestores(Gestor * inicio)
{while (inicio != NULL)
 {printf("%d %s %s\n",inicio->identificacao, inicio->nome, inicio->nome, inicio->senha);
  inicio = inicio->seguinte;
 }
}

// Ler Gestores
Gestor * lerGestores()
{
    FILE* fp;
    int id;
    char nome[50], senha[20];
    Gestor* aux = NULL;

    fp = fopen("gestores.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d;%[^,],%[^\n]\n", &id, nome, senha) == 3) {
            aux = criar_gestor(aux, id, nome, senha);
        }
        fclose(fp);
    }

    return(aux);
}

//Guardar Gestor
int guardarGestor(Gestor* inicio)
{FILE* fp;
 fp = fopen("gestores.txt","w");
 if (fp!=NULL)
 {
 Gestor* aux = inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%s;%s\n", aux->identificacao, aux->nome, aux->senha);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

