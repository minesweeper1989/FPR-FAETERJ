/*Questão 07:
Desenvolver uma função recursiva que
determine o número de caracteres comuns
entre duas strings s1 e s2.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int similares (char s1[], char s2[], int i, int iguais);

int main (){
	char s1[100], s2[100];
	int inicio=0, iguais=0;
	printf("crie duas strings:\nstring1 = ");
	fgets(s1, sizeof(s1), stdin);
	printf("\nstring2 = ");
	fgets(s2, sizeof(s2), stdin);
	
	s1[strcspn(s1, "\n")] = '\0';
	s2[strcspn(s2, "\n")] = '\0';
	
	printf("\n\nsuas strings tem %d caracteres similares.", similares(s1, s2, inicio, iguais));
	
	return 0;
}

int similares (char s1[], char s2[], int i, int iguais){
	int j;
	if(s1[i]=='\0'){
		return iguais;
	}
	
	for(j=0;s2[j]!='\0';j++){
		if(s1[i]==s2[j]){
			iguais++;
			break;
		}
	}
	similares(s1, s2, i+1, iguais);
}
