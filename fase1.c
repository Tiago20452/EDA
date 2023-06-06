#include <stdio.h>
#include "cliente.h"
#include "gestor.h"
#include "mobilidade.h"
#include "aluguer.h"
#include "grafo.h"


int menuPrincipal()
{
 	int opPrincipal;
	printf("///////////////////////////////\n");
 	printf("\t MENU PRINCIPAL\n");
 	printf("1 - Gestor\n");         
 	printf("2 - Cliente\n");
 	printf("0 - Sair\n");
	printf("///////////////////////////////\n\n");
 	printf("Escolha uma opcao: ");
	
 	scanf("%d", &opPrincipal);

 	return (opPrincipal);
}

int menuGestor_REGLOG()
{
	int opGestor_REGLOG;
	printf("////////////////////////////////////\n");
	printf("\t MENU GESTOR \n");
	printf(" 1 - Registar novo gestor\n"); 
	printf(" 2 - Login \n"); 
	printf(" 0 - Voltar ao menu anterior\n");
	printf("////////////////////////////////////\n\n");
	printf(" Escolher opcao: ");
	scanf("%d", &opGestor_REGLOG);

	return (opGestor_REGLOG);
}

int menuRegistoGestor()     
{
	int opRegistoGestor;
	printf("//////////////////////////////////////////////////\n");
	printf("\t MENU DE REGISTO GESTOR\n");
	printf(" 1 - Inserir dados\n"); 
	printf(" 2 - Listar dados\n");  
	printf(" 3 - Guardar dados\n"); 
	printf(" 4 - Inserir valores aleatorios\n");
	printf(" 0 - Voltar ao menu anterior\n");
	printf("//////////////////////////////////////////////////\n\n");
	printf(" Escolher opcao: ");
	scanf("%d", &opRegistoGestor);

	return (opRegistoGestor);
}

int menuGestor()                                              
{
	int opGestor;
	printf("/////////////////////////////////////////////\n");
	printf("\t\t GESTOR \n");
	printf(" 1 - Criar novo meio de mobilidade\n");     
	printf(" 2 - Listar meios existentes\n");
	printf(" 3 - Alterar informacoes de meio\n");             
	printf(" 4 - Remover meio\n");
	printf(" 5 - Ler meios\n");
	printf(" 6 - Listar clientes registados\n");
	printf(" 7 - Remover cliente\n");
	printf(" 8 - Ler Clientes\n");
	printf(" 9 - Listar meios por geocodigo\n");
	printf(" 10 - Inserir meios de valores aleatorios\n");
	printf(" 0 - Voltar ao menu anterior\n");
	printf("/////////////////////////////////////////////\n\n");
	printf(" Escolher opcao: ");
	scanf("%d", &opGestor);

	return(opGestor);
}

int menuCliente_REGLOG()
{
	int opCliente_REGLOG;
	printf("//////////////////////////////////////////////////\n");
	printf("\t MENU CLIENTE \n");
	printf(" 1 - Registar novo cliente\n"); 
	printf(" 2 - Login \n");                                 
	printf(" 0 - Voltar ao menu anterior\n");
	printf("//////////////////////////////////////////////////\n\n");
	printf(" Escolher opcao: ");
	scanf("%d", &opCliente_REGLOG);

	return (opCliente_REGLOG);
}

int menuRegistoCliente()     
{
	int opRegistoCliente;
	printf("//////////////////////////////////////////////////\n");
	printf(" \t REGISTO NOVO CLIENTE \n");
	printf(" 1 - Inserir dados\n"); 
	printf(" 2 - Listar dados\n");  
	printf(" 3 - Guardar dados\n"); 
	printf(" 0 - Voltar ao menu anterior\n");
	printf("//////////////////////////////////////////////////\n\n");
	printf(" Escolher opcao: ");
	scanf("%d", &opRegistoCliente);

	return (opRegistoCliente);
}

int menuCliente()                                              
{
	int opCliente;
	printf("//////////////////////////////////////////////\n");
	printf("\t\t CLIENTE  \n");
	printf(" 1 - Listar meios existentes\n");     
	printf(" 2 - Alugar meio\n");
	printf(" 3 - Listar alugueres\n");   
	printf(" 4 - Inserir valores aleatorios de clientes\n");       
	printf(" 0 - Voltar ao menu anterior\n");
	printf("//////////////////////////////////////////////\n\n");

	printf(" Escolher opcao: ");
	scanf("%d", &opCliente);

	return(opCliente);
}

int main()
{
	Gestor* gestores = NULL;
	Mobilidade* meios = NULL;
	Cliente* clientes = NULL;
	Aluguer* alugueres = NULL;
	Grafo g = NULL;

	int opPrincipal, opGestor_REGLOG, opRegistoGestor, opGestor, opCliente_REGLOG, opRegistoCliente, opCliente;
	int cod, NIF, tel, id; 
	float bat, aut;
	char tipo[50], geocodigo[50], nome[50], email[50], password[20], senha[20], data[50];
	
	criarVertice(&g,"///thesaurus.sharers.blizzards");
 	criarVertice(&g,"///dimly.nuttier.pitch");
 	criarVertice(&g,"///babbled.trifling.consoled");
 	criarAresta(g,"///thesaurus.sharers.blizzards","///babbled.trifling.consoled",100);
 	criarAresta(g,"///thesaurus.sharers.blizzards","///dimly.nuttier.pitch",150);

 	inserirMeio(g,"///dimly.nuttier.pitch",100);
 	inserirMeio(g,"///dimly.nuttier.pitch",101);
 	inserirMeio(g,"///dimly.nuttier.pitch",102);
 	inserirMeio(g,"///babbled.trifling.consoled",200);

	do
	{
		opPrincipal = menuPrincipal();
		switch (opPrincipal)
		{
			case 1 :                                                                // GESTOR
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
											case 1 :                                // Inserção de credenciais do novo gestor  
													printf("Identificacao?\n");
	   												scanf("%d",&id);
	   												scanf("%*c"); 
	    											printf("Nome?\n");
	    											scanf("%[^\n]s",nome);
													getchar();
	    											printf("Senha?\n\n");
	    											scanf("%[^\n]s",senha);
													getchar();

														gestores = criar_gestor(gestores,id,nome,senha); // adiciona o gestor à lista ligada
													break;

											case 2 : listarGestores(gestores); break;     // lista os gestores contidos na lista ligada
											case 3 : guardarGestor(gestores); break;      // guarda a informação dos gestores num ficheiro.txt

											case 4 :                                                              //cria automaticamente gestores com as informações
													gestores = criar_gestor(gestores,1234,"Tiago","HFGJTY");      
													gestores = criar_gestor(gestores,5678,"Pedro","IOPFDS");
													gestores = criar_gestor(gestores,9865,"Antunes","YOPDWFG"); 
													guardarGestor(gestores);
													break;
										
										default:
											break;
										}
									} while (opRegistoGestor != 0);                           // Regressa ao menu anterior
								break;

							case 2 :                                                          //LOGIN e MENU DE GESTOR
							        printf(" ****Login de Gestor ****\n");
    								printf("Identificacao: ");
    								scanf("%d", &id);
									scanf("%*c"); 
    								printf("Senha: ");
    								scanf("%s", senha);
									getchar();

									gestores = gestor_login(gestores, id, senha);

									if (gestores != NULL )                                     // Confirma as credenciais de Gestor
									{
										printf("\tBEM VINDO %d!\n", id);
										do
										{
										
											opGestor = menuGestor();
											switch (opGestor)
											{
												case 1: 										// criação de um novo meio
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
														printf("Autonomia?\n\n");
	   													scanf("%f",&aut);

           													meios = criarmobilidade(meios,cod,tipo,geocodigo,bat,aut);
															guardarMobilidade(meios); 
															guardarMobilidade_Bin(meios);
													break;
											
												case 2:	listarMobilidades(meios); break;

												case 3: 													// alteração do meio da lista ligada
														printf("Codigo de meio a alterar?\n");
														scanf("%d", &cod);
															meios = remover_mobilidade(meios, cod);

														printf("Insira os novos dados do meio\n");

														printf("Codigo?\n");
	   													scanf("%d",&cod);
	    												scanf("%*c"); 
	   													printf("Tipo?\n");
	   													scanf("%[^\n]s",tipo);
														getchar();
	    												printf("Geocodigo?\n");
	   													scanf("%[^\n]s",geocodigo);
														getchar();
														printf("Bateria?\n");
	   													scanf("%f",&bat);
														printf("Autonomia?\n");
	   													scanf("%f\n",&aut);

           													meios = criarmobilidade(meios,cod,tipo,geocodigo,bat,aut);
															guardarMobilidade(meios);
														break;


												case 4:															// remoção do meio da lista ligada
														printf("Codigo do meio de mobilidade a remover?\n");
	   													scanf("%d",&cod);
	   														meios = remover_mobilidade(meios, cod);
															guardarMobilidade(meios); 
															guardarMobilidade_Bin(meios);
	   													break;

												case 5: meios = lerMobilidades(); break;
												case 6: listarClientes(clientes); break;

												case 7:                                                       // remoção de cliente da lista ligada
														printf("Numero fiscal do cliente a remover?\n");
	   													scanf("%d",&NIF);

	  														clientes = remover_cliente(clientes, NIF);
															guardarCliente(clientes);
	   													break;

												case 8: clientes = lerClientes(); break;

												case 9: 													 // procura de um meio por geocodigo
														printf("Qual o geocodigo que pretente procurar?\n");
														scanf("%s", geocodigo);
														getchar();
															meios = listarMobilidadesPorGeocodigo(meios, geocodigo);

														break;
											
												case 10:
														meios = criarmobilidade(meios,1,"Trotinete","Braga",78.00,89.00);
														meios = criarmobilidade(meios,2,"Bicicleta","Porto",55.00,80.00);
														meios = criarmobilidade(meios,3,"Trotinete","Braga",40.00,75.00);
														meios = criarmobilidade(meios,4,"Bicicleta","Braga",18.00,30.00);
														guardarMobilidade(meios); 
														break;
											default:
												break;
											}
										
										} while (opGestor != 0);
									
									} else {
										printf("Utilizador nao encontrado!\n\n");
									}
								break;
						default:
							break;
						}
					} while (opGestor_REGLOG != 0);
			    break;
			case 2 :															//CLIENTE
					do
					{
						opCliente_REGLOG = menuCliente_REGLOG();
						switch (opCliente_REGLOG)
						{
							case 1:                                            // REGISTO DE NOVO CLIENTE
									do
									{
										opRegistoCliente = menuRegistoCliente();
										switch (opRegistoCliente)
										{
											case 1:
													printf("Numero fiscal?\n");
	   												scanf("%d",&NIF); 
													printf("Numero de telemovel?\n");
	   												scanf("%d",&tel);
													scanf("%*c");
	    											printf("Nome?\n");
	    											scanf("%[^\n]s",nome);
													getchar();
													printf("Email?\n");
	    											scanf("%[^\n]s",email);
													getchar();
	    											printf("Password?\n");
	    											scanf("%[^\n]s\n",password);
													getchar();

														clientes = criar_cliente(clientes, NIF, tel, nome, email, password);
											break;

											case 2: listarClientes(clientes); break;
											case 3: guardarCliente(clientes); break;

											case 4: 
													clientes = criar_cliente(clientes, 123456777, 931234568, "Joao", "joao@gmail.com", "JOAO123");
													clientes = criar_cliente(clientes, 123456888, 923456789, "Maria", "maria@hotmail.com", "MARIA123");
													clientes = criar_cliente(clientes, 123456999, 965345678, "Manuel", "manuel@sapo.pt", "MANUEL123");
													guardarCliente(clientes);
													break;
										default:
											break;
										}
									} while (opRegistoCliente != 0);
									
							break;
						
							case 2 :
									printf(" ****Login de Gestor ****\n");
    								printf("Numero Fiscal: ");
    								scanf("%d", &NIF);
									scanf("%*c"); 
    								printf("Password: ");
    								scanf("%s", password);
									getchar();

									clientes = cliente_login(clientes, NIF, password);

									if (clientes != NULL )                                     // Confirma as credenciais do Cliente
									{
										printf("\tBEM VINDO %d!\n", NIF);
										do
										{
											opCliente = menuCliente();
											switch (opCliente)
											{
												case 1: listarMobilidades(meios);break;

												case 2: 
														scanf("%*c");
														printf("Insira o seu email:\n");
														scanf("%[^\n]s",email);
														getchar();
														printf("Insira o codigo do meio de mobilidade que deseja alugar:\n");
														scanf("%d", &cod);
														scanf("%*c");
														printf("Insira a data atual:\n");
														scanf("%[^\n]s\n",data);
														getchar();

															alugueres = novo_aluguer(alugueres, email, cod, data);
															guardarAluguer(alugueres);
														break;

												case 3: listarAluguer(alugueres); break;
									
											default:
												break;
											}
										} while (opCliente != 0);

									} else {
										printf("Utilizador nao encontrado!\n\n");
									}
									
							break;
						default:
							break;
						}
					} while (opCliente_REGLOG != 0);

			break;
		
		default:
			break;
		}

	} while (opPrincipal != 0);
	
}

