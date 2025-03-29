/*Questão 01:
Considerando a existência de uma matriz de inteiros M, de ordem N (ou seja, o no de linhas e o no de colunas são iguais a
N), onde N é uma constante, desenvolver uma função que retorne 1 se a seguinte regra for atendida por M (caso contrário,
o valor 0 deverá ser retornado):
? A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que estão acima desta
diagonal, assim como à soma dos elementos abaixo da diagonal.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void aleatorizador (int linha, int coluna, int limite, int matriz[linha][coluna]);
void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]);
int somaelementos (int linha, int coluna, int matriz[linha][coluna]);

int main (){
	int lincol, m[lincol][lincol];
	
	printf("qual tamanho voce deseja que sua matriz tenha?\nR: ");
	scanf("%d", &lincol);
	
	printf("\nmatriz:\n");
	aleatorizador(lincol, lincol, 5, m);
	exibirmatriz(lincol, lincol, m);
	
	printf("\na soma dos elementos da diagonal %s", (somaelementos(lincol, lincol, m)==1) ? "e igual a soma dos elementos acima e abaixo." : "NAO e igual a soma dos elementos acima e abaixo.");
	
	
	return 0;
}

int somaelementos (int linha, int coluna, int matriz[linha][coluna]){
	int i, j, somadiagonal=0, somaacima=0, somaabaixo=0;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			if(j==i){
				somadiagonal+=matriz[i][j];
			}
			else if(j>i){
				somaacima+=matriz[i][j];
			}
			else{
				somaabaixo+=matriz[i][j];
			}
			
		}
	}
	
	if(somadiagonal==somaacima && somadiagonal==somaabaixo){
		return 1;
	}
	else{
		return 0;
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
