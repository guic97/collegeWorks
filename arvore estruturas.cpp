#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 50
#define R -1
#define D 1
#define E 0

struct str_no {
	char dado;
	int esq;
	int dir;
	int pai;
};

struct str_no arvore[tamanho];
int lado, indice=0;
int op=-1;
char pai, no;

void inserir(int pai, char dado, int lado);
int procurar(char dado);
void mostrar(void);

int main(){
setlocale(LC_ALL,"");
	int temp;
	do {
		mostrar();
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("\nDigite o valor do pai: ");
				scanf("%c", &pai);
				scanf("%c", &pai);
				printf("\nDigite o valor do nó: ");
				scanf("%c", &no);
				scanf("%c", &no);
				printf("Digite o lado da subarvore (E= %d/D= %d/R= %d) : ", E,D,R);
				scanf("%d", lado);
				temp = procurar(pai);
				inserir(temp,no,lado);
				break;
			case 2:
				printf("Digite o valor do nó: ");
				scanf("%c",&no);
				scanf("%c",&no);
				temp = procurar(no);
				printf("No: %c\nFilho Esquerda: %c\nFilho Direita: %c\n\n", arvore[temp].dado, arvore[arvore[temp].esq].dado, arvore[arvore[temp].dir].dado);
				system("pause");
				break;	
		}
	}while (op!=0);
	system("pause");
	return(0);
}

void inserir (int pai, char dado, int lado){
	switch (lado){
		case E:
			arvore[pai].esq = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esq = -1;
			arvore[indice].dir = -1;
			indice++;
		break;
		case D:
			arvore[pai].dir = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].dir = -1;
			arvore[indice].esq = -1;
			indice++;
		break;
		case R:
			arvore[indice].dado = dado;
			arvore[indice].pai = -1;
			arvore[indice].esq = -1;
			arvore[indice].dir = -1;
			indice++;
		break;
	break;
	}
}

void mostrar(void){
	system("cls");
	for (int i = 0; i < indice; i++){
		printf("| %c ", arvore[i].dado);
	}
	printf("\n1 - Inserir um nó na arvore");
	printf("\n2 - Pesquisar um nó na arvore");
	printf("\n0 - Sair...\n\n");
}

int procurar (char dado) {
	if (indice != 0) {
		for (int i = 0; i < indice; i++){
			if (arvore[i].dado == dado){
				return (i);
			}
		}
	}
	else {
		return (0);
	}
}
