#include <stdio.h>

typedef struct meio {
    int codigo;
    char tipo[50];
    char geocodigo[50];
    float bateria;
    float autonomia;
    struct meio* seguinte;
} Mobilidade;


Mobilidade* criarmobilidade(Mobilidade* inicio, int cod, char tipo[], char geocodigo[], float bat, float aut);

int existeMobilidade(Mobilidade* inicio, int cod);

Mobilidade* remover_mobilidade(Mobilidade* inicio, int cod);

void listarMobilidades(Mobilidade * inicio);

Mobilidade * lerMobilidades();

int guardarMobilidade(Mobilidade* inicio);

int guardarMobilidade_Bin(Mobilidade* inicio); 


Mobilidade* listarMobilidadesPorGeocodigo(Mobilidade *inicio, char geocodigo[]);
