/*
Desenvolver uma função que, dadas duas strings s1 e
s2, determine o número de caracteres que são comuns às duas cadeias de caracteres.
Nota: sua solução deve, obrigatoriamente, fazer uso de recursividade.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int comum_rec (char s1[], char s2[], int c, int i, int j);

int main (){
	char string1[100], string2[100]; 
	int comum=0, i=0, j=0;
	printf("crie duas string:\nstring 1 = ");
	fgets(string1, sizeof(string1), stdin);
	printf("string 2 = ");
	fgets(string2, sizeof(string2), stdin);
	
	string1[strcspn(string1, "\n")] = '\0';
	string2[strcspn(string2, "\n")] = '\0';
	
	printf("\ncaracteres em comum: %d", comum_rec(string1, string2, comum, i, j));
	
	return 0;
}

int comum_rec (char s1[], char s2[], int c, int i, int j){
	if(s2[j]=='\0'){
		return c;
	}
	if(s1[i]=='\0'){
		return comum_rec(s1, s2, c, 0, j+1);
	}

	if(s1[i]==s2[j]){
		return comum_rec(s1, s2, c+1, i+1, j);
	}
	return comum_rec(s1, s2, c, i+1, j);

}
