/*Questão 08:
Desenvolver uma função recursiva que, dada
uma string, exiba-a invertida.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void invertida (char s[], int tamanho);

int main (){
	char s[100];
	printf("insira uma string: ");
	fgets(s, sizeof(s), stdin);
	
	s[strcspn(s, "\n")] = '\0';
	int tam=strlen(s)-1;
	
	invertida(s, tam);
	
	return 0;
}

void invertida (char s[], int tamanho){
	if(tamanho>=0){
		printf("%c", s[tamanho]);
		invertida(s, tamanho-1);
	}
}

