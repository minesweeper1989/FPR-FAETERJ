/*Questão 09:
Desenvolver uma função recursiva que, dado
um vetor V com quant números inteiros,
determine se seus elementos estão dispostos
de maneira a representar uma progressão
aritmética.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int checar (int i, int razao, int vetor[]);
void aleatorizador (int tamanho, int limite, int vetor[]);
void exibir (int tamanho, int vetor[]);

int main (){
	int quant, razao_v, razao_v2;
	printf("insira a quantidade de numeros inteiros no vetor: ");
	scanf("%d", &quant);
	
	int v[quant], v2[4]={3, 6, 9, 12};
	
	printf("\nvetor 1: ");
	aleatorizador(quant, 10, v);
	exibir(quant, v);
	printf("\no vetor 1 %s progressao aritmetica.", (checar(quant-1, v[0]-v[1], v))==1 ? "e":"nao e");
	
	printf("\n\nvetor 2: ");
	exibir(4, v2);
	printf("\no vetor 2 %s progressao aritmetica.", (checar(3, v2[0]-v2[1], v2))==1 ? "e":"nao e");
	
	return 0;
}

int checar (int i, int razao, int vetor[]){
	if(vetor[i-1]-vetor[i]!=razao){
		return 0;
	}
	if(i==0){
		return 1;
	}
	checar(i-1, razao, vetor);
}

void aleatorizador (int tamanho, int limite, int vetor[]){
	int i;
	srand (time(NULL));
	for(i=0;i<tamanho;i++){
		vetor[i]=rand()%limite;
	}
}

void exibir (int tamanho, int vetor[]){
	int i;
	for(i=0;i<tamanho;i++){
			printf("%d ", vetor[i]);
    }
}
