/*Questão 02:
Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa.*/
#include<stdio.h>
#include<string.h>

int palindromo(char s[]);

int main (){
	char s[50];
	
	printf("insira seu nome: ");
	fgets(s, sizeof(s), stdin);

	
	printf("\nseu nome %s", palindromo(s)==1? "e um palindromo!":"nao e um palindromo.");
	
	return 0;
}

int palindromo(char s[]){
	int i, j;
	for(i=0, j=strlen(s)-2; i<j ;i++, j--){
		if(s[i]!=s[j]){
			return 0;
		}
	}
	return 1;
}
