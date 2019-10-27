//Guilherme Rocha Vieira RA: 22.118.024-3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Agenda
{
	char nome[50];
	char telefone[20];
	char email[30];
	char rg[16];
	char cpf[20];
	char sangueT[4];
	char convenio[15];
	char religiao[10];
	char cidade[20];
	char estado[2];
} Agenda;

void Inserir(Agenda *P, int *T)
{
	fflush(stdin);
	printf("\n=========================\nInsercao do Paciente N:%d\n=========================\n", *T);
	printf("Nome: ");
	fflush(stdin);
	fgets((*(P + *T)).nome, 50, stdin);
	printf("Telefone: ");
	fgets((*(P + *T)).telefone, 20, stdin);
	printf("E-mail: ");
	fgets((*(P + *T)).email, 30, stdin);
	printf("RG: ");
	fgets((*(P + *T)).rg, 16, stdin);
	printf("CPF: ");
	fgets((*(P + *T)).cpf, 20, stdin);
	printf("Tipo Sanguineo: ");
	fgets((*(P + *T)).sangueT, 4, stdin);
	printf("Operadora do Convenio: ");
	fgets((*(P + *T)).convenio, 15, stdin);
	printf("Religiao: ");
	fgets((*(P + *T)).religiao, 10, stdin);
	fflush(stdin);
	printf("Cidade: ");
	fgets((*(P + *T)).cidade, 20, stdin);
	printf("Estado: ");
	fgets((*(P + *T)).estado, 2, stdin);
	printf("=========================\n\n");
	*T = *T + 1;
}

void Listar(Agenda *P, int *T)
{
	int i = 0;
	for (i = 0; i < *T; i++)
	{
		printf("\n=========================\nListagem do Paciente N:%d\n=========================\n", i);
		printf("Nome: %s", P[i].nome);
		printf("Telefone: %s", P[i].telefone);
		printf("E-mail: %s", P[i].email);
		printf("RG: %s", P[i].rg);
		printf("CPF: %s", P[i].cpf);
		printf("Tipo Sanguineo: %s", P[i].sangueT);
		printf("Operadora do Convenio: %s", P[i].convenio);
		printf("Religiao: %s", P[i].religiao);
		printf("Cidade: %s", P[i].cidade);
		printf("Estado: %s", P[i].estado);
		printf("\n=========================\n\n");
	}
}

void Remover(Agenda *P, int *T)
{
	int num = 0, i = 0, certo = 0;
	while (certo == 0)
	{
		printf("\n============================================\nInsira o numero do paciente para remocao: ");
		scanf("%d%*c", &num);
		printf("============================================\n");
		if (num >= 0 && num < *T)
		{

			certo = 1;
		}
		else
		{
			printf("\n=========================================\n");
			printf("O n�mero do paciente digitado n�o existe!");
			printf("\n=========================================\n");
		}
	}
	int aux = 0;
	for (i = num; i < *T; i++)
	{
		if (num + aux == *T - 1)
		{
			strncpy(P[num + aux].nome, "zerado", 50);
			strncpy(P[num + aux].telefone, "zerado", 20);
			strncpy(P[num + aux].email, "zerado", 30);
			strncpy(P[num + aux].rg, "zerado", 16);
			strncpy(P[num + aux].cpf, "zerado", 20);
			strncpy(P[num + aux].sangueT, "zerado", 4);
			strncpy(P[num + aux].convenio, "zerado", 15);
			strncpy(P[num + aux].religiao, "zerado", 10);
			strncpy(P[num + aux].cidade, "zerado", 20);
			strncpy(P[num + aux].estado, "zerado", 2);
		}
		else
		{
			strncpy(P[num + aux].nome, P[num + aux + 1].nome, 50);
			strncpy(P[num + aux].telefone, P[num + aux + 1].telefone, 30);
			strncpy(P[num + aux].email, P[num + aux + 1].email, 30);
			strncpy(P[num + aux].rg, P[num + aux + 1].rg, 16);
			strncpy(P[num + aux].cpf, P[num + aux + 1].cpf, 20);
			strncpy(P[num + aux].sangueT, P[num + aux + 1].sangueT, 4);
			strncpy(P[num + aux].convenio, P[num + aux + 1].convenio, 15);
			strncpy(P[num + aux].religiao, P[num + aux + 1].religiao, 10);
			strncpy(P[num + aux].cidade, P[num + aux + 1].cidade, 20);
			strncpy(P[num + aux].estado, P[num + aux + 1].estado, 2);
		}
		aux++;
	}
	printf("\n===================================\nPaciente N:%d removido com sucesso!\n===================================\n", num);
	*T = *T - 1;
}

void Alterar(Agenda *P, int *T)
{
	int num = 0, i = 0, certo = 0, escolha = -1;
	while (certo == 0)
	{
		printf("\n==============================================\nInsira o numero do paciente para alteracao: ");
		scanf("%d%*c", &num);
		printf("==============================================\n");
		if (num >= 0 && num < *T)
		{

			certo = 1;
		}
		else
		{
			printf("\n=========================================\n");
			printf("O n�mero do paciente digitado n�o existe!");
			printf("\n=========================================\n");
		}
	}

	while (escolha != 11)
	{
		printf("++++++++++++++++++++++++++++\n");
		printf("Alteracao do paciente N:%d\n", num);
		printf("++++++++++++++++++++++++++++\n");
		printf("Todos os campos(0)\n");
		printf("Nome(1)\n");
		printf("Telefone(2)\n");
		printf("E-mail(3)\n");
		printf("RG(4)\n");
		printf("CPF(5)\n");
		printf("Tipo sanguineo(6)\n");
		printf("Operadora do Convenio(7)\n");
		printf("Religiao(8)\n");
		printf("Cidade(9)\n");
		printf("Estado(10)\n");
		printf("Sair(11)\n");
		printf("++++++++++++++++++++++++++++\n");
		printf("Escolha um dos campos acima!\n");
		printf("Obs: Digite o numero :)\n");
		printf("++++++++++++++++++++++++++++\n");
		scanf("%d%*c", &escolha);

		if (escolha == 0)
		{
			fflush(stdin);
			printf("Nome: ");
			fgets((*(P + num)).nome, 50, stdin);
			printf("Telefone: ");
			fgets((*(P + num)).telefone, 20, stdin);
			printf("E-mail: ");
			fgets((*(P + num)).email, 30, stdin);
			printf("RG: ");
			fgets((*(P + num)).rg, 16, stdin);
			printf("CPF: ");
			fgets((*(P + num)).cpf, 20, stdin);
			printf("Tipo Sanguineo: ");
			fgets((*(P + num)).sangueT, 4, stdin);
			printf("Operadora do Convenio: ");
			fgets((*(P + num)).convenio, 15, stdin);
			printf("Religiao: ");
			fgets((*(P + num)).religiao, 10, stdin);
			fflush(stdin);
			printf("Cidade: ");
			fgets((*(P + num)).cidade, 20, stdin);
			printf("Estado: ");
			fgets((*(P + num)).estado, 2, stdin);
			printf("=========================\n\n");
			escolha = -1;
		}

		else if (escolha == 1)
		{
			printf("Nome: ");
			fgets((*(P + num)).nome, 50, stdin);
			escolha = -1;
		}

		else if (escolha == 2)
		{
			printf("Telefone: ");
			fgets((*(P + num)).telefone, 20, stdin);
			escolha = -1;
		}

		else if (escolha == 3)
		{
			printf("E-mail: ");
			fgets((*(P + num)).email, 30, stdin);
			escolha = -1;
		}

		else if (escolha == 4)
		{
			printf("RG: ");
			fgets((*(P + num)).rg, 16, stdin);
			escolha = -1;
		}

		else if (escolha == 5)
		{
			printf("CPF: ");
			fgets((*(P + num)).cpf, 20, stdin);
			escolha = -1;
		}

		else if (escolha == 6)
		{
			printf("Tipo Sanguineo: ");
			fgets((*(P + num)).sangueT, 4, stdin);
			escolha = -1;
		}

		else if (escolha == 7)
		{

			printf("Operadora do Convenio: ");
			fgets((*(P + num)).convenio, 15, stdin);
			escolha = -1;
		}

		else if (escolha == 8)
		{
			printf("Religiao: ");
			fgets((*(P + num)).religiao, 10, stdin);
			escolha = -1;
		}

		else if (escolha == 9)
		{
			printf("Cidade: ");
			fgets((*(P + num)).cidade, 20, stdin);
			escolha = -1;
		}

		else if (escolha == 10)
		{
			printf("Estado: ");
			fgets((*(P + num)).estado, 2, stdin);
			escolha = -1;
		}
		else if (escolha == 11)
		{
			printf("==========================\n");
			printf("Menu de alteracao fechado!\n");
			printf("==========================\n");
		}
		else
		{
			printf("====================\n");
			printf("Escolha invalida!!!\n");
			printf("====================\n");
			escolha = -1;
		}
	}
	printf("\n");
}

void Buscar(Agenda *P, int *T)
{
	int num = 0, i = 0, certo = 0;
	while (certo == 0)
	{
		printf("\n==========================================\nInsira o numero do paciente para busca: ");
		scanf("%d%*c", &num);
		printf("==========================================\n");
		if (num >= 0 && num < *T)
		{

			certo = 1;
		}
		else
		{
			printf("\n=========================================\n");
			printf("O n�mero do paciente digitado n�o existe!");
			printf("\n=========================================\n");
		}
	}
	printf("\n=========================\nBusca do Paciente N:%d\n=========================\n", num);
	printf("Nome: %s", P[num].nome);
	printf("Telefone: %s", P[num].telefone);
	printf("E-mail: %s", P[num].email);
	printf("RG: %s", P[num].rg);
	printf("CPF: %s", P[num].cpf);
	printf("Tipo Sanguineo: %s", P[num].sangueT);
	printf("Operadora do Convenio: %s", P[num].convenio);
	printf("Religiao: %s", P[num].religiao);
	printf("Cidade: %s", P[num].cidade);
	printf("Estado: %s", P[num].estado);
	printf("\n=========================\n\n");
}

void GravarBinario(Agenda *P, int *T)
{
	int i = 0;
	FILE *file = fopen("ArquivoB.txt", "wb");
	for (i = 0; i < *T; i++)
	{
		fwrite(P + i, sizeof(struct Agenda), 1, file);
	}
	fclose(file);
	printf("\n==========================================\nArquivo gravado em binario com sucesso!!!\n==========================================\n\n");
}

void LerBinario()
{
	struct Agenda P[100];
	FILE *file = fopen("ArquivoB.txt", "rb");

	if (file == NULL)
	{
		printf("\n========================================\nO arquivo binario nao existe :( \n========================================\n\n");
		fclose(file);
		exit(1);
	}
	else
	{

		int i = 0;
		while (!feof(file))
		{
			fread(P + i, sizeof(struct Agenda), 1, file);
			i++;
		}
		for (int j = 0; j < i; j++)
		{
			{
				printf("\n=========================\nPaciente N:%d\n=========================\n", j);
				printf("Nome: %s", P[j].nome);
				printf("Telefone: %s", P[j].telefone);
				printf("E-mail: %s", P[j].email);
				printf("RG: %s", P[j].rg);
				printf("CPF: %s", P[j].cpf);
				printf("Tipo Sanguineo: %s", P[j].sangueT);
				printf("Operadora do Convenio: %s", P[j].convenio);
				printf("Religiao: %s", P[j].religiao);
				printf("Cidade: %s", P[j].cidade);
				printf("Estado: %s", P[j].estado);
				printf("\n=========================\n\n");
			}
		}
		printf("\n===================================\nArquivo binario lido com sucesso!!!\n===================================\n\n");
	}
	fclose(file);
}

void GravarTexto(Agenda *P, int *T)
{
	int i = 0;
	FILE *file = fopen("ArquivoT.txt", "wb");
	fprintf(file, "AGENDA ELETRONICA\n\n");
	for (i = 0; i < *T; i++)
	{
		fprintf(file, "==============================\nPaciente N:%d\n==============================\n", i);
		fprintf(file, "Nome: %s\n", P[i].nome);
		fprintf(file, "Telefone: %s\n", P[i].telefone);
		fprintf(file, "E-mail: %s\n", P[i].email);
		fprintf(file, "RG: %s\n", P[i].rg);
		fprintf(file, "CPF: %s\n", P[i].cpf);
		fprintf(file, "Tipo sanguineo: %s\n", P[i].sangueT);
		fprintf(file, "Operadora do Convenio: %s\n", P[i].convenio);
		fprintf(file, "Religiao: %s\n", P[i].religiao);
		fprintf(file, "Cidade: %s\n", P[i].cidade);
		fprintf(file, "Estado: %s\n", P[i].estado);
		fprintf(file, "==============================\n\n\n");
	}
	fclose(file);
	printf("\n========================================\nArquivo gravado em texto com sucesso!!!\n========================================\n\n");
}

void LerTexto()
{
	int i = 0;
	FILE *file = fopen("ArquivoT.txt", "r");
	if (file == NULL)
	{
		printf("\n========================================\nO arquivo de texto n�o existe :( \n========================================\n\n");
		fclose(file);
		exit(1);
	}
	else
	{
		char ch;
		printf("\n");
		while ((ch = fgetc(file)) != EOF)
		{
			putchar(ch);
		}
		printf("\n========================================\nArquivo lido com sucesso!!!\n========================================\n\n");
		printf("\n\n");
		fclose(file);
	}
}

int main(int argc, char *argv[])
{

	Agenda paciente[100];
	int *T = malloc(sizeof(int));

	*T = 0;
	int escolha = 0;
	LerBinario();
	while (escolha != 10)
	{
		printf("++++++++++++++++++++++++++++\n");
		printf("Agenda Eletronica\n");
		printf("++++++++++++++++++++++++++++\n");
		printf("Inserir(1)\n");
		printf("Listar(2)\n");
		printf("Remover(3)\n");
		printf("Alterar(4)\n");
		printf("Buscar(5)\n");
		printf("Gravar em Binario(6)\n");
		printf("Ler em Binario(7)\n");
		printf("Gravar em Texto(8)\n");
		printf("Ler em Texto(9)\n");
		printf("Sair(10)\n");
		printf("++++++++++++++++++++++++++++\n");
		printf("Escolha uma das acoes acima!\n");
		printf("++++++++++++++++++++++++++++\n");
		scanf("%d%*c", &escolha);

		if (escolha == 1)
		{
			Inserir(paciente, T);
			escolha = 0;
		}
		else if (escolha == 2)
		{
			if (*T == 0)
			{
				printf("\n========================================================");
				printf("\nNao eh possivel listar se voce nao inseriu nada ainda ;)");
				printf("\n========================================================\n\n");
			}
			else
			{
				Listar(paciente, T);
			}
			escolha == 0;
		}
		else if (escolha == 3)
		{
			if (*T == 0)
			{
				printf("\n=========================================================");
				printf("\nNao eh possivel remover se voce nao inseriu nada ainda ;)");
				printf("\n=========================================================\n\n");
			}
			else
			{
				Remover(paciente, T);
			}
			escolha == 0;
		}
		else if (escolha == 4)
		{
			if (*T == 0)
			{
				printf("\n=========================================================");
				printf("\nNao eh possivel alterar se voce nao inseriu nada ainda ;)");
				printf("\n=========================================================\n\n");
			}
			else
			{
				Alterar(paciente, T);
			}
			escolha == 0;
		}
		else if (escolha == 5)
		{
			if (*T == 0)
			{
				printf("\n========================================================");
				printf("\nNao eh possivel buscar se voce nao inseriu nada ainda ;)");
				printf("\n========================================================\n\n");
			}
			else
			{
				Buscar(paciente, T);
			}
			escolha == 0;
		}
		else if (escolha == 6)
		{
			if (*T == 0)
			{
				printf("\n===================================================================");
				printf("\nNao eh possivel gravar em binario se voce nao inseriu nada ainda ;)");
				printf("\n===================================================================\n\n");
			}
			else
			{
				GravarBinario(paciente, T);
			}
			escolha == 0;
		}

		else if (escolha == 7)
		{
			LerBinario();
			escolha == 0;
		}

		else if (escolha == 8)
		{
			if (*T == 0)
			{
				printf("\n=================================================================");
				printf("\nNao eh possivel gravar em texto se voce nao inseriu nada ainda ;)");
				printf("\n=================================================================\n\n");
			}
			else
			{
				GravarTexto(paciente, T);
			}
			escolha == 0;
		}

		else if (escolha == 9)
		{
			LerTexto();
			escolha == 0;
		}

		else if (escolha == 10)
		{
			GravarBinario(paciente, T);
			GravarTexto(paciente, T);
			printf("\n++++++\n");
			printf("Adeus!");
			printf("\n++++++\n\n");
		}
		else
		{
			printf("Acao invalida\n");
			escolha == 0;
		}
	}
	free(T);
	system("pause");
	return 0;
}
