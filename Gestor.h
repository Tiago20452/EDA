#ifndef GESTOR_H
#define GESTOR_H

typedef struct {
    int id;
    char nome[50];
    char email[50];
    char telefone[20];
    char senha[20];
} Gestor;

Gestor* criar_gestor(int id, char* nome, char* email, char* telefone, char* senha);

void remover_gestor(Gestor* gestor);

#endif // GESTOR_H
