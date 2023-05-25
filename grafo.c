#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"

// Criar um novo vértice
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarVertice(Grafo *g, char novoId[])
{
    Grafo novo = malloc(sizeof(struct registo1));
    if (novo!=NULL)
    {
        strcpy(novo->vertice,novoId);
        novo->meios = NULL;
        novo->seguinte = *g;
        *g = novo;
    return(1);
    }
 else return(0);
}

int criarAresta(Grafo g, char vOrigem[], char vDestino[], float peso)
{
    Adjacente novo;
    if (existeVertice(g,vOrigem) && existeVertice(g,vDestino))
    {
        while(strcmp(g->vertice,vOrigem)!=0) 
        g=g->seguinte;
        novo = malloc(sizeof(struct registo1));
            if (novo!=NULL)
	        {
                strcpy(novo->vertice,vDestino);
	            novo->peso = peso;
	            novo->seguinte=g->adjacentes;
	            g->adjacentes=novo;

	            return(1);
	        }
        else return(0);
    }
    else return(0);
}

// Inserir meio de transporte na localização com geocódigo passado por parâmetro
// Devolve 1 em caso de sucesso ou 0 caso contrário
int inserirMeio(Grafo g, char geocodigo[], int codigoMeio)
{
 while ((g!=NULL)&&(strcmp(g->vertice,geocodigo)!=0))

	g=g->seguinte;
    if (g==NULL) 
    return(0);

    else 
    {
        Meios novo = malloc(sizeof(struct registo3));
        novo->codigo = codigoMeio;
        novo->seguinte = g->meios;
        g->meios = novo;
        return(1);	 
    }
}
