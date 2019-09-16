#ifndef _HEADER_H
#define _HEADER_H
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
#endif
