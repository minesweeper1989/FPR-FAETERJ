/*Questão 04:
Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/
#include<stdio.h>
#include<string.h>

void remover (char s[], char p);

int main (){
	char s[11]="MINESWEEPER", letra;
	
	printf("%s\nescolha uma letra: ", s);
	scanf("%c", &letra);
	
	remover(s, letra);
	printf("\nstring atualizada: %s", s);
}

void remover (char s[], char p){
	int i, j=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]!=p){
			s[j]=s[i];
			j++;
		}
	}
	s[j]='\0';
}
