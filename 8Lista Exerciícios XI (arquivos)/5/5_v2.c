/*Questão 05:
Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição.*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printar (char nomearq[]);
int decrescente (char nomearqA[], char nomearqB[]);

int main (){
	int res=decrescente("A.txt", "B.txt");
	if(res<0){
		printf("erro ao ler o arquivo.");
	} else{
		printf("os numeros do arquivo A.txt foram ordenados no arquivo B.txt.");
		printar("A.txt");
		printar("B.txt");
	}
	return 0;
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

int decrescente (char nomearqA[], char nomearqB[]){
	FILE *arqA, *arqB;
	int numA, maior, anterior=INT_MAX, num, parar;
	
	arqA=fopen(nomearqA, "r");
	arqB=fopen(nomearqB, "w");
	if(!arqA || !arqB){
		fclose(arqA);
		fclose(arqB);
		return -1;
	}
	
	
		/*A.txt tem esses numeros: 3 2 1 3 5 9
	3 2 1 3 5 9
	3 2 1 3 5 9
	
	9 5 3 2 1
	*/
	do{
		rewind(arqA);
		maior=INT_MIN;
		parar=1;
		while(fscanf(arqA, "%d", &numA)!=EOF){
			if(numA>maior && numA<anterior){
				maior=numA;
				parar=0;
			}
		}
		if(!parar){
			fprintf(arqB, "%d\n", maior);
			anterior=maior;
		}
	}while(!parar);

    
	fclose(arqA);
	fclose(arqB);
	return 0;
}
