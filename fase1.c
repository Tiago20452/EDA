#include <stdio.h>
#include "cliente.h"
#include "gestor.h"
#include "mobilidade.h"
#include "aluguer.h"

int menuMobilidade()
{
 int op;
 printf("M E N U\n");
 printf("1 - Inserir Meio de mobilidade\n");
 printf("2 - Listar Meios de mobilidade\n");
 printf("3 - Remover Meio de mobilidade\n");
 printf("4 - Guardar Meios de Mobilidade inseridos\n");
 printf("5 - Ler Meios de mobilidade\n");
 printf("0 - Sair\n");
 printf("Escolha uma opcao:\n");
 scanf("%d",&op);
 return(op);
}

int main()
{Mobilidade* meios = NULL; // Lista ligada vazia 
 int op, cod;
 float bat, aut, longi, lat;
 char tipo[50];
 do
 {
  op = menu();
  switch(op)
  {case 1: 
  		printf("Codigo?\n");
	   	scanf("%d",&cod);
	    scanf("%*c"); 
	    printf("Tipo\n");
	    scanf("%[^\n]s",tipo);
	    printf("Nivel da bateria?\n");
	    scanf("%f",&bat);
	    printf("Autonomia\n");
	    scanf("%f",&aut);
		printf("Longitude??\n");
	    scanf("%f",&longi);
		printf("Latitude?\n");
	    scanf("%f",&lat);
           meios = criarmobilidade(meios,cod,tipo,longi,lat,bat,aut);
	    break;
   case 2: listarMobilidades(meios); break;
   case 3: printf("Codigo do meio de mobilidade a remover?\n");
	   scanf("%d",&cod);
	   meios = remover_mobilidade(meios, cod);
	   break;
   case 4: guardarMobilidade(meios); break;
   case 5: meios = lerMobilidades(); break;
  }
 } while (op!=0);
}