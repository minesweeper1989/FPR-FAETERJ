/*Questão 04:
Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.*/
#include<stdio.h>
#include<stdlib.h>

int crescente(char nomearq[]);

int main (){
	int res=crescente("teste.txt");
	if(res<0){
		printf("erro ao ler o arquivo.");
	} else{
		printf("o arquivo %sencontra-se ordenado crescentemente.", res==1?"":"NAO ");
	}
	return 0;
}

int crescente(char nomearq[]){
	FILE *arq;
	int numero, anterior, primeiro=0;
	
	arq=fopen(nomearq, "r");
	if(!arq){
		fclose(arq);
		return -1;
	}
	while(fscanf(arq, "%d", &numero)!=EOF){
		if(primeiro){
			if(anterior>numero){
				return 0;
			}
		} else{
			primeiro=1;
		}
		anterior=numero;
	}
	fclose(arq);
	return 1;
}
