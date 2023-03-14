#include "Mobilidade.h"
#include <stdlib.h>
#include <string.h>

Mobilidade* nova_mobilidade(int codigo, char* tipo, float bateria, float autonomia) {
    Mobilidade* mobilidade = malloc(sizeof(Mobilidade));
    mobilidade->codigo = codigo;
    strcpy(mobilidade->tipo, tipo);
    mobilidade->bateria = bateria;
    mobilidade->autonomia = autonomia;

    return mobilidade;
}

void remover_mobilidade(Mobilidade* mobilidade) {
    free(mobilidade);
}
