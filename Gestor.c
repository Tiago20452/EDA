#include "Gestor.h"
#include <stdlib.h>
#include <string.h>

Gestor* criar_gestor(int id, char* nome, char* email, char* telefone, char* senha) {
    Gestor* gestor = malloc(sizeof(Gestor));
    gestor->id = id;
    strcpy(gestor->nome, nome);
    strcpy(gestor->email, email);
    strcpy(gestor->telefone, telefone);
    strcpy(gestor->senha, senha);
    return gestor;
}

void destruir_gestor(Gestor* gestor) {
    free(gestor);
}
