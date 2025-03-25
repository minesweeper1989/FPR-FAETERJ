/*
Questão 02:
Implementar uma função que, dadas duas
strings s1 e s2, crie uma nova string – s3 –
contendo todos os caracteres de s1 que não
estejam em s2.
Nota: em s3, não devem existir caracteres
repetidos.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void nova (char str1[], char str2[], char str3[]);

int main (){
	char string1[100], string2[100], string3[100];
	printf("insira uma string: ");
	fgets(string1, sizeof(string1), stdin);
	printf("\ninsira outra string: ");
	fgets(string2, sizeof(string2), stdin);
	
	string1[strcspn(string1, "\n")] = '\0';
	string2[strcspn(string2, "\n")] = '\0';
	
	nova(string1, string2, string3);
	printf("\n\nnova string: %s", string3);
	return 0;
}


void nova (char str1[], char str2[], char str3[]){
	int i, j, k=0, cont, cont_str3;
	
	for(i=0; str1[i]!='\0' ;i++){
		cont=1;
		for(j=0; str2[j]!='\0';j++){
			if(str1[i]==str2[j]){
				cont=0;
				break;
			}
		}
		 
		if(cont){
			cont_str3=1;
			for(j=0; str3[j]!='\0' ;j++){
				if(str3[j]==str1[i]){
					cont_str3=0;
					break;
				}
			}
			if(cont_str3){
				str3[k++]=str1[i];
			}
		}
		
	}
	str3[i]='\0';
}

