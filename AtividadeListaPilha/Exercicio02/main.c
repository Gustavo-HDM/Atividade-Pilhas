#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM 20

int resp;

//	ESTRUTURA PARA UMA PILHA
typedef struct {
	char dados[TAM];
	int topo;
} Pilha;

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

//	IMPRIME TODOS OS VALORES DA PILHA
void imprimePilha(Pilha *p){
	printf("Pilha: ");
	int i;
	for(i = 0; i <= p->topo; i++) {
		printf("%c", p->dados[i]);
	}
}

//	TRAZ O VALOR DO TOPO DA PILHA TIRANDO ELE EM SEGUIDA
int pop(Pilha *p) {
	char temp = p->dados[p->topo];
	p->topo--;
	return temp;
}

//=========================================================   MAIN   =========================================================

main() {
	
	Pilha pilha;
	inicializar(&pilha);
	char palin[TAM];
	char palinCheck[TAM];
	int i;
	
	/*	2. Verificar se uma palavra é um palíndromo 
			Leia uma palavra do usuário e use uma pilha para verificar se ela é igual 
			quando lida de trás para frente.	*/
	
	printf("Digite um palindromo para ser verificado: ");
	scanf("%s", palin);

	for (i = 0; i < strlen(palin); i++) {
		palin[i] = toupper(palin[i]);
		push(&pilha, palin[i]);
	}
	
	printf("\nPalavra colocada na pilha: ");
	imprimePilha(&pilha);
	printf("\n\n");
	
	for (i = 0; i < strlen(palin); i++) {
		palinCheck[i] = pop(&pilha);
	}
	
	palinCheck[strlen(palin)] = '\0';
	
	if (strcmp(palin, palinCheck) == 0) {
        printf("Esta palavra e um palindromo! :D\n");
    } else {
        printf("Esta palavra NAO e um palindromo... :(\n");
    }
}
