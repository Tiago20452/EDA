#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    int NIF;
    char nome[50];
    char email[50];
    char telefone[20];
    char password[20];
} Cliente;

Cliente* criar_cliente(int NIF, char* nome, char* email, char* telefone, char* password);

void remover_cliente(Cliente* cliente);

#endif // CLIENTE_H
