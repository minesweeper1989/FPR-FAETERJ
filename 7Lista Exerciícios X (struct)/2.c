/*Questão 02:
Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:
? Determinar a quantidade de pessoas que
fazem aniversário no mês M;
? Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 5

typedef struct {
	int dia, mes;
}TData;

typedef struct {
	char nome[50];
	TData aniversario; 
}TPessoa;

void entreDTS (int tamanho, TPessoa aluno[tamanho], TData d1, TData d2);
int mesmoNIV (int tamanho, TPessoa aluno[tamanho], int mes);

int main (){
	TPessoa aluno[TAM];
	TData d1, d2;
	int i, mes, quant;
	
	for(i=0;i<TAM;i++){
		printf("\n\ndigite o nome da pessoa %d: ",  i+1);
		fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
		aluno[i].nome[strcspn(aluno[i].nome, "\n")]='\0';
		printf("\ndigite o dia e o mes do aniversario (dia mes): ");
		scanf("%d %d", &aluno[i].aniversario.dia, &aluno[i].aniversario.mes);
		getchar();
	}

	printf("\n\ndigite um mes: ");
	scanf("%d", &mes);
	printf("\nnumero de aniversariantes do mes %d: %d\n\n", mes, mesmoNIV(TAM, aluno, mes));
	
	printf("\n\ndigite a primeira data(dia mes): ");
	scanf("%d %d", &d1.dia, &d1.mes);
	printf("\ndigite a primeira data(dia mes): ");
	scanf("%d %d", &d2.dia, &d2.mes);
	
	printf("\naniversariantes entre essas datas:");
	entreDTS(TAM, aluno, d1, d2);

	return 0;
}

//Determinar a quantidade de pessoas que fazem aniversário no mês M;
int mesmoNIV (int tamanho, TPessoa aluno[tamanho], int mes){
	int i, quant=0;
	for(i=0;i<tamanho;i++){
		if(aluno[i].aniversario.mes==mes){
			quant++;
		}
	}
	return quant;
}

//Exibir os nomes de todas pessoas que fazem aniversário entre as datas d1 e d2, ambas do tipo TData.
void entreDTS (int tamanho, TPessoa aluno[tamanho], TData d1, TData d2){
	int i;
	for(i=0;i<tamanho;i++){
		if((aluno[i].aniversario.mes > d1.mes || (aluno[i].aniversario.mes == d1.mes && aluno[i].aniversario.dia >= d1.dia)) && (aluno[i].aniversario.mes < d2.mes || (aluno[i].aniversario.mes == d2.mes && aluno[i].aniversario.dia <= d2.dia))){
			printf("\n\n%s", aluno[i].nome);
		}
	}
}





