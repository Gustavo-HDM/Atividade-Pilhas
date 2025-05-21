#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TAM 10

int resp;

//	ESTRUTURA PARA UMA PILHA
typedef struct {
	int dados[TAM];
	int topo;
} Pilha;

//	TESTA SE A PILHA ESTÁ VAZIA
bool isEmpty(Pilha *p) {
	return p->topo == -1;
}

//	INICIALIZA UMA PILHA DEFININDO O TOPO COMO -1
void inicializar(Pilha *p) {
	p->topo = -1;
}

//	ADICIONA UM VALOR AO TOPO DA PILHA
void push(Pilha *p, int data) {
	if(p->topo == TAM-1) {
		printf("Pilha Cheia!\n");
		return;
	}
	p->topo++;
	p->dados[p->topo] = data;
}

//	IMPRIME TODOS OS VALORES DA PILHA
void imprimePilha(Pilha *p){
	if(isEmpty(p)) {
		printf("Pilha Vazia!\n");
		return;
	}
	int i;
	for(i = 0; i <= p->topo; i++) {
		printf("%d ", p->dados[i]);
	}
}

//	TRAZ O VALOR DO TOPO DA PILHA SEM TIRAR ELE
int top(Pilha *p) {
	if(isEmpty(p)) {
		printf("Pilha Vazia!\n");
		return;
	}
	return p->dados[p->topo];
}

//	TRAZ O VALOR DO TOPO DA PILHA TIRANDO ELE EM SEGUIDA
int pop(Pilha *p) {
	if(isEmpty(p)) {
		printf("\nPilha Vazia!\n");
		return 0;
	}
	int temp = p->dados[p->topo];
	p->topo--;
	return temp;
}

//=========================================================   MAIN   =========================================================

main() {
	
	/*	4. Remover elementos pares da pilha 
			Dada uma pilha de inteiros, remova todos os números pares mantendo a 
			ordem dos ímpares. 	*/
			
	Pilha pilha, impares;
	inicializar(&pilha);
	inicializar(&impares);
	int i, num;
	
	// Ordem da pilha -> 13 22 87 6 99 41 26
	push(&pilha, 13);
	push(&pilha, 22);
	push(&pilha, 87);
	push(&pilha, 6);
	push(&pilha, 99);
	push(&pilha, 41);
	push(&pilha, 26);
	
	printf("Pilha Criada: ");
	for (i = 0; i <= pilha.topo; i++) {
		printf("%d ", pilha.dados[i]);
	}
	
	// Resultado esperado -> 13 87 99 41	
	
	while (!isEmpty(&pilha)) {
		num = pop(&pilha);
		if (num % 2 != 0) {
			push(&impares, num);
		}
	}
	
	while (!isEmpty(&impares)) {
		push(&pilha, pop(&impares));
	}
	
	printf("\n\nResultado final: ");
	imprimePilha(&pilha);
}
