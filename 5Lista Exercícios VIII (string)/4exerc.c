/*
Questão 04:
Desenvolver uma função que remova de uma
string s os caracteres compreendidos entre as
posições p1 e p2.
Caso p1 ou p2 seja uma posição inválida, a
função deverá retornar o valor 0 e a remoção de
caracteres solicitada não será realizada; caso
contrário, deverá retornar 1 e proceder com o
que foi pedido.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int remocao (char str[], int p1, int p2);

int main (){
	char string[100];
	int posicao1, posicao2;
	printf("insira uma string: ");
	fgets(string, sizeof(string), stdin);
	
	string[strcspn(string, "\n")] = '\0';
	
	printf("\ninsira duas posicoes: ");
	scanf("%d %d", &posicao1, &posicao2);
	
	if(remocao(string, posicao1, posicao2)==0){
		printf("\nposicao invalida.");
	}
	else{
		printf("\n\nresultado: %s", string);
	}
	
	return 0;
}

int remocao (char str[], int p1, int p2){
	int i, j=0, tam;
	tam=strlen(str);
	p1--;
	p2--;
	if(p1>p2 || p1<0 || p2>tam){
		return 0;
	}
	
	for(i=0; i<tam; i++){
		if(i<p1 || i>p2){
			str[j++]=str[i];
		}
	}
	str[j]='\0';
	
	return 1;
}
