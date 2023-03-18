
#ifndef ALUGUER.H
#define ALUGUER.H
#include <stdio.h>


typedef struct aluguer {

   int codigo; // código do meio de mobilidade elétrica
   char data[20]; // data do aluguel
   struct aluguer* seguinte
} Aluguer;

Aluguer* novo_aluguer(Aluguer* inicio, int cod, char data[]);

int guardarAluguer(Aluguer* inicio);

void listarAluguer(Aluguer * inicio);

#endif 