/*Questão 06:
Desenvolver uma função que, dados dois
arquivos textos arqA e arqB, crie um novo
arquivo arqC, considerando que:
   ? arqA e arqB contém números reais,
um por linha, ordenados
crescentemente e sem repetição no
arquivo;
   ? arqC deve conter todos os números
dos dois arquivos originais;
   ? Assim como arqA e arqB, arqC
também não possuirá repetições de
elementos e estes deverão estar
ordenados de forma crescente.*/
#include<stdio.h>
#include<stdlib.h>

int sla (char nomeA[], char nomeB[], char nomeC[]);
void printar (char nomearq[]);

int main (){
	int res=sla("A.txt", "B.txt", "C.txt");
	if(res<0){
		printf("erro ao ler o arquivo.");
	} else{
		printf("o arquivo C.txt possui todos os numeros sem repeticao ordenados crescentemente do arquivo A.txt e B.txt");
		printar("A.txt");
		printar("B.txt");
		printar("C.txt");
	}
	return 0;
}

int sla (char nomeA[], char nomeB[], char nomeC[]){
	FILE *arqA, *arqB, *arqC;
	int numA, numB;
	arqA=fopen(nomeA, "r");
	arqB=fopen(nomeB, "r");
	if(!arqA || !arqB){
		fclose(arqA);
    	fclose(arqB);
		return -1;
	}
	
	/*
	A: 1 3 4 7 9
	B: 2 4 7 8 9
	C: 1 2 3 4 7 8 9
	*/
	int contA=fscanf(arqA, "%d", &numA);
	int contB=fscanf(arqB, "%d", &numB);
	
	arqC=fopen(nomeC, "w");
	while(contA!=EOF && contB!=EOF){
		if(numA<numB){
			fprintf(arqC, "%d\n", numA);
			contA=fscanf(arqA, "%d", &numA);
		} else if(numA>numB){
			fprintf(arqC, "%d\n", numB);
			contB=fscanf(arqB, "%d", &numB);
		} else{
			fprintf(arqC, "%d\n", numA);
			contA=fscanf(arqA, "%d", &numA);
			contB=fscanf(arqB, "%d", &numB);
		}
	}
	
	fclose(arqA);
	fclose(arqB);
	fclose(arqC);
	return 1;
}

void printar (char nomearq[]){
	FILE *arq;
	int num;
	printf("\n\n\narquivo %s:\n", nomearq);
	arq=fopen(nomearq, "r");
	while(fscanf(arq, "%d", &num)!=EOF){
		printf("%d\n", num);
	}
	fclose(arq);
}

