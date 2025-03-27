/*Questão 02:
Implementar uma função que, dadas uma matriz M de inteiros (com lin linhas e col colunas) e duas colunas c1 e c2, inverta
a ordem (por linha) dos elementos compreendidos entre estas colunas.
Exemplo:
  c1   c2
1 2 4 8 6 2 0
9 7 4 0 3 1 0
8 8 4 1 2 0 1
4 7 2 1 5 4 8
2 1 2 4 0 1 0
1 8 7 2 1 3 6
9 4 5 2 0 3 2
0 1 3 5 6 9 8
7 4 1 2 3 5 0


  c1   c2
1 6 8 4 2 2 0
9 3 0 4 7 1 0
8 2 1 4 8 0 1
4 5 1 2 7 4 8
2 0 4 2 1 1 0
1 1 2 7 8 3 6
9 0 2 5 4 3 2
0 6 5 3 1 9 8
7 3 2 1 4 5 0

Nota: se as colunas c1 e c2 forem inválidas, nada será realizado e o valor 0 retornado pela função; caso contrário,
a inversão dos elementos será feita e o código 1 retornado.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int troca (int linha, int coluna, int col1, int col2, int matriz[linha][coluna]);
void aleatorizador (int linha, int coluna, int limite, int matriz[linha][coluna]);
void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]);

int main (){
	int lin, col, c1, c2;
	printf("quantas linhas e colunas voce deseja que sua matriz tenha?\nR: ");
	scanf("%d %d", &lin, &col);
	int m[lin][col];
	
	printf("\nmatriz:\n");
	
	aleatorizador(lin, col, 10, m);
	exibirmatriz(lin, col, m);
	
	printf("\nescolha duas colunas:\nc1 = ");
	scanf("%d", &c1);
	printf("c2 = ");
	scanf("%d", &c2);
	
	if((troca(lin, col, c1, c2, m))==1){
		printf("\nmatriz trocada:\n");
		exibirmatriz(lin, col, m);
	}
	else{
		printf("\ncolunas invalidas.");
	}
	
	return 0;
}

int troca (int linha, int coluna, int col1, int col2, int matriz[linha][coluna]){
	int i, temp, inicio, fim;
	col1--;
	col2--;
	if(col1>=col2 || col1<0 || col2>=coluna){
		return 0;
	}
	
	for(i=0;i<linha;i++){
		inicio=col1;
		fim=col2;
		while(inicio<fim){
			temp=matriz[i][inicio];
			matriz[i][inicio]=matriz[i][fim];
			matriz[i][fim]=temp;
			inicio++;
	        fim--;
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
