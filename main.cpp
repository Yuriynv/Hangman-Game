#include <iostream>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

void hangman_game(char level){
	switch (level){	
		case 1:
			printf("\n\n\n");	
			printf("\t\t\t  ,,, \n");
			printf("\t\t\t (º º)\n");
			printf("\t\t\t _'''_ \n");
			printf("\t\t\t   | \n");
			printf("\t\t\t _/ \\_ \n");
			printf("=====================================\n");
			break;
		case 2:
			printf("\n\n");	
			printf("\t\t\t  ,,, \n");
			printf("\t\t\t (º º)\n");
			printf("\t\t\t _'''_ \n");
			printf("\t\t\t   | \n");
			printf("\t\t\t  / \\  \n");
			printf("=====================================\n");
			break;
		case 3:
			printf("\n\n");	
			printf("\t\t\t  ,,, \n");
			printf("\t\t\t (º º)\n");
			printf("\t\t\t _'''_ \n");
			printf("\t\t\t   | \n");
			printf("\t\t\t       \n");
			printf("=====================================\n");
			break;
		case 4:
			printf("\n\n");	
			printf("\t\t\t  ,,, \n");
			printf("\t\t\t (º º)\n");
			printf("\t\t\t _'''_ \n");
			printf("\t\t\t     \n");
			printf("\t\t\t       \n");
			printf("=====================================\n");
			break;
		case 5:
			printf("\n\n");	
			printf("\t\t\t  ,,, \n");
			printf("\t\t\t (º º)\n");
			printf("\t\t\t  '''   \n");
			printf("\t\t\t     \n");
			printf("\t\t\t       \n");
			printf("=====================================\n");
			break;
		case 6:
			printf("\n\n");	
			printf("\t\t\t  ,,, \n");
			printf("\tMORREU, OTÁRIO!\t (x x)\n");
			printf("\t\t\t  '''   \n");
			printf("\t\t\t     \n");
			printf("\t\t\t       \n");
			printf("=====================================\n");
			break;
	}
}

void apresentar(int tamanho, char letras[], char letras_usadas[]) {
	
	printf("\n\tLetras Usadas: [");
	for (int i = 0; i < strlen(letras_usadas); i++) {
		printf("%c", letras_usadas[i]);
		if (i < (strlen(letras_usadas) -1)) {
			printf(", ");
		}
	}
	printf("]\n");
	
	printf("\n\t");
	for (int i = 0; i < tamanho; i++) {
		printf("%c", letras[i]);
		printf(" ");
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	int tamanho = 46, hit, vazio;
	char palavra[tamanho];
	char letras[strlen(palavra)];
	char letra;
	
	printf("\n\tDigite a palavra desafio: ");
	scanf("%s", &palavra);
	tamanho = strlen(palavra);
	system("cls");
	
	for (int i = 0; i < tamanho; i++) {
		letras[i] = '_';
	}
	
	int level = 1;
	char *letras_usadas = NULL;
	letras_usadas = (char*)malloc(sizeof(char));
	
	while (level < 6) {
		hit = 0;
		
		hangman_game(level);
		
		printf("\n\t");
		std::cin.ignore();
		
		apresentar(tamanho, letras, letras_usadas);
		
		printf("\n\n\tDigite uma letra: ");
		scanf("%c", &letra);
		
		letras_usadas[strlen(letras_usadas)] = letra;
		letras_usadas = (char*)realloc((char*)letras_usadas, strlen(letras_usadas) + sizeof(char));
		
		for (int i = 0; i < tamanho; i++) {
			if (letra == palavra[i]) {
				letras[i] = letra;
				hit += 1;
			}
		}
		
		if (hit == 0) level += 1;
		
		system("cls");
	}
	hangman_game(level);
	
	printf("\n\tDigite qualquer tecla para encerrar.\n");
}
