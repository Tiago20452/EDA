#ifndef MOBILIDADE_H
#define MOBILIDADE_H

typedef struct {
    int codigo;
    char tipo[50];
    float bateria;
    float autonomia;
} Mobilidade;

Mobilidade* nova_mobilidade(int codigo, char* tipo, float bateria, float autonomia);

void remover_mobilidade(Mobilidade* mobilidade);

#endif // MOBILIDADE_H
