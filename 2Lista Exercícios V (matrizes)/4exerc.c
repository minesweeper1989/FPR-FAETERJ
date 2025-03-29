/*
Questão 04:
Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que verifique se os elementos da matriz estão
ordenados de forma crescente. Para isto, as seguintes regras devem ser atendidas:
a. Os elementos de cada linha devem estar ordenados crescentemente (ou seja, cada elemento será maior ou igual
àquele da mesma linha, porém da coluna anterior – caso exista);
b. O primeiro elemento de cada linha deve ser maior ou igual ao último da linha anterior (caso exista).
Caso a matriz M atenda aos critérios definidos, o valor 1 deverá ser retornado pela função; caso contrário, 0.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void aleatorizador (int linha, int coluna, int limite, int matriz[linha][coluna]);
void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]);
int crescente (int linha, int coluna, int matriz[linha][coluna]);

int main (){
	int lin, col, m[lin][col];
	
	printf("quantas linhas e colunas tera sua matriz?\nR: ");
	scanf("%d %d", &lin, &col);
	
	printf("\nmatriz:\n");
	aleatorizador(lin, col, 10, m);
	exibirmatriz(lin, col, m);
	
	printf("\na sua matriz %s", (crescente(lin, col, m)==1) ? "e crescente." : "nao e crescente.");
	
	return 0;
}

int crescente (int linha, int coluna, int matriz[linha][coluna]){
	int i, j;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			if(j>0 && matriz[i][j]<matriz[i][j-1]){
				return 0;
			}
			if(i>0 && matriz[i][0]<matriz[i-1][coluna-1]){
				return 0;
			}
			
		}
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
