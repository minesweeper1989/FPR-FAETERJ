/*Questão 04:
Considere a existência de uma matriz M, contendo números reais, com x linhas e y colunas. Pede-se a implementação de
uma função que, a partir de M, gere dois vetores, conforme descritos a seguir:
? V1, com x posições, de forma que cada posição i do vetor armazene quantos elementos da linha i de M são múltiplos
do primeiro valor desta linha (excluindo o próprio primeiro número);
? V2, com y posições, de forma que cada posição i do vetor armazene quantos elementos da coluna i de M são múltiplos
do primeiro valor desta coluna (excluindo o próprio primeiro número).*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void gerador (int linha, int coluna, int matriz[linha][coluna], int v1[linha], int v2[coluna]);
void aleatorizador (int linha, int coluna, int limite, int matriz[linha][coluna]);
void exibirvetor (int tamanho, int vet[tamanho]);
void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]);

int main (){
	int x, y;
	printf("quantas linhas e colunas voce deseja que sua matriz tenha?\nR: ");
	scanf("%d %d", &x, &y);
	int m[x][y], v1[x], v2[y];
	
	printf("\nmatriz:\n");
	aleatorizador(x, y, 9, m);
	exibirmatriz(x, y, m);
	
	gerador(x, y, m, v1, v2);
	printf("\n\nvetor 1: ");
	exibirvetor(x, v1);
	
	printf("\nvetor 2: ");
	exibirvetor(y, v2);
	
	return 0;
}

void gerador (int linha, int coluna, int matriz[linha][coluna], int v1[linha], int v2[coluna]){
	int i, j, cont;
	for(i=0;i<linha;i++){
		cont=0;
		for(j=1;j<coluna;j++){
			if(matriz[i][j] % matriz[i][0]==0){
				cont++;
			}
		}
		v1[i]=cont;		
	}
	
	for(j=0;j<coluna;j++){
		cont=0;
		for(i=1;i<linha;i++){
			if(matriz[i][j] % matriz[0][j] == 0){
				cont++;
			}
		}
		v2[j]=cont;
	}
}

void aleatorizador (int linha, int coluna, int limite, int matriz[linha][coluna]){
	int i, j;
	srand (time(NULL));
	
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			matriz[i][j]=rand()%limite + 1;
		}
	}
}

void exibirvetor (int tamanho, int vet[tamanho]){
	int i;
	for(i=0;i<tamanho;i++){
		printf("%d ", vet[i]);
	}
}

void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]){
	int i, j;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			printf("%3d ", matriz[i][j]);
		}
		printf("\n");
	}
}
