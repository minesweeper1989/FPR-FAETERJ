/*
Questão 02:
Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que “troque” os elementos de duas colunas
c1 e c2, respeitadas as seguintes regras:
a. A troca só será possível se as colunas c1 e c2 existirem na matriz. Caso existam, a troca será realizada e o valor 1
retornado pela função; por outro lado, 0 será retornado se uma ou as duas colunas forem inválidas;
b. Após a troca, a coluna c2 conterá exatamente os elementos originais da coluna c1, na mesma ordem. Porém, os
valores da coluna c1 serão os originais da c2, na ordem inversa.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int troca (int linha, int coluna, int coluna1, int coluna2, int matriz[linha][coluna]);
void aleatorizador (int linha, int coluna, int limite, int matriz[linha][coluna]);
void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]);

int main (){
	int lin, col, c1, c2;
	printf("insira a quantidade de linhas e colunas que voce deseja para sua matriz: ");
	scanf("%d %d", &lin, &col);
	
	int m[lin][col];
	
	printf("\nmatriz:\n");
	aleatorizador(lin, col, 10, m);
	exibirmatriz(lin, col, m);
	
	printf("\nescolha duas colunas para trocar:\nc1 = ");
	scanf("%d", &c1);
	printf("c2 = ");
	scanf("%d", &c2);
	
	printf("\n\nresultado:\n");
	troca(lin, col, c1, c2, m);
	exibirmatriz(lin, col, m);
	
	
	return 0;
}

int troca (int linha, int coluna, int coluna1, int coluna2_inv, int matriz[linha][coluna]){
	int i, j, inv_temp[linha];
	coluna1--;
	coluna2_inv--;
	if(coluna1<0 || coluna1>=coluna || coluna2_inv<0 || coluna2_inv>=coluna){
		return 0;
	}
	
	for(i=0, j=linha-1;i<linha; i++,j--){
		inv_temp[j]=matriz[i][coluna2_inv];
		matriz[i][coluna2_inv]=matriz[i][coluna1];
	}
	
	for(i=0;i<linha;i++){
		matriz[i][coluna1]=inv_temp[i];
	}
	
	return 1;
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
