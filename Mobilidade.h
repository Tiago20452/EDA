#ifndef MOBILIDADE_H
#define MOBILIDADE_H
#include <stdio.h>

typedef struct mobilidade {
    int codigo;
    char tipo[50];
    char localizacao[50]; // cidade
    float bateria;
    float autonomia;
    struct mobilidade* seguinte;
} Mobilidade;

Mobilidade* criar_mobilidade(Mobilidade* inicio, int cod , char tipo[], char localizacao[], float bat, float aut);

int existeMobilidade(Mobilidade* inicio, int codigo);

Mobilidade* remover_mobilidade(Mobilidade* inicio, int cod);

void listarMobilidades(Mobilidade * inicio);

Mobilidade * lerMobilidades();

#endif // MOBILIDADE_H
