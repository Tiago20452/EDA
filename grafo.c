#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"

// Criar um novo vértice
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarVertice(Grafo *g, int novoVId)
{
    Grafo novo = malloc(sizeof(struct registo1));
    if (novo!=NULL)
    {
        novo->vertice = novoVId;
        novo->seguinte = *g;
        *g = novo;

        return(1);
    }
 else return(0);
}

int existeVertice(Grafo g, int vertice)
{while (g!=NULL)
 {
    if (strcmp(g->vertice,vertice)==0) 
    return(1);

    else g=g->seguinte;
 }
 return(0);
}

int criarAresta(Grafo g, int vORIGEM, int vDESTINO, float peso)
{
    Adjacente novo;
    if (existeVertice(g,vORIGEM) && existeVertice(g,vDESTINO))
    {
        while(g->vertice != vORIGEM)
        g=g->seguinte;
        novo = malloc(sizeof(struct registo1));

        if (novo!=NULL)
	    {   
            novo->vertice = vDESTINO;
	        novo->peso = peso;
	        novo->seguinte=g->adjacentes;
	        g->adjacentes=novo;
	        return(1);
	    }
        else return(0);
    }
 else return(0);
}

void listarAdjacentes(Grafo g, int vertice)
{
    Adjacente aux;
    if (existeVertice(g,vertice))
    {
        while (g->vertice != vertice) 
        g=g->seguinte;
        aux = g->adjacentes;

        while (aux!=NULL) 
        {
            printf("Adjacente:%d Peso:%.2f\n", aux->vertice, aux->peso);
            aux=aux->seguinte;
        }
    }
}

