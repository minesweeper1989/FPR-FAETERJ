/*Questão 06:
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int palindromo (char s[], int i, int f);

int main (){
	char s[100];
	printf("crie uma string: ");
	fgets(s, sizeof(s), stdin);
	
	s[strcspn(s, "\n")] = '\0';
	
	int inicio=0, fim=strlen(s)-1;
	printf("\nsua string %s", palindromo(s, inicio, fim)==1 ? "e um palindromo.":"nao e um palindromo.");
	
	return 0;
}

int palindromo (char s[], int i, int f){
	if(s[i]!=s[f]){
		return 0;
	}
	if(i>=f){
		return 1;
	}

	palindromo(s, i+1, f-1);
}
