#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsáel por cuidar das strings

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a se cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //espaço para colocar a variavel, o "%s" refere-se as strings(conjunto de variaveis)
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //chmar a função do arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa escrever
	fprintf(file, "CPF: "); //separando as informações por categoria
	fprintf(file,cpf); //salva o valor da variavel e adiciona
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" refere-se a atualizar/adicionar
	fprintf(file, ", ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletar a informação
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informações
	fprintf(file, "NOME: "); //separando as informações por categoria
	fprintf(file,nome); //adiciona a variável escolhida
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informações
	fprintf(file, ", ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletar a informação
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informações
	fprintf(file, "SOBRENOME: "); //separando as informações por categoria
	fprintf(file,sobrenome); //adiciona a variável escolhida
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informações
	fprintf(file, ", ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletar a informação
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com informações
	fprintf(file, "CARGO: "); //separando as irformações por categoria
	fprintf(file,cargo); //adiciona a variável escolida
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//definindo as váriaveis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" refere-se a ler, o que será mostrado
	
	if(file == NULL) //caso não encontre
	{
		printf("Arquivo não localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso encontre
	{
		printf("\nEssas são as informações do usuário: \n");
		printf("%s", conteudo); //mostrar as informações salvas no arquivo
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	//definindo a variável
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //ler as informações do arquivo
	
	if(file == NULL)//caso não encontre o cfp digitado
	{
		printf("O usuário não encontrado.\n");
		system("pause");
	}	
	
	else //se encontrar ele deleta
	{
		fclose(file);
		remove(cpf);
		printf("Usuário deletado!\n");
		system("pause");	
	}	
	
}

int main() //função principal do programa
{
	int opcao=0; //Definindo as variaveis (módulo 03), revisar as variaveis ;p
	int laco=1; //aula 5
	
	for(laco=1;laco=1;) //depois da variavel e antes de tudo, entrada e saida
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolher a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:  "); //fim do menu
	
		scanf("%d", &opcao); //Esperando a escolha do usuario
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1: //opção
			registro(); //chamada de funções
			break;
			
			case 2: //opção
			consulta();
			break;
			
			case 3: //opção
			deletar();
			break;
			
			default: //caso o usuário digitar outra opção não listada acima
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		} //fim da seleção
	
	}
}
