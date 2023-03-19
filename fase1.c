#include <stdio.h>
#include "cliente.h"
#include "gestor.h"
#include "mobilidade.h"
#include "aluguer.h"

int menuPrincipal()
{
 	int opPrincipal;
 	printf("MENU PRINCIPAL\n");
 	printf("1 - Gestor\n");
 	printf("2 - Cliente\n");
 	printf("0 - Sair\n");
 	printf("Escolha uma opcao:\n");
 	scanf("%d", &opPrincipal);

 	return (opPrincipal);
}

int menuGestor_REGLOG()
{
	int opGestor_REGLOG;
	printf(" 1 - Registar novo gestor\n");
	printf(" 2 - Login \n");
	printf(" 0 - Voltar");
	printf(" Escolher opcao: ");
	scanf("%d", &opGestor_REGLOG);

	return (opGestor_REGLOG);
}

int menuRegistoGestor()
{
	int opRegistoGestor;
	printf(" 1 - Inserir dados\n");
	printf(" 2 - Listar dados\n");
	printf(" 3 - Guardar dados\n");
	printf(" 0 - Retornar");
	scanf("%d", &opRegistoGestor);

	return (opRegistoGestor);
}

int menuGestor()
{
	int opGestor;
	printf(" 1 - Criar novo meio de mobilidade\n");
	printf(" 2 - Guardar meios adicionados\n");
	printf(" 3 - Listar meios existentes\n");
	printf(" 4 - Remover meio");
	printf(" 5 - Alterar informações de meio");
	printf(" 5 - Listar clientes registados");
	printf(" 6 - Remover cliente");



}

















/*
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
*/