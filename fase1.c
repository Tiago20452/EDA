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
 	printf("Escolha uma opcao: ");
 	scanf("%d", &opPrincipal);

 	return (opPrincipal);
}

int menuGestor_REGLOG()
{
	int opGestor_REGLOG;
	printf(" 1 - Registar novo gestor\n"); 
	printf(" 2 - Login \n"); 
	printf(" 0 - Sair\n");
	printf(" Escolher opcao: ");
	scanf("%d", &opGestor_REGLOG);

	return (opGestor_REGLOG);
}

int menuRegistoGestor()     // feito
{
	int opRegistoGestor;
	printf(" 1 - Inserir dados\n"); 
	printf(" 2 - Listar dados\n");  
	printf(" 3 - Guardar dados\n"); 
	printf(" 0 - Sair\n");
	printf(" Escolher opcao: ");
	scanf("%d", &opRegistoGestor);

	return (opRegistoGestor);
}

int menuGestor()                                              
{
	int opGestor;
	printf(" 1 - Criar novo meio de mobilidade\n");     
	printf(" 2 - Listar meios existentes\n");
	printf(" 3 - Alterar informacoes de meio\n");             //em falta
	printf(" 4 - Remover meio\n");
	printf(" 5 - Ler meios\n");
	printf(" 6 - Listar clientes registados\n");
	printf(" 7 - Remover cliente\n");
	printf(" 8 - Ler Clientes\n");
	printf(" 0 - Sair\n");
	scanf("%d", &opGestor);

	return(opGestor);
}

int main()
{
	Gestor* gestores = NULL;
	Mobilidade* meios = NULL;
	Cliente* clientes = NULL;

	int opPrincipal, opGestor_REGLOG, opRegistoGestor, opGestor;
	int cod, NIF, tel, id; 
	float bat, aut;
	char tipo[50], geocodigo[50], nome[50], email[50], password[20], senha[20];

	do
	{
		opPrincipal = menuPrincipal();
		switch (opPrincipal)
		{
			case 1 : 
					do
					{
						opGestor_REGLOG = menuGestor_REGLOG();
						switch (opGestor_REGLOG)
						{
							case 1 :                                                //REGISTO DE GESTOR
									do 
									{
										opRegistoGestor = menuRegistoGestor();
										switch (opRegistoGestor)
										{
											case 1 :                                   
													printf("Identificacao?\n");
	   												scanf("%d",&id);
	   												scanf("%*c"); 
	    											printf("Nome?\n");
	    											scanf("%[^\n]s",nome);
													getchar();
	    											printf("Senha?\n");
	    											scanf("%[^\n]s",senha);
													getchar();

														gestores = criar_gestor(gestores,id,nome,senha);	
													break;

											case 2 : listarGestores(gestores); break;
											case 3 : guardarGestor(gestores); break;
										
										default:
											break;
										}
									} while (opRegistoGestor != 0);
								break;

							case 2 :                                                          //LOGIN DE GESTOR
									do
									{
										/*
										printf("Insira o seu ID: ");
										scanf("%d", &id);
										printf("Insira a sua senha: \n");
										scanf("%[^\n]s", senha);
										getchar();


										if (lerGestores(id, senha))
										{
											printf(" Bem vindo %d", id);
										}
										 else
										{
											printf("Credenciais invalidas!");
											return 0;
										}
										*/
											opGestor = menuGestor();
											switch (opGestor)
											{
												case 1: 
														printf("Codigo?\n");
	   													scanf("%d",&cod);
	    												scanf("%*c"); 
	   													printf("Tipo\n");
	   													scanf("%[^\n]s",tipo);
														getchar();
	    												printf("Geocodigo?\n");
	   													scanf("%[^\n]s",geocodigo);
														getchar();
														printf("Bateria?\n");
	   													scanf("%f",&bat);
														printf("Autonomia?\n");
	   													scanf("%f",&aut);

           													meios = criarmobilidade(meios,cod,tipo,geocodigo,bat,aut);
															guardarMobilidade(meios); 
															guardarMobilidade_Bin(meios);
												    	break;
											
												case 2:	listarMobilidades(meios); break;
											//	case 3: alterarmobilidade; break;

												case 4: printf("Codigo do meio de mobilidade a remover?\n");
	   													scanf("%d",&cod);
	   														meios = remover_mobilidade(meios, cod);
															guardarMobilidade(meios); 
															guardarMobilidade_Bin(meios);
	   													break;

												case 5: meios = lerMobilidades(); break;
												case 6: listarClientes(clientes); break;

												case 7: 
														printf("Numero fiscal do cliente a remover?\n");
	   													scanf("%d",&NIF);

	  														clientes = remover_cliente(clientes, NIF);
															guardarCliente(clientes);
	   													break;

												case 8: clientes = lerClientes(); break;

											default:
												break;
											}
										
									} while (opGestor != 0);
								break;

						default:
							break;
						}
					} while (opGestor_REGLOG != 0);
					

			break;
		
		default:
			break;
		}

	} while (opPrincipal != 0);
	
}





										/*printf("Insira o seu ID\n");
										scanf("%d", &id1);
										printf("Insira a sua senha\n");
										scanf("%[^\n]s", senha1);
										getchar();

										printf("Bem vindo!");*/









/*
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