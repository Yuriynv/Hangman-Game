#include <iostream>
#include <stdlib.h>

float calcular_nota(float custo, float lucro, float imposto) {
	float valor = custo + lucro;
	float imposto_rs = valor * imposto / 100;
	
	float valor_final = (valor + imposto_rs) / ((100 - imposto) / 100);
	
	return valor_final;
}

int main(int argc, char** argv) {
	
	float custo, lucro, imposto, valor_final;
	
	do {
		printf("\nDigite o custo: R$");
		scanf("%f", &custo);
	} while (custo < 0);
	
	do {
		system("cls");
		printf("\nCusto Objtido: R$ %.2f", custo);
		printf("\nDigite o lucro desejado: R$");
		scanf("%f", &lucro);
	} while (lucro < 0);
	
	do {
		system("cls");
		printf("\nCusto Obtido: R$ %.2f", custo);
		printf("\nLucro Desejado: R$ %.2f", lucro);
		printf("\nDigite o total de imposto em %: ");
		scanf("%f", &imposto);
	} while (imposto < 0);
	
	system("cls");
	printf("\nCusto Obtido: R$ %.2f", custo);
	printf("\nLucro Desejado: R$ %.2f", lucro);
	printf("\nTotal de Imposto em %: ");
	
	valor_final = calcular_nota(custo, lucro, imposto);
	
	printf("\nValor a cobrar: R$ %.2f", valor_final);
	
	return 0;
}
