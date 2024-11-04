#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por país
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar(){ //função para resgistrar
	char simnao[1]="s";
	char arquivo[15];
	char cpf[15];
	char nome[20];
	char sobrenome[40];
	char cargo[20];
	system("cls");
	
	printf ("Digite o CPF para cadastrar: ");
	scanf ("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //abre o arquivo
	fprintf(file,cpf); //salvar valor da variável
	fclose(file); //fecha o arquivo	
	
	file = fopen(arquivo,"a"); //usado para pular linha entre informações
	fprintf(file,", Nome: "); //usado para pular linha entre informações
	fclose(file); //usado para pular linha entre informações
	
	printf("\nDigite o primeiro nome do usuário: ");
	scanf ("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", Sobrenome: ");
	fclose(file);
	
	printf("\nDigite o sobrenome do usuário: ");
	scanf ("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); //usado para pular linha entre informações
	fprintf(file,", Cargo: "); //usado para pular linha entre informações
	fclose(file); //usado para pular linha entre informações
	
	printf("\nDigite o cargo do usuário:");
	scanf ("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);	
	
	printf ("\n\n\n\nOs dados estão corretos? (s/n)");
	scanf ("%s", &simnao);
	if (strcmp(simnao,"s") ==0) {
		system ("cls");
		printf("Novo usuário cadastrado!\n\n\n\n\n\n");
		system("pause");
	}
	else {
		system ("cls");
		printf ("Deseja voltar ao menu inicial? (s/n)\n\n");
		scanf ("%s", &simnao);
		if (strcmp(simnao,"s") ==0){
			main();
		}
		else registrar();
	}
}

int consultar(){ //função para consultar
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem do programa
	
	char cpf [15];
	char conteudo [200];
	
	printf ("Digite o CPF  para a consulta:\n");
	scanf ("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL) {
		printf ("\n\n\nCPF não localizado!\n\n\n\n\n");
	}
	while(fgets(conteudo, 200, file)!=NULL){ //enquanto tiver caractére vai continuar lendo
		printf ("CPF: ");
		printf ("%s", conteudo);
	}
	printf("\n\n");
	system("pause");
	fclose(file);
}

int deletar(){ //função para deletar
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem do programa
	char cpf[15];
	
	printf ("Digite o CPF que pretende deletar: ");
	scanf ("%s",cpf);
	
	FILE *file;
	
	
	if(file != NULL){
		remove(cpf);
		file = fopen(cpf,"r");
		printf("\n\nO CPF: %s foi deletado com sucesso.\n\n\n",cpf);
		system("pause");
	}
	else {
		printf ("\n\n\nCPF não encontrado!\n\n\n\n");
		system("pause");		
	}
	fclose(file);
}

void telaLogin(){ //pedindo login

    char login[15] = "admin";
    char login1[15];
    char senha[15] = "admin";
    char senha1[15];        
    int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

    while(!login_efetuado){
        printf("Digite o Login: ");
        scanf("%s", login1);

        printf("Digite a Senha: ");
        scanf("%s", senha1);

        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
            printf("\n\nLOGADO!\n\n");
            login_efetuado = 1;
        }
        else{
		printf("\n\nDADOS INVALIDOS!\n\n");
		system("pause");
		system("cls");
		}
	}

}

int main(){ //função principal
	
	int opcao=0; //Definindo variáveis
	int laco=1;
	telaLogin();
	
	for(laco=1;laco=1;){ //fazendo o loop para o programa não fechar
	
	
		system("cls"); //Limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem do programa
	
		printf ("### Cartório da EBAC ###\n\n"); //Título
		printf ("Escolha a opção no menu:\n\n"); //Menu principal	
		printf ("\t1 - Resgistrar usuário\n");
		printf ("\t2 - Consultar usuário\n");
		printf ("\t3 - Deletar usuário\n\n");
		printf ("\t0 - Fechar o programa\n\n\n");
		printf ("Digite o número da ação desejada:");	
	
		scanf ("%d", &opcao); //armazenando a opção do usuário
	
		system("cls"); //Limpar a tela
		
		switch(opcao){ //enviando resposta ao usuário
			case 1:
				registrar();
				break;
			case 2:
				consultar();
				break;
			case 3:
				deletar();
				break;
			case 0:
				printf ("Volte sempre!\n\n\n");
				exit(0);
				break;
			default:
				printf ("Escolha uma opção de 1 a 3.\n\n\n\n");
				system ("pause");
				break;
		}
	}
	
}

