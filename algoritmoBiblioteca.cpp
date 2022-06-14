#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <locale.h>

typedef struct cadastro
{
	char titulo[50], autor[50], editora[50];
	int edicao, quantidade, ano, caixa, tipo;
	long long int isbn;
} CadastroObra;

void aluno();
void cadastrarObra(CadastroObra obra[MAX]);
void ListarTodasObras(CadastroObra obra[MAX]);
void ListarObraTipo(int buscaTipo, CadastroObra obra[MAX]);
void ListarObraCaixa(int buscaCaixa, CadastroObra obra[MAX]);
int ContarRegistro(CadastroObra obra[MAX]);

int main()
{
	CadastroObra obra[MAX];
	setlocale(LC_ALL, "Portuguese");
	int op, buscaCaixa, buscaTipo;
	do{
		aluno();
		printf("\n1 - CADASTRAR OBRAS");
		printf("\n2 - LISTAR TODAS AS OBRAS");
		printf("\n3 - LISTAR OBRAS POR TIPO");
		printf("\n4 - LISTAR OBRAS POR CAIXA");
		printf("\n0 - SAIR\n");
		printf("\nESCOLHA OPÇÃO: ");
		scanf("%d", &op);
		system("cls");
		
		switch(op){
			case 1:
				cadastrarObra(obra);
				break;
			case 2:
				ListarTodasObras(obra);
				printf("\n");
				system("pause");
				break;
			case 3: 		
				printf("INFORME O TIPO DA OBRA: \n[1] LIVRO [2] REVISTA\n");
				fflush(stdin);
				scanf("%d", &buscaTipo);
				ListarObraTipo(buscaTipo, obra);
				printf("\n");
				system("pause");
				break;
			case 4: 
				printf("INFORME A CAIXA DESEJADA: ");
				fflush(stdin);
				scanf("%d", &buscaCaixa);
				ListarObraCaixa(buscaCaixa, obra);
				printf("\n");
				system("pause");
				break;
			case 0:
				printf("\nSAINDO DO SISTEMA!");
				break;
			default:
				printf("VALOR INVÁLIDO");
				system("pause");
				break;
		}	
	}while(op!=0);
	return 0;
}

void aluno(){
	system("cls");
	int t;
	for(t=0; t<80; t++) printf("-");
    	printf(" \n RA: 200243575\n");
        printf(" NOME: ATILA GUILHERME BAIDA CARRÃO\n");
        printf(" CURSO: ENGENHARIA DE SOFTWARE\n");
	for(t=0; t<80; t++) printf("-");
}
void cadastrarObra(CadastroObra obra[MAX])
{
	char resp='s';
	aluno();
	int i=0;
	FILE * arq;
 	arq = fopen("testes.txt", "a+");

	if(arq != NULL)
	{
		while(resp=='s'||resp=='S')
		{
			printf("\nINFORME OS DADOS DA OBRA:");
			printf("\nTITULO: ");
			fflush(stdin);
			gets(obra[i].titulo);
			printf("\nAUTOR: ");
			fflush(stdin);
			gets(obra[i].autor);
			printf("\nEDITORA: ");
			fflush(stdin);
			gets(obra[i].editora);
			printf("\nNÚMERO DA CAIXA: ");
			fflush(stdin);
			scanf("%d", &obra[i].caixa);
			printf("\nTIPO DA OBRA: \n[1] LIVRO [2] REVISTA\n");
			fflush(stdin);
			scanf("%d", &obra[i].tipo);
			fwrite(&obra[i], sizeof(CadastroObra), 1, arq);
			
			system("cls");
			printf("\nDESEJA CONTINUAR A CADASTRAR? NÃO [n] - SIM [s]\n");
			fflush(stdin);
			scanf("%c", &resp);
			system("cls");
		}
		fclose(arq); 
	}
	else
	{
		printf("\nERRO DE LEITURA!\n");
		exit(1); 
	}
}

int ContarRegistro(CadastroObra obra[MAX])
{
	FILE * arq = fopen("testes.txt", "r");
	if(arq != NULL)
	{
		int contador = 0;
		while(1)
		{
			CadastroObra p;
		
			//int registro = fread(&p, sizeof(CadastroObra), 1, arq);
			 size_t registro = fread(&p, sizeof(CadastroObra), 1, arq);
			
			if(registro < 1)
				break;
			else
				obra[contador++] = p;
		}
		fclose(arq); 
		return contador;
	}
	else
	{
		printf("\nERRO DE LEITURA!\n");
		exit(1);
	}
}

void ListarTodasObras(CadastroObra obra[MAX])
{	
	aluno();
	
	int quantidade = ContarRegistro(obra);
	int i;
	
	printf("\n------- LISTA DE OBRAS [%d] ------- \n\n", quantidade);
	
	for(i = 0; i < quantidade; i++)
	{
		printf("\n[OBRA N° %d]:\n TITULO: %s\t AUTOR: %s\t\n EDITORA: %s\t CAIXA: %d\t TIPO: %d\t\n\n\n", i+1, obra[i].titulo, obra[i].autor, obra[i].editora, obra[i].caixa, obra[i].tipo);
	}
}

void ListarObraTipo(int buscaTipo, CadastroObra obra[MAX]){	
	aluno();
	
	int quantidade = ContarRegistro(obra);
	int i;
	
	printf("\n------- LISTA DE OBRAS POR TIPO ------- \n\n");
	if (buscaTipo == 1) 
	{
		printf("TIPO PESQUISADO [1]: LIVRO \n");	
	}else if (buscaTipo == 2) 
	{
		printf("TIPO PESQUISADO [2]: REVISTA \n");	
	}
	
	for(i = 0; i < quantidade; i++)
	{
		if(obra[i].tipo == buscaTipo)
		{
			printf("\n[OBRA N° %d]:\n TITULO: %s\t AUTOR: %s\t\n EDITORA: %s\t CAIXA: %d\t TIPO: %d\t\n\n\n", i+1, obra[i].titulo, obra[i].autor, obra[i].editora, obra[i].caixa, obra[i].tipo);	
		}
	}
}
void ListarObraCaixa(int buscarCaixa, CadastroObra obra[MAX])
{
	aluno();
	
	int quantidade = ContarRegistro(obra);
	int i;
	
	printf("\n------- LISTA DE OBRAS POR CAIXA ------- \n");
	printf("CAIXA PESQUISADA: %d \n", buscarCaixa);
	
	for(i = 0; i < quantidade; i++)
	{
		if(obra[i].caixa == buscarCaixa)
		{
			printf("\n[OBRA N° %d]:\n TITULO: %s\t AUTOR: %s\t\n EDITORA: %s\t CAIXA: %d\t TIPO: %d\t\n\n\n", i+1, obra[i].titulo, obra[i].autor, obra[i].editora, obra[i].caixa, obra[i].tipo);	
		}
	}
}
