#include "Cliente.h"
#include <stdlib.h>
#include <string.h>

Cliente* criar_cliente(int NIF, char* nome, char* email, char* telefone, char* password) {
    Cliente* cliente = malloc(sizeof(Cliente));
    cliente->NIF = NIF;
    strcpy(cliente->nome, nome);
    strcpy(cliente->email, email);
    strcpy(cliente->telefone, telefone);
    strcpy(cliente->password, password);
    return cliente;
}

void remover_clinte(Cliente* cliente) {
    free(cliente);
}
