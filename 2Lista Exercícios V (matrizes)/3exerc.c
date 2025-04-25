/*
Questão 03:
Pede-se o desenvolvimento de uma função recursiva que, dada uma matriz M de L linhas e C colunas, onde L e C são
constantes, e três linhas L1, L2 e L3, altere os elementos de L3, de forma que cada um consista na soma dos elementos
de L1 e L2, conforme ilustrado no exemplo abaixo:


Observação: como essa questão pede uma solução recursiva, pensaremos em sua solução mais adiante.
*/
#include<stdio.h>
#include<stdlib.h>
void soma (int coluna, int m[][coluna], int l1, int l2, int l3, int j);
void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]);
int main (){
	int linha1, linha2, linha3, m[8][4]={{1, 5, 9, 2},
	                       {0, 3, 4, 8},
	                       {1, 1, 3, 7},
	                       {7, 9, 6, 5},
	                       {1, 3, 2, 4},
	                       {8, 6, 8, 7},
	                       {9, 7, 2, 1},
	                       {4, 6, 7, 8}};
	printf("antes:\n");
	exibirmatriz(8, 4, m);
	printf("\nescolha tres linhas: ");
	scanf("%d %d %d", &linha1, &linha2, &linha3);
	
	printf("\ndepois:\n");
	soma(4, m, linha1, linha2, linha3, 0);
	exibirmatriz(8, 4, m);
	
	return 0;
}

void soma (int coluna, int m[][coluna], int l1, int l2, int l3, int j){
	if(m[l3][j]>=coluna);
	else{
		m[l3][j]=m[l1][j]+m[l2][j];
		soma(coluna, m, l1, l2, l3, j+1);
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
