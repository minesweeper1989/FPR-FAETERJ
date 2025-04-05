/*Desenvolver uma função recursiva que, dada uma string s, determine 
se s representa um número real. Para tal, deve atender às seguintes regras:

i. s só pode conter caracteres que representem os algarismos de 0 a 9 
(ou seja, '0', '1', '2',...,'8' ou '9') e o caractere ponto ('.');

ii. O ponto não é obrigatório. Porém, caso exista, só pode aparecer 
uma vez e não deve figurar na primeira e nem na última posição da string.

Caso s cumpra as regras, o valor 1 deverá ser retornado pela função; caso contrário, retornará 0.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validade (char s[], int tamanho, int ponto, int i);

int main (){
	int tamanho, ponto=0, i=0;
	char string[100];
	printf("insira um numero qualquer: ");
	fgets(string, sizeof(string), stdin);
	
	string[strcspn(string, "\n")] = '\0';
	tamanho=strlen(string)-1;
	
	printf("\n%s %s valida.", string, (validade(string, tamanho, ponto, i)==1)?"e":"nao e");
	
	return 0;
}

int validade (char s[], int tamanho, int ponto, int i){
	if(s[i]=='\0'){
		return 1;
	}
	if(s[i]=='.'){
		if(i==0 || i==tamanho || ponto){
			return 0;
		}
		return validade(s, tamanho, 1, i+1);
	}
	if(s[i]<'0' || s[i]>'9'){
		return 0;
	}
	
	return validade(s, tamanho, ponto, i+1);
}
