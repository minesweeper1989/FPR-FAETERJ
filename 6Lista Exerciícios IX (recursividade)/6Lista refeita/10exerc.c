/*Questão 10:
Implementar uma função recursiva que,
dados uma string str e um caracter ch,
remova de str todas as ocorrências de ch,
retornando o total de remoções realizadas.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int remocao (char s[], char ch, int i);

int main (){
	char s[100], caractere;
	printf("insira uma palavra: ");
	fgets(s, sizeof(s), stdin);
	printf("escolha a letra que deseja remover: ");
	scanf(" %c", &caractere);
	
	s[strcspn(s, "\n")] = '\0';
	
	printf("\ntotal de remocoes: %d\nstring modificada: %s", remocao(s, caractere, 0), s);
	
	return 0;
}

int remocao (char s[], char ch, int i){
	if(s[i]=='\0'){
		return 0;
	}
	if(s[i]==ch){
		int j;
		for(j=i;s[j]!='\0';j++){
			s[j]=s[j+1];
		}
		i--;
		return 1 + remocao(s, ch, i+1);
	}
	return remocao(s, ch, i+1);
}
