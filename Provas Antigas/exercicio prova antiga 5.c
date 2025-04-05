/*
Dada uma matriz M de inteiros (de apenas um algarismo), com x linhas e y colunas, 
desenvolver uma função que crie um vetor V de x posições contendo, em cada posição, 
as "representações numéricas" de cada linha de M, como ilustrado no exemplo abaixo:

M= 1 5 9
   4 2 7
   4 8 8
   2 5 1
   7 1 1

V= 159, 427, 488, 251, 711
*/
#include<stdio.h>
#include<stdlib.h>

void transformar (int lin, int col, int m[lin][col], int vet[col]);
void aleatorizador (int linha, int coluna, int limite, int matriz[linha][coluna]);
void exibirvetor (int tamanho, int vet[tamanho]);
void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]);

int main (){
	int linha, coluna;
	
	printf("insira a quantidade de linhas e colunas da sua matriz: ");
	scanf("%d %d", &linha, &coluna);
	
	int matriz[linha][coluna], vetor[coluna];
	
	aleatorizador(linha, coluna, 9, matriz);
	exibirmatriz(linha, coluna, matriz);
	
	transformar(linha, coluna, matriz, vetor);
	exibirvetor(coluna, vetor);
	
	return 0;
}

void transformar (int lin, int col, int m[lin][col], int vet[col]){
	int i, j;
	for(i=0;i<lin;i++){
		vet[i]=0;
		for(j=0;j<col;j++){
			vet[i] = vet[i] * 10 + m[i][j];	
		}
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
	printf("\nvetor: ");
	for(i=0;i<tamanho;i++){
		printf("%d ", vet[i]);
	}
}

void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]){
	int i, j;
	printf("\nmatriz:\n");
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			printf("%3d ", matriz[i][j]);
		}
		printf("\n");
	}
}
