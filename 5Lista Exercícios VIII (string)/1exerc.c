/*
Questão 01:
Implementar uma função que, dada uma string
s, determine a quantidade de caracteres
distintos em s.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int distintos(char str[]);

int main (){
	char string[100];
	printf("insira uma string: ");
	fgets(string, sizeof(string), stdin);
	
	string[strcspn(string, "\n")] = '\0';
	
	printf("\nsua string tem %d caracteres distintos.", distintos(string));
	
	return 0;
}

int distintos(char str[]){
	int i, j, repetido, unica=0;
	
	for(i=0;str[i]!='\0';i++){
		repetido=1;
		for(j=0;str[j] != '\0';j++){
			if(str[i]==str[j] && i!=j){
				repetido=0;
				break;
			}
		}
		if(repetido){
			unica++;
		}
	}
	return unica;
}
