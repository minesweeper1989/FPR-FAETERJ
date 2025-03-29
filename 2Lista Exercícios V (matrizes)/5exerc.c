/*
Questão 05:
Desenvolver uma função que receba duas matrizes de inteiros, ambas de ordem 10, com as seguintes características:
a. M1: matriz contendo números inteiros quaisquer;
b. M2: matriz contendo apenas os valores 0 ou 1.
Desenvolver uma função que a partir destas matrizes gere a matriz M3, também de ordem 10, cujos elementos são
definidos da seguinte forma:
M2ij = 0 ? M3ij = M1ij
M2ij = 1 ? M3ij = soma dos elementos da linha i com os da coluna j da matriz.
*/

#include<stdio.h>

#define lincol 10

void aleatorizador (int linha, int coluna, int limite, int matriz[linha][coluna]);
void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]);
void gerador (int linha, int coluna, int matriz1[linha][coluna], int matriz2[linha][coluna], int matriz3[linha][coluna]);

int main (){
	int m1[lincol][lincol], m2[lincol][lincol], m3[lincol][lincol];
	
	printf("matriz 1:\n");
	aleatorizador(lincol, lincol, 10, m1);
	exibirmatriz(lincol, lincol, m1);
	
	printf("\n\nmatriz 2:\n");
	aleatorizador(lincol, lincol, 2, m2);
	exibirmatriz(lincol, lincol, m2);
	
	printf("\n\nmatriz 3:\n");
	gerador(lincol, lincol, m1, m2, m3);
	exibirmatriz(lincol, lincol, m3);
	
	return 0;
}

void gerador (int linha, int coluna, int matriz1[linha][coluna], int matriz2[linha][coluna], int matriz3[linha][coluna]){
	int i, j, soma;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			if(matriz2[i][j]==0){
				matriz3[i][j]=matriz1[i][j];
			}
			else{
				matriz3[i][j]=0;
				for(soma=0;soma<linha;soma++){
					matriz3[i][j]+=matriz1[soma][j];
				}
				for(soma=0;soma<coluna;soma++){
					matriz3[i][j]+=matriz1[i][soma];
				}
			}
		}
	}
	
}

void aleatorizador (int linha, int coluna, int limite, int matriz[linha][coluna]){
	int i, j;
	srand (time(NULL));
	
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			matriz[i][j]=rand()%limite;
		}
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
