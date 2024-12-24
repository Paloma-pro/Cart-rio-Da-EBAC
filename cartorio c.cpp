#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�el por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a se cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //espa�o para colocar a variavel, o "%s" refere-se as strings(conjunto de variaveis)
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //chmar a fun��o do arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa escrever
	fprintf(file, "CPF: "); //separando as informa��es por categoria
	fprintf(file,cpf); //salva o valor da variavel e adiciona
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" refere-se a atualizar/adicionar
	fprintf(file, ", ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletar a informa��o
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informa��es
	fprintf(file, "NOME: "); //separando as informa��es por categoria
	fprintf(file,nome); //adiciona a vari�vel escolhida
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informa��es
	fprintf(file, ", ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletar a informa��o
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informa��es
	fprintf(file, "SOBRENOME: "); //separando as informa��es por categoria
	fprintf(file,sobrenome); //adiciona a vari�vel escolhida
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informa��es
	fprintf(file, ", ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletar a informa��o
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informa��es
	fprintf(file, "CARGO: "); //separando as irforma��es por categoria
	fprintf(file,cargo); //adiciona a vari�vel escolida
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//definindo as v�riaveis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" refere-se a ler, o que ser� mostrado
	
	if(file == NULL) //caso n�o encontre
	{
		printf("Arquivo n�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso encontre
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo); //mostrar as informa��es salvas no arquivo
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	//definindo a vari�vel
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //ler as informa��es do arquivo
	
	if(file == NULL)//caso n�o encontre o cfp digitado
	{
		printf("O usu�rio n�o encontrado.\n");
		system("pause");
	}	
	
	else //se encontrar ele deleta
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado!\n");
		system("pause");	
	}	
	
}

int main() //fun��o principal do programa
{
	int opcao=0; //Definindo as variaveis (m�dulo 03), revisar as variaveis ;p
	int laco=1; //aula 5
	
	for(laco=1;laco=1;) //depois da variavel e antes de tudo, entrada e saida
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolher a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o:  "); //fim do menu
	
		scanf("%d", &opcao); //Esperando a escolha do usuario
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1: //op��o
			registro(); //chamada de fun��es
			break;
			
			case 2: //op��o
			consulta();
			break;
			
			case 3: //op��o
			deletar();
			break;
			
			default: //caso o usu�rio digitar outra op��o n�o listada acima
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		} //fim da sele��o
	
	}
}
