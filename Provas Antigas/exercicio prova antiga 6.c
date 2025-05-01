/******************************************************************************


Desenvolver uma função recursiva que, dados um vetor com quant inteiros e dois 
números num1 e num2, calcule a média dos valores do vetor que estão no intervalo 
de num1 a num2, inclusive.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorizador(int tamanho, int limite, int vetor[tamanho]);
void exibir_vetor(int tamanho, int vetor[tamanho]);
float media_rec(int num1, int num2, float divisor, int vetor[]); 

int main(){
    int quant, num1, num2;
    printf("quantos numeros deseja que seu vetor tenha? ");
    scanf("%d", &quant);
    int vet[quant];
    
    aleatorizador(quant, 9, vet);
    exibir_vetor(quant, vet);
    printf("\nescolha dois numeros do vetor de acordo com sua localizacao(1-%d): ", quant);
    scanf("%d %d", &num1, &num2);
    
    num1--;
    num2--;
    
    printf("\nmedia do intervalo: %.2f", media_rec(num1, num2, num2-num1+1, vet)); 

    return 0;
}

float media_rec(int num1, int num2, float divisor, int vet[]){
    if(num1>num2){
        return 0;
    }
    if(num1==num2){
        return (vet[num1]/divisor) + media_rec(num1+1, num2, divisor, vet);
    }
    return (vet[num1]/divisor) + media_rec(num1+1, num2, divisor, vet);
}

void aleatorizador(int tamanho, int limite, int vetor[tamanho]){
    int i;
    srand(time(NULL));
    for(i=0;i<tamanho;i++){
        vetor[i]=rand()%limite;
    }
}

void exibir_vetor(int tamanho, int vetor[tamanho]){
    int i;
    printf("\nvetor: ");
    for(i=0;i<tamanho;i++){
        printf("%d ", vetor[i]);
    }
}
