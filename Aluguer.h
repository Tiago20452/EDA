#include <stdio.h>


typedef struct aluguer {
   char email[50];        // email do usuário
   int codigo;           // código do meio de mobilidade elétrica
   char data_atual[50];

   struct aluguer* seguinte;
} Aluguer;

Aluguer* novo_aluguer(Aluguer* inicio,char email[], int cod, char data[]);

int guardarAluguer(Aluguer* inicio);

void listarAluguer(Aluguer * inicio);
