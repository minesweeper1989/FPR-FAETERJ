/*Questão 01:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.*/
#include<stdio.h>
#include<stdlib.h>

int quantidade (char nomeaq[]);

int main (){
	int resultado=quantidade("teste.txt");
	if(resultado<0){
		printf("erro ao ler o arquivo.");
	} else{
		printf("o arquivo possui %d caracteres.\n", resultado);
	}

	return 0;
}

int quantidade (char nomearq[]){
	char caracter;
	FILE *arq;
	int quant=0;
	
	arq=fopen(nomearq, "r");
	
	if(!arq){
		fclose(arq);
		return -1;
	}

	while(fscanf(arq, "%c", &caracter)!=EOF){
		quant++;
	}
	
	fclose(arq);
	return quant;
}
