#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int value;
	struct Node *left;
	struct Node *right; 
};

bool verConec(struct Node *n);
void create(struct Node **n);
void insert(struct Node **n, int v);

void imprimeNo(int c, int b);
void mostraArvore(struct Node *n, int b);

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

void create(struct Node **n){ /*Criacao basica da arvore*/
								/*Dois ponteiros para nao alocar memoria desnecessaria*/
	(*n) = NULL;
}

void insert(struct Node **n, int v) { /*Insercao de um elemento na arvore*/
	if((*n) == NULL){ //se nao tiver nenhum elemento na raiz, coloca diretamente na raiz o valor inserido.
		(*n) = (struct Node*)malloc(sizeof(struct Node)); /*Aloca espaco para adicionar e*/
															/*Setando os elementos da esquerda e direita*/
		(*n)->left = NULL;
		(*n)->right = NULL;
		(*n)->value = v; //Coloca valor inserido
	}
	else { /*senao, eh por que existe um elemento na raiz*/
			/*Verifica se o elemento inserido eh maior ou menor*/
				/*Menor=esquerda, Maior=direita*/
		if(v > (*n)->value){
			insert (&((*n)->right), v); //O endereco do no para pegar a referencia
		}
		else /*senao for maior eh pq eh menor ou igual, entao insere na esquerda*/
			insert(&((*n)->left), v);
	}
}

/* A funao mostraArvore faz um desenho horizontal
 da arvore x. O desenho terá uma margem esquerda de
 4 espaços */
void mostraArvore(struct Node *a, int b) {
    if (a == NULL) {    /*Se o no for nulo, 
							imprime os valores zero 
								na esquerda e direita*/
        imprimeNo(0, b);
        return;
	}
	mostraArvore(a->right, b+1);
	imprimeNo(a->value, b);
	mostraArvore(a->left, b+1);
}

/* A função auxiliar imprimeNo imprime o valor
c precedido de 4 espaços e seguido de uma mudança
de linha */

void imprimeNo(int c, int b) {
    int i;
    for (i = 0; i < b; i++) printf("    ");
    printf("%d\n", c);
}
