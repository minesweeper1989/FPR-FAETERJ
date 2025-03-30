/*Questão 10:
Implementar uma função recursiva que,
dados uma string str e um caracter ch,
remova de str todas as ocorrências de ch,
retornando o total de remoções realizadas.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int remocao (char str[], char ch, int i, int cont);

int main (){
	char str[]="MINESWEEPER", ch;
	int i=0, cont=0;
	printf("%s\nselecione a letra que voce deseja remover: ", str);
	scanf("%c", &ch);
	
	printf("\nforam removidos %d caracteres.", remocao (str, ch, i, cont));
	
	return 0;
}

int remocao (char str[], char ch, int i, int cont){
	if(str[i]=='\0'){
		return cont;
	}
	if(str[i]==ch){
		cont++;
	}
	remocao(str, ch, i+1, cont);
}


/*
int remocao (char str[], char ch, int i, int cont){
	if(str[i]=='\0'){
		return cont;
	}
	if(str[i]==ch){
		cont++;
		while(str[i+1]!=ch && str[i+1]!='\0'){
			str[i]=str[i+1];
			i++;
		}
	}
	remocao(str, ch, i+1, cont);
}*/
