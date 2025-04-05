/*
Implementar uma função recursiva que, dados uma string s e 
dois caracteres c1 e c2, substitua todas as ocorrências de c1 
por c2. Além disso, deve ser retornado o número de substituições 
realizadas.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int substituicao (char s[], char c1, char c2, int i, int quant);

int main (){
	char string[100], caracter1, caracter2, i=0, quantidade=0;
	printf("crie uma string: ");
	fgets(string, sizeof(string), stdin);
	
	printf("agora duas caracteres:\nc1 = ");
	scanf(" %c", &caracter1);
	printf("c2 = ");
	scanf(" %c", &caracter2);
	
	quantidade = substituicao (string, caracter1, caracter2, i, quantidade);
	
	if(quantidade){
		printf("\nstring substituida: %s\ncaracteres substituidos: %d", string, quantidade);
	}
	else{
		printf("nao houve substituicoes.");
	}
	
	return 0;
}

int substituicao (char s[], char c1, char c2, int i, int quant){
	if(s[i]=='\0'){
		return quant;
	}
	if(s[i]==c1){
		s[i]=c2;
		return substituicao (s, c1, c2, i+1, quant+1);
	}
	return substituicao (s, c1, c2, i+1, quant);
}

/*
chocolate
o
i
*/
