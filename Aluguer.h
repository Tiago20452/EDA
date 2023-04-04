#include <stdio.h>


typedef struct aluguer {
   char email[50];        // email do usuário
   int codigo;            // código do meio de mobilidade elétrica
   time_t data_aluguer;   // data do aluguer
   struct aluguer* seguinte;
} Aluguer;

Aluguer* novo_aluguer(Aluguer* inicio,char email[], int cod, time_t data);

int guardarAluguer(Aluguer* inicio);

void listarAluguer(Aluguer * inicio);
