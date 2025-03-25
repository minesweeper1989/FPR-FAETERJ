/*Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.*/
#include<stdio.h>
#include<string.h>

int str_len (char str[]);
void str_cpy (char str1[], char str2[]);
void str_cat (char str1[], char str2[]);
int str_cmp (char str1[], char str2[]);

int main (){
	char string1[50], novo[50];
	
	printf("digite a primeira palavra: ");
	gets(string1);
	//fgets(string1, sizeof(string1), stdin);
	
	printf("\nRESULTADOS\nstrlen: %d", str_len(string1));
	
	str_cpy(novo, string1);
	str_cat(string1, "MINESWEEPER");
	printf("\nstrcpy: %s", novo);
	printf("\nstrcat: %s", string1);
	
	if(str_cmp(string1, "MINESWEEPER")>0){
		printf("\nstring 1 e maior");
	}
	else if(str_cmp(string1, "MINESWEEPER")<0){
		printf("\nstring 2 e maior");
	}
	else{
		printf("\nambos sao iguais");
	}
	
	return 0;
}

int str_len (char str[]){
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}

void str_cpy (char str1[], char str2[]){
	int i;
	for(i=0;str2[i]!='\0';i++){
		str1[i]=str2[i];
	}
	str1[i]='\0';
}

void str_cat (char str1[], char str2[]){
	int i, j;
	for(i=0, j=str_len(str1);str2[i]!='\0';i++, j++){
		str1[j]=str2[i];
	}
	str1[j]='\0';
}

int str_cmp (char str1[], char str2[]){
	int i;
	for (i=0;(str1[i]==str2[i]) && (str1[i]) && (str2[i]);i++);

	return str1[i]-str2[i];
}
