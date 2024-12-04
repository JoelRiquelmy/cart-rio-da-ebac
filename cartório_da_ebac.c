#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca respons�vel oela aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de loca��o de texto por regi�o
#include <string.h> //biblioteca que cuida de dar a vida para as strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o cpf para ser cadastrado:  ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
		
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);	
	
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	

	int opcao=0;
	
	system("cls");
	
	printf("\nNome registrado dcom sucesso!\n\n");
	printf("\n\t1 - Voltar para registrar nomes\n\n");
	printf("\n\t2 - Voltar para o menu\n");
	
	scanf("%d", &opcao);
	system("cls");
 	
	switch(opcao)
	{
		case 1:
		registro();		
						
		break;
	
		case 2:
		return 0;
		system("cls");
		
		break;		
	}

		
	system("pause");
		
}

int consultar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("\nO CPF digitado n�o existe\n\n");
	}
	
	while (fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");	
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("\nDigite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);



	remove(cpf);
	
	
	FILE *file;
	file =fopen(cpf, "r");
	

	if(file ==NULL)
	{
		printf("\nEsse usu�rio n�o existe!\n");
		
		system("pause");
	}
}







int main()
{
	int opcao=0;
	int repeat=1;
	
	for(repeat=1;repeat=1;)
	{
	
		system("cls");
		
		
		
		setlocale(LC_ALL, "portuguese");
	
		printf("\n\n###BEM VINDO AO CART�RIO DA EBAC###\n\n");
		printf("Escolha uma das op��es do menu:\n\n");
		printf("\t1 - registrar nomes\n\n");
		printf("\t2 - consultar nomes\n\n");
		printf("\t3 - deletar  nomes\n\n");
		printf("\t4 - sair do site\n\n");
		printf("op��o: ");
	
		scanf("%d", &opcao);
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();	
							
			break;
			
			case 2:
			consultar();
										
			break;
			
			case 3:
			deletar();							
			break;
			
			case 4:
			printf("\nobrigado por utilizar o site\n\n");
			return 0;
								
			break;
			

			
			default:
				
			printf("essa op��o n�o existe!\n\n");
			system("pause");	
				
			break;	
		}
	
	}
}

