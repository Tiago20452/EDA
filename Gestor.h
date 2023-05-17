#include <stdio.h>

typedef struct gestor {
    int identificacao;
    char nome[50];
    char senha[20];
    struct gestor* seguinte;
} Gestor;

Gestor* criar_gestor(Gestor* inicio, int id , char nome[], char senha[]);

int existeGestor(Gestor* inicio, int identificacao);

Gestor* remover_gestor(Gestor* inicio, int id);

void listarGestores(Gestor * inicio);

Gestor * lerGestores();

int guardarGestor(Gestor* inicio);

Gestor* gestor_login(Gestor* inicio, int id, char senha[]);