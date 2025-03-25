/*
Questão 03:
Desenvolver uma função, em C, que, dada uma
string s e dada uma posição p desta string, crie duas
novas strings: s1 com os caracteres de s das
posições 0 a p-1; e s2 com os caracteres de s da
posição p à última.
Nota: Caso p seja uma posição inválida, a função
deverá retornar o valor 0; caso contrário,
procederá com a criação das duas strings e
retornará o valor 1.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nova (char str[], char str1[], char str2[], int p);

int main (){
	char string[100], string1[100], string2[100];
	int posicao;
	printf("insira uma string: ");
	fgets(string, sizeof(string), stdin);
	
	string[strcspn(string, "\n")] = '\0';
	
	printf("\nescolha uma posicao: ");
	scanf("%d", &posicao);
	
	if(nova(string, string1, string2, posicao)==0){
		printf("\nposicao invalida.");
	}
	else{
		printf("\nNOVAS STRINGS. . .\nstring 1: %s\nstring 2: %s", string1, string2);
	}
	
	return 0;
}

int nova (char str[], char str1[], char str2[], int p){
	int i, tam;
	tam=strlen(str);
	
	if(p>tam || p<0){
		return 0;
	}
	
	p--;
	for(i=0; i<tam ; i++){
		if(i<p){
			str1[i]=str[i];
		}
		else{
			str2[i-p]=str[i];
		}
	}
	str1[p]='\0';
	str2[i]='\0';

	return 1;
}
