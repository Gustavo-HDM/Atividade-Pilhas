#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TAM 10

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
	
	/*	1. Inverter elementos de um vetor usando pilha 
			Dado um vetor de inteiros, use uma pilha para inverter a ordem dos elementos. 	*/
	
	srand(time(NULL));
	int vetor[TAM], i;
	Pilha pilha;
	inicializar(&pilha);
	
	for (i = 0; i < TAM; i++) {
		vetor[i] = rand() % 90 + 10	;	// Valor aleatório de 10 a 99
	}
	
	printf("Valores preenchidos no vetor:\n");
	
	for (i = 0; i < TAM; i++) {
		printf("%d ", vetor[i]);
		push(&pilha, vetor[i]);
	}
	
	printf("\n\nVetor invertido utilizando a pilha:\n");
	
	for (i = 0; i < TAM; i++) {
		vetor[i] = pop(&pilha);	
	}
	
	for (i = 0; i < TAM; i++) {
		printf("%d ", vetor[i]);
	}
}
