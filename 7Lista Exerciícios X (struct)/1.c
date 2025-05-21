/*Questão 01:
Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:
i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;
iii. Retirar do estoque um determinado veículo,
dada a sua placa.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 5

typedef struct{
	int modelo, fabricacao;
}Sano;

typedef struct{
	char placa[9], modelo[20], marca[30], cor[15], tipo[10];
	float quilometragem, valor;
	Sano ano;
	 
} Scarro;

void case1 (int tamanho, Scarro carro[tamanho], char m[], int a1, int a2, float maximo);
int case2 (int tamanho, Scarro carro[tamanho], float p);
int case3 (int *tamanho, Scarro carro[*tamanho], char rmvplaca[]);
void exibir_struct (int tamanho, Scarro carro[tamanho]);
void preencher_carros(int tamanho, Scarro carro[tamanho]);

int main (){
	int resp, a1, a2, tamanho=TAM;
	float maximo_e_p;
	char m_e_placa[20];
	Scarro carro[tamanho];
	
	preencher_carros(tamanho, carro);
	do{
		system("cls");
		exibir_struct(tamanho, carro);
		
		printf("\n\n\nSELECIONE A OPCAO QUE DESEJA VISUALIZAR:\n1 - Exibir todos os carros do modelo m, ano de fabricacao entre a1 e a2 (inclusive), com valor não superior a x reais;\n");
		printf("2 - Reajustar os valores de todos os carros 0km, considerando um aumento de p porcento;\n");
		printf("3 - Retirar do estoque um determinado veiculo, dada a sua placa;\n");
		printf("0 - Finalizar programa.\n\n");
		printf("RESPOSTA: ");
		scanf("%d", &resp);
		
		
		switch(resp){
			case 1:
				printf("\n\nModelo: ");
				getchar();
				fgets(m_e_placa, sizeof(m_e_placa), stdin);
				m_e_placa[strcspn(m_e_placa, "\n")]='\0'; 
				
				printf("\na1 e a2: ");
				scanf("%d %d", &a1, &a2);
				getchar();
				
				printf("\nValor maximo: R$");
				scanf("%f", &maximo_e_p);
				
				case1(tamanho, carro, m_e_placa, a1, a2, maximo_e_p);
				
				break;
			case 2:
				printf("\n\np porcento: ");
				scanf("%f", &maximo_e_p);
				
				if(case2(tamanho, carro, maximo_e_p)==0){
					printf("\nNao houve mudancas. ");
				}
				else{
					printf("\nValor reajustado com sucesso. ");
				}
				break;
			case 3:
				printf("\n\nPlaca: ");
				getchar();
				fgets(m_e_placa, sizeof(m_e_placa), stdin);
				m_e_placa[strcspn(m_e_placa, "\n")]='\0';
				
				if(case3(&tamanho, carro, m_e_placa)==0){
					printf("\nNao houve mudancas. ");
				}
				else{
					printf("\nVeiculo removido com sucesso. ");
				}
				break;
			default:
				printf("\nOpcao invalida. Tente novamente. ");
				break;
		}
		system("PAUSE");
	}while(resp!=0);
	
	return 0;
}

/*i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;*/
void case1 (int tamanho, Scarro carro[tamanho], char m[], int a1, int a2, float maximo){
	int i, j=1;
	for(i=0;i<tamanho;i++){
		if(strcmp(m, carro[i].modelo)==0 && carro[i].ano.fabricacao>=a1 && carro[i].ano.fabricacao<=a2 && carro[i].valor<maximo){
			printf("\nCARRO %d:\nPlaca: %s\nModelo: %s\nMarca: %s\nCor: %s\nQuilometragem: %.2fkm", j, carro[i].placa, carro[i].modelo, carro[i].marca, carro[i].cor, carro[i].quilometragem);
        	printf("\nAno do modelo: %d\nAno da fabricacao: %d\nValor: R$%.2f\nTipo: %s\n", carro[i].ano.modelo, carro[i].ano.fabricacao, carro[i].valor);
	    	j++;
	 	}
	}
}

/*ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;*/
int case2 (int tamanho, Scarro carro[tamanho], float p){
	int i;
	for(i=0;i<tamanho;i++){
		if(strcmp("0 km",carro[i].tipo)==0){
			carro[i].valor*=((p/100)+1);
		}
	}
}

/*iii. Retirar do estoque um determinado veículo,
dada a sua placa.*/
int case3 (int *tamanho, Scarro carro[*tamanho], char rmvplaca[]){
	int i, removido=0;
	for(i=0;i<(*tamanho);i++){
		if(strcmp(rmvplaca, carro[i].placa)==0){
			carro[i]=carro[(*tamanho)-1];
			(*tamanho)--;
			removido=1;
			return 1;
		}
	}
	return 0;
}

void exibir_struct (int tamanho, Scarro carro[tamanho]){
	int i;
	for(i=0;i<tamanho;i++){
		printf("\nCARRO %d:\nplaca: %s\nmodelo: %s\nmarca: %s\ncor: %s\nquilometragem: %.2fkm", i+1, carro[i].placa, carro[i].modelo, carro[i].marca, carro[i].cor, carro[i].quilometragem);
		printf("\nano do modelo: %d\nano da fabricacao: %d\nvalor: R$%.2f\ntipo: %s\n", carro[i].ano.modelo, carro[i].ano.fabricacao, carro[i].valor, carro[i].tipo);
	}
}

void preencher_carros(int tamanho, Scarro carro[tamanho]) {
    strcpy(carro[0].placa, "ABC1234");
    strcpy(carro[0].modelo, "Civic");
    strcpy(carro[0].marca, "Honda");
    strcpy(carro[0].cor, "Preto");
    carro[0].quilometragem = 0;
    carro[0].ano.modelo = 2023;
    carro[0].ano.fabricacao = 2022;
    carro[0].valor = 120000;
    strcpy(carro[0].tipo, "0 km");

    strcpy(carro[1].placa, "DEF5678");
    strcpy(carro[1].modelo, "Onix");
    strcpy(carro[1].marca, "Chevrolet");
    strcpy(carro[1].cor, "Branco");
    carro[1].quilometragem = 15000;
    carro[1].ano.modelo = 2021;
    carro[1].ano.fabricacao = 2020;
    carro[1].valor = 60000;
    strcpy(carro[1].tipo, "usado");

    strcpy(carro[2].placa, "GHI9012");
    strcpy(carro[2].modelo, "Civic");
    strcpy(carro[2].marca, "Honda");
    strcpy(carro[2].cor, "Prata");
    carro[2].quilometragem = 5000;
    carro[2].ano.modelo = 2022;
    carro[2].ano.fabricacao = 2021;
    carro[2].valor = 95000;
    strcpy(carro[2].tipo, "usado");

    strcpy(carro[3].placa, "JKL3456");
    strcpy(carro[3].modelo, "Corolla");
    strcpy(carro[3].marca, "Toyota");
    strcpy(carro[3].cor, "Cinza");
    carro[3].quilometragem = 0;
    carro[3].ano.modelo = 2024;
    carro[3].ano.fabricacao = 2023;
    carro[3].valor = 130000;
    strcpy(carro[3].tipo, "0 km");

    strcpy(carro[4].placa, "MNO7890");
    strcpy(carro[4].modelo, "HB20");
    strcpy(carro[4].marca, "Hyundai");
    strcpy(carro[4].cor, "Azul");
    carro[4].quilometragem = 30000;
    carro[4].ano.modelo = 2020;
    carro[4].ano.fabricacao = 2019;
    carro[4].valor = 55000;
    strcpy(carro[4].tipo, "usado");
    
    exibir_struct(tamanho, carro);
}
