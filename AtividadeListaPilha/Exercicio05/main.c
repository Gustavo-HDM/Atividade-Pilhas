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
	
	/* 5. Ordenar uma pilha
		Dada uma pilha de inteiros, use apenas operações de pilha para ordená-la 
		em ordem crescete (pode usar pilha auxiliar) */	
		
	Pilha pilha, aux;
	inicializar(&pilha);
	inicializar(&aux);
	int i;
		
	push(&pilha, 67);
	push(&pilha, 82);
	push(&pilha, 14);
	push(&pilha, 2);
	push(&pilha, 91);
	push(&pilha, 38);
	
	printf("Ordem inicial da pilha: "); // 67 82 14 2 91 38
	imprimePilha(&pilha);
	
	while (!isEmpty(&pilha)) {
		int temp = pop(&pilha);

		while (!isEmpty(&aux) && top(&aux) < temp) {
			push(&pilha, pop(&aux));
		}

		push(&aux, temp);
	}
	
	printf("\nOrdem final: ");
	imprimePilha(&aux);
}
