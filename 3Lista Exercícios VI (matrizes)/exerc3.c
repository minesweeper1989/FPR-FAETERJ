/*Questão 03:
O conceito de simetria de matrizes considera a diagonal principal como referencial. Porém, supondo que se deseja
determinar se uma matriz é simétrica em relação às colunas, pede-se o desenvolvimento de uma função que, dada uma
matriz de ordem n, verifique se é ou não “simétrica verticalmente”.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define linha 5
#define coluna 7

int simetria (int matriz[linha][coluna]);
void aleatorizador (int limite, int matriz[linha][coluna]);
void exibirmatriz (int matriz[linha][coluna]);

int main (){
	int m[linha][coluna], simetrica[linha][coluna] = {
    {1, 2, 3, 4, 3, 2, 1},
    {5, 6, 7, 8, 7, 6, 5},
    {9, 10, 11, 12, 11, 10, 9},
    {5, 6, 7, 8, 7, 6, 5},
    {1, 2, 3, 4, 3, 2, 1}};
    
    printf("matriz 1:\n");
    exibirmatriz(simetrica);
    printf("\nR: a matriz %s", (simetria(simetrica))==1? "e simetrica.":"NAO e simetrica.");
    
    printf("\n\nmatriz 2:\n");
    aleatorizador(13, m);
    exibirmatriz(m);
    printf("\nR: a matriz %s", (simetria(m))==1? "e simetrica.":"NAO e simetrica.");
	
	return 0;
}

int simetria (int matriz[linha][coluna]){
	int i, j;
	
	for(i=0;i<linha;i++){
		for(j=0;j<=coluna/2;j++){
			if(matriz[i][j]!=matriz[i][coluna-j-1]){
				return 0;
			}
		}
	}
	return 1;
}

void aleatorizador (int limite, int matriz[linha][coluna]){
	int i, j;
	srand (time(NULL));
	
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			matriz[i][j]=rand()%limite;
		}
	}
}
void exibirmatriz (int matriz[linha][coluna]){
	int i, j;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			printf("%3d ", matriz[i][j]);
		}
		printf("\n");
	}
}
