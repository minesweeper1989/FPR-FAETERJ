/*Questão 07:
Desenvolver uma função recursiva que
determine o número de caracteres comuns
entre duas strings s1 e s2.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int comum (char s1[], char s2[], int i, int j);
void sem_repeticao(char s[]);

int main (){
	char s1[100], s2[100];
	printf("insira duas palavras...\npalavra 1: ");
	fgets(s1, sizeof(s1), stdin);
	s1[strcspn(s1, "\n")] = '\0';
	
	printf("\npalavra 2: ");
	fgets(s2, sizeof(s2), stdin);
	s2[strcspn(s2, "\n")] = '\0';
	
	int i=0, j=0;
	
	sem_repeticao(s1);
	sem_repeticao(s2);
	
	printf("as palavras tem %d caracteres em comum.", comum(s1, s2, i, j));
	
	return 0;
}
/*
s1- chococlate
s1- chococlate
s2- menta
e-t-a 3
banana
abacate
*/

//função extra que eu adicionei para garantir que nao tenhacaracteres repetidos(exemplo: banana -> ban)
void sem_repeticao(char s[]){
	int i, j, k;
	
	for(i=0;s[i]!='\0';i++){
		for(j=i+1;s[j]!='\0';j++){
			if(s[i]==s[j]){
				for(k=j;s[k]!='\0';k++){
					s[k]=s[k+1];
				}
				j--;
			}
		}
	}
}

int comum (char s1[], char s2[], int i, int j){
	if(s1[j]=='\0'){
		return 0;
	}
	if(s2[i]=='\0'){
		return comum(s1, s2, i=0, j+1);
	}
	if(s2[i]==s1[j]){
		return 1+comum(s1, s2, i=0, j+1);
	} else{
		return comum(s1, s2, i+1, j);
	}
}








