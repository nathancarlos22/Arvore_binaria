#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main () {
	struct Node *arvore;
	
	create(&arvore);
	
	insert(&arvore, 1);
	insert(&arvore, 10);
	insert(&arvore, 10);
	insert(&arvore, 1);
	
	mostraArvore(arvore, 1);
	printf("\nArvore HORIZONTAL\n");
	printf("0 representa espaco vazio\n");
	getchar();
	
	return 0;
}
