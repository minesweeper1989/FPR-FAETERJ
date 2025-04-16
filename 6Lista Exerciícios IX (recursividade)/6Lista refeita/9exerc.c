/*Questão 09:
Desenvolver uma função recursiva que, dado
um vetor V com quant números inteiros,
determine se seus elementos estão dispostos
de maneira a representar uma progressão
aritmética.
an = a1 + (n-1) d
an	= 	o termo n na sequência
a1	= 	o primeiro termo na sequência
d	= 	a diferença comum entre termos
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define tam 4
void aleatorizador (int tamanho, int limite, int vetor[]);
void exibir (int tamanho, int vetor[]);
int checar (int vet[], int i, int razao, int tamanho);
int main (){
	int v[tam], v2[tam]={3, 6, 9, 12}, i=1;
	
	printf("\nvetor 1: ");
	aleatorizador(tam, 10, v);
	exibir(tam, v);
	printf("o vetor 1 %s uma PA.", checar(v, i, v[1]-v[0], tam)==1? "e":"nao e");
	
	printf("\n\nvetor 2: ");
	exibir(tam, v2);
	printf("o vetor 2 %s uma PA.", checar(v2, i, v2[1]-v2[0], tam)==1? "e":"nao e");
	return 0;
}

int checar (int vet[], int i, int razao, int tamanho){
	if(i>=tamanho){
		return 1;
	}
	if(vet[i]-vet[i-1]!=razao){
		return 0;
	}
	return checar(vet, i+1, razao, tamanho);
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
