/*Questão 05:
Pede-se a implementação de uma função
recursiva que exiba os n primeiros termos de
uma PG (Progressão Geométrica), onde a1 é o
seu primeiro termo e q a razão.

formula: An = A1 . Q^n-1*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void PG (int primeiro, int razao, int quant);

int main (){
	int n, A1, Q;
	printf("PROGRESSAO GEOMETRICA\n\n1. o primeiro termo da sua PG: ");
	scanf("%d", &A1);
	printf("\n2. a razao da sua PG: ");
	scanf("%d", &Q);
	printf("\n3. a quantidade de termos da sua PG: ");
	scanf("%d", &n);
	
	printf("\n\nsua PG:");
	PG(A1, Q, n);
	
	return 0;
}

void PG (int primeiro, int razao, int quant){
	int termo;
	if(quant!=0){
		termo=primeiro*pow(razao,quant-1);
		PG(primeiro, razao, quant-1);
		printf(" %d", termo);
	}
}
