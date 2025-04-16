/*Questão 03:
Desenvolver uma função recursiva que exiba
todos os múltiplos do número N, inferiores ou
iguais ao valor V.*/
#include<stdio.h>

void multiplos (int n, int v, int multiplo); 

int main (){
	int n, v;
	printf("insira dois numeros: ");
	scanf("%d %d", &n, &v);
	
	int multiplo=n;
	
	printf("\nmultiplos: ");
	multiplos(n, v, multiplo);
	
	return 0;
}

void multiplos (int n, int v, int multiplo){
	if (v<=multiplo){
		return;
	}
	printf("%d ", multiplo);
	multiplos(n, v, multiplo+n);
}
