#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define TAM 50

//	ESTRUTURA PARA UMA PILHA
typedef struct {
	char dados[TAM];
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
void push(Pilha *p, char data) {
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

void mostrarFrase(Pilha *p) {
	int i;
	for (i = 0; i <= p->topo; i++) {
		printf("%c", p->dados[i]);
	}
	printf("\n");
}

char menu() {
	char character;
	printf("(Aperte 1 para desfazer, 2 para refazer e 3 para finalizar a frase)\n");
	printf("Adicione um character a frase e aperte enter: ");
	scanf(" %c", &character);	
	return character;
}
//=========================================================   MAIN   =========================================================
char resposta;
main() {
	
	/* 3. Simular desfazer/refazer (undo/redo) 
		Use duas pilhas para simular o comportamento de desfazer e refazer 
		operações (ex: edição de texto). */
		
	Pilha desfazer, refazer;
	inicializar(&desfazer);
	inicializar(&refazer);
	
	char opt;
	
	while (1) {
		mostrarFrase(&desfazer);
		opt = menu();

		if (opt == '3') {
			printf("\nFrase final: ");
			mostrarFrase(&desfazer);
			break;
		}

		if (opt == '1') {
			if (!isEmpty(&desfazer)) {
				int c = pop(&desfazer);
				push(&refazer, c);
			} else {
				printf("\nNao foi possivel desfazer!\n");
			}
		} else if (opt == '2') {
			if (!isEmpty(&refazer)) {
				int c = pop(&refazer);
				push(&desfazer, c);
			} else {
				printf("\nNao foi possivel refazer!\n");
			}
		} else {
			push(&desfazer, opt);
			inicializar(&refazer);
		}
	}
}
