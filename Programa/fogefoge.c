#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

char** mapa;
int linhas;
int colunas;

void lemapa() {
    //matriz de 5 X 10
    //char mapa[5][10+1];

    /*
    mapa[0][0] = '|';
    mapa[4][9] = '@';
    printf("%c %c\n", mapa[0][0], mapa[4][9]);
    */

    ///////////////
    //Variavel
    /*int* v = malloc(4);
    *v = 10;
    printf("inteiro alocado %d\n", *v);
    free(v);*/

    //Vetor
    /*int* v = malloc(sizeof(int) * 50);
    v[0] = 10;
    v[1] = 20;
    printf("inteiro alocado %d %d\n", v[0], v[1]);
    free(v);*/

    //Matriz
    /*int** v = malloc(sizeof(int*) * 5);
    for(int i = 0; i < 5; i++){
        v[i] = malloc(sizeof(int) * 10);
    }
    v[0][0] = 10;
    v[1][1] = 20;
    printf("inteiro alocado %d %d\n", v[0][0], v[1][1]);
    for(int i = 0; i < 5; i++){
        free(v[i]);
    }
    free(v);*/
    ///////////////

	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa");
		exit(1);
	}

	fscanf(f, "%d %d", &linhas, &colunas);
	alocamapa();

	for(int i = 0; i < 5; i++) {
		fscanf(f, "%s", mapa[i]);
	}

	fclose(f);
}

void alocamapa() {
	mapa = malloc(sizeof(char*) * linhas);

	for(int i = 0; i < linhas; i++) {
		mapa[i] = malloc(sizeof(char) * colunas + 1);
	}
}

void liberamapa() {
	for(int i = 0; i < linhas; i++) {
		free(mapa[i]);
	}

	free(mapa);
}

int main() {

	lemapa();

	for(int i = 0; i < linhas; i++) {
		printf("%s\n", mapa[i]);
	}

	liberamapa();
}
