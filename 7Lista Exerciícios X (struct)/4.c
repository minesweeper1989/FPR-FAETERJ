/*Questão 04:
Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre um grupo
de pessoas: nome (string), gênero (char) e
idade (int). Pede-se uma função que determine
se os elementos deste vetor estão ordenados e
retorne 1, caso estejam ordenados, e 0, caso
contrário.
Observação: o vetor será considerado ordenado se
estiver organizado crescentemente em função da
idade. Porém, no caso de pessoas com a mesma
idade, estas devem estar ordenadas crescentemente
pelo nome.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 5

typedef struct{
	char nome[100], sexo;
	int idade;
}grupo;

void tipo_vetor (int resp, int tamanho, grupo pessoa[tamanho]);
int checar (int tamanho, grupo pessoa[tamanho]);
void exibir_vetor (int tamanho, grupo pessoa[tamanho]);

int main(){
	grupo pessoa[TAM];
	int resp;
	
	printf("escolha o tipo de vetor:\n1 - vetor organizado\n2 - vetor desorganizado(idade)\n3 - vetor desorganizado(nome)\n\nRESPOSTA: ");
	scanf("%d", &resp);
	
	tipo_vetor(resp, TAM, pessoa);
	exibir_vetor(TAM, pessoa);
	
	printf("\no vetor %se organizado.", checar(TAM, pessoa)==1?"":"nao ");
	
	return 0;
}

void tipo_vetor (int resp, int tamanho, grupo pessoa[tamanho]){
	if(resp==1){
	strcpy (pessoa[0].nome, "A");
	pessoa[0].idade = 1;
	pessoa[0].sexo = 'F';

	strcpy (pessoa[1].nome, "B");
	pessoa[1].idade = 2;
	pessoa[1].sexo = 'M';

	strcpy (pessoa[2].nome, "C");
	pessoa[2].idade = 3;
	pessoa[2].sexo = 'M';

	strcpy (pessoa[3].nome, "D");
	pessoa[3].idade = 4;
	pessoa[3].sexo = 'F';

	strcpy (pessoa[4].nome, "E");
	pessoa[4].idade = 5;
	pessoa[4].sexo = 'M';
	}
	else if (resp==2){
		strcpy (pessoa[0].nome, "A");
		pessoa[0].idade = 1;
		pessoa[0].sexo = 'M';

		strcpy (pessoa[1].nome, "B");
		pessoa[1].idade = 2;
		pessoa[1].sexo = 'M';

		strcpy (pessoa[2].nome, "C");
		pessoa[2].idade = 4;
		pessoa[2].sexo = 'F';

		strcpy (pessoa[3].nome, "D");
		pessoa[3].idade = 3;
		pessoa[3].sexo = 'M';

		strcpy (pessoa[4].nome, "E");
		pessoa[4].idade = 5;
		pessoa[4].sexo = 'F';
	}
	else{
		strcpy (pessoa[0].nome, "A");
		pessoa[0].idade = 1;
		pessoa[0].sexo = 'M';

		strcpy (pessoa[1].nome, "C");
		pessoa[1].idade = 2;
		pessoa[1].sexo = 'M';

		strcpy (pessoa[2].nome, "B");
		pessoa[2].idade = 2;
		pessoa[2].sexo = 'F';

		strcpy (pessoa[3].nome, "D");
		pessoa[3].idade = 3;
		pessoa[3].sexo = 'M';

		strcpy (pessoa[4].nome, "E");
		pessoa[4].idade = 5;
		pessoa[4].sexo = 'F';
	}
}

int checar (int tamanho, grupo pessoa[tamanho]){
	int i, j;
	for(i=1;i<tamanho;i++){
		if(pessoa[i].idade<pessoa[i-1].idade){
			return 0;
		}
		if(pessoa[i].idade==pessoa[i-1].idade){
			if(strcmp(pessoa[i].nome,pessoa[i-1].nome)<0){
				return 0;
			}
		}
		
	}
	return 1;
}

void exibir_vetor (int tamanho, grupo pessoa[tamanho]){
	int i;
	for(i=0;i<tamanho;i++){
		printf("\n\nPESSOA %d.\nNOME: %s\nIDADE: %d\nSEXO: %c", i+1,pessoa[i].nome,pessoa[i].idade,pessoa[i].sexo);
	}
}


