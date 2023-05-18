#include <stdio.h>

typedef struct registo {
    int Numero_fiscal;
    int telefone;
    char nome[50];
    char email[50];
    char password[20];
    struct registo* seguinte;
} Cliente;

Cliente* criar_cliente(Cliente* inicio, int NIF, int tel, char nome[], char email[], char password[]);

int existeCliente(Cliente* inicio, int Numero_fiscal);

Cliente* remover_cliente(Cliente* inicio, int NIF);

void listarClientes(Cliente* inicio);

int guardarCliente(Cliente* inicio);

Cliente* lerClientes();






