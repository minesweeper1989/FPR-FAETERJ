/*Questão 03:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).*/
#include<stdio.h>
#include<stdlib.h>
//<ctype.h>
int existente (char nomearq[]);

int main (){
	int res=existente("teste.txt");
	if(res<0){
		printf("erro ao ler o arquivo.");
	} else{
		printf("o arquivo possui %d letras.\n", res);
	}
	
	return 0;
}

int existente (char nomearq[]){
	FILE *arq;
	int quant=0;
	char caracter;
	
	arq=fopen(nomearq, "r");
	
	if(!arq){
		fclose(arq);
		return -1;
	}
	while(fscanf(arq,"%c", &caracter)!=EOF){
		if((caracter>='A' && caracter<='Z') || (caracter>='a' && caracter<='z')){
			quant++;
		}
		/*ou
		if(isalpha(caracter)){
			quant++;
     	}
		*/
	}
	fclose(arq);
	return quant;
}
