/*Questão 03:
Desenvolver uma função recursiva que exiba
todos os múltiplos do número N, inferiores ou
iguais ao valor V.*/
#include<stdio.h>
#include<stdlib.h>
void recursiva_teste(int numero, int maximo);

int main (){
	int n, v;
	printf("insira um numero: ");
	scanf("%d", &n);
	printf("\nagora insira o limite: ");
	scanf("%d", &v);
	
	printf("\n\ntodos os multiplos de %d inferiores a %d:", n, v);
	recursiva_teste(n, v);
	
	return 0;
}

void recursiva_teste(int numero, int maximo){
	if(numero<=maximo){
		recursiva_teste(numero, maximo-numero);
		printf(" %d", maximo);
	}
}
