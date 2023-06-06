#include <stdio.h>

typedef struct registo2
{
    int vertice; 
    float peso;
    struct registo2 * seguinte;
} * Adjacente;


typedef struct registo1
{
    int vertice; 
    Adjacente adjacentes;

 struct registo1 * seguinte;
} * Grafo;

int criarVertice(Grafo *g, int novoVId);
int existeVertice(Grafo g, int vertice);
int criarAresta(Grafo g, int vORIGEM, int vDESTINO, float peso);
void listarAdjacentes(Grafo g, int vertice);

