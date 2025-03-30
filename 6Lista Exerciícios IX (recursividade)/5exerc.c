/*Questão 05:
Pede-se a implementação de uma função
recursiva que exiba os n primeiros termos de
uma PG (Progressão Geométrica), onde a1 é o
seu primeiro termo e q a razão.

formula: An = A1 . Q^n-1*/
#include<stdio.h>
#include<stdlib.h>

void PG (int quant, int razao, int primeiro);

int main (){
	int n, A1, Q;
	printf("PROGRESSAO GEOMETRICA\n\n1. o primeiro termo da sua PG: ");
	scanf("%d", &A1);
	printf("\n2. a razao da sua PG: ");
	scanf("%d", &Q);
	printf("\n3. a quantidade de termos da sua PG: ");
	scanf("%d", &n);
	
	printf("\n\nsua PG:");
	PG(n, Q, A1);
	
	return 0;
}

void PG (int quant, int razao, int primeiro){
	if(quant>0){
		//a1, a2, a3, a4.. an
		printf(" %d", primeiro);
		PG(quant-1, razao, primeiro*razao);
	}
}
