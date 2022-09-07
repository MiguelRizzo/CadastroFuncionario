#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char nome[50];
	int diaNasc;
	int mesNasc;
	int anoNasc;
	char departamento[50];
	char cargo[50];
	int matricula;
	FILE *arquivo;
	char continua = 's';

	arquivo = fopen("cadastrofuncionarios.csv","a");

	printf("Deseja cadastrar um funcionario? s/n \n");
	scanf("%c", &continua);
	setbuf(stdin,NULL);
	
	while(continua == 's')
	
	{	
		printf("Digite o nome do funcionario:\n");
		scanf("%[^\n]",&nome);
		setbuf(stdin,NULL);
		
		printf("Digite o dia de nascimento do funcionario:\n");
		scanf("%d",&diaNasc);
		setbuf(stdin,NULL);
		
		printf("Digite o mes de nascimento do funcionario:\n");
		scanf("%d",&mesNasc);
		setbuf(stdin,NULL);
		
		printf("Digite o ano de nascimento do funcionario:\n");
		scanf("%d",&anoNasc);
		setbuf(stdin,NULL);
		
		printf("Digite o departamento do funcionario:\n");
		scanf("%[^\n]",&departamento);
		setbuf(stdin,NULL);
		
		printf("Digite o cargo do funcionario:\n");
		scanf("%[^\n]",&cargo);
		setbuf(stdin,NULL);
		
		printf("Digite o numero da matricula do funcionario:\n");
		scanf("%d",&matricula);
		setbuf(stdin,NULL);
		
		fprintf(arquivo,"%d;%s;%d/%d/%d;%s;%s\n",matricula,
		nome,diaNasc,mesNasc,anoNasc,departamento,cargo
		);

		printf("Deseja cadastrar um funcionario? s/n \n");
		scanf("%c", &continua);
		setbuf(stdin,NULL);
    }
	
	fclose(arquivo);
	
	arquivo = fopen("cadastrofuncionarios.csv","r");
	
	while(fscanf(arquivo,"%d;%[^;];%d/%d/%d;%[^;];%[^\n]",&matricula,
		&nome,&diaNasc,&mesNasc,&anoNasc,&departamento,&cargo
		)!= EOF)
		{
		printf("%d %s %d/%d/%d %s %s\n",matricula,
		nome,diaNasc,mesNasc,anoNasc,departamento,cargo);
		}
		
	return 0;
}
