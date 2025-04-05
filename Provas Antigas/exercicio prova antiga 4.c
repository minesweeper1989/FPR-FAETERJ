/*
desenvolver uma função recursiva que, dados uma matriz, uma linha L e uma coluna C, determine 
se os elementos da linha Le da coluna C possuem os mesmos elementos, porém na ordem inversa.
Deve ser retornado o valor 1 se esta característica  for observada; caso contrário, a função retornará 0.
Exemplo:
1 2 3 4
0 9 2 7
4 6 9 1
2 9 2 3
Na matriz M4x4 acima, a função deve retornar 1 se L = 3 e C = 2, 
pois os elementos da linha 3 são os mesmos da coluna 2, porém na ordem inversa.
*/
#include<stdio.h>
#include<stdlib.h>

int igual_inversa (int m[4][4], int lin, int col, int i, int j);
void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]);

int main (){
	int linha, coluna, matriz[4][4] = {{1, 2, 3, 4},
                                       {0, 9, 2, 7},
                                       {4, 6, 9, 1},
                                       {2, 9, 2, 3}};
	 
	exibirmatriz(4,4,matriz);
	int i=0, j=3;
	
	printf("\nescolha uma linha e uma coluna(0 a 3): ");
	scanf("%d %d", &linha, &coluna);
	
	printf("os elementos da linha %d %s da coluna %d invertida", linha, igual_inversa(matriz, linha, coluna, i, j)? "e o mesmo":"nao e o mesmo", coluna);
	
	return 0;
}

int igual_inversa (int m[4][4], int lin, int col, int i, int j){
	if(m[i][col]!=m[lin][j]){
		return 0;
	}
	return 1 + igual_inversa(m,lin,col,i+1,j-1);
}

void exibirmatriz (int linha, int coluna, int matriz[linha][coluna]){
	int i, j;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			printf("%3d ", matriz[i][j]);
		}
		printf("\n");
	}
}
