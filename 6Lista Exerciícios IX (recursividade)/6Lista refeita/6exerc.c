/*Questão 06:
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int palindromo (char s[], int i, int j);
int main (){
	char s[100];
	printf("insira uma palavra: ");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s, "\n")] = '\0';
	
	int inicio=0, fim=strlen(s)-1;
	
	printf("sua palavra %s um palindromo.", palindromo(s, inicio, fim)==1?"e":"nao e");
	
	return 0;
}

int palindromo (char s[], int i, int j){
	if(s[i]!=s[j]){
		return 0;
	}
	if(i>=j){
		return 1;
	}
	return palindromo(s, i+1, j-1);
}
