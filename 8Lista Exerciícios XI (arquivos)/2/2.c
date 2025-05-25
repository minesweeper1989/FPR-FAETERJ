/*Questão 02:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.*/
#include<stdio.h>
#include<stdlib.h>

int frequencia (char nomearq[], char escolhido);

int main (){
	char escolhido;
	
	printf("\nescolha um caracter: ");
	scanf(" %c", &escolhido);
	
	int resultado=frequencia("teste.txt", escolhido);
	
	if(resultado<0){
		printf("erro ao ler o arquivo.");
	} else{
		printf("o arquivo possui %d caracteres.\n", resultado);
	}
	
	return 0;
}

int frequencia (char nomearq[], char escolhido){
	FILE *arq;
	char caracter;
	int quant=0;
	arq=fopen(nomearq, "r");
	
	if(!arq){
		fclose(arq);
		return -1;
	}
	
	while(fscanf(arq, "%c", &caracter)!=EOF){
		if(caracter==escolhido){
			quant++;
		}
	}
	fclose(arq);
	return quant;
}


