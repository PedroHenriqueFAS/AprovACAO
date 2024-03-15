#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_SIZE 1000

//----Uma vaga de estagio seria otima!----
typedef struct {
    char data[MAX_SIZE];
    int top;
} Pilha;

// inicializa��o da pilha
void initialize(Pilha *pilha) {
    pilha->top = -1;
}

// Verificando se a pilha est� vazia
int isEmpty(Pilha *pilha) {
    return pilha->top == -1;
}

// Verificando se a pilha est� cheia
int isFull(Pilha *pilha) {
    return pilha->top == MAX_SIZE - 1;
}

// Empilhando um caractere na pilha
void push(Pilha *pilha, char item) {
    if (isFull(pilha)) {
        printf("Erro: pilha cheia\n");
        return;
    }
    pilha->data[++pilha->top] = item;
}

// Desempilhando um caractere da pilha
char pop(Pilha *pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: pilha vazia\n");
        return '\0';
    }
    return pilha->data[pilha->top--];
}

// Invertendo os caracteres de uma string usando uma pilha
void reverseString(char *str) {
    Pilha pilha;
    int i;

    initialize(&pilha);

    // Empilhando os caracteres da string
    for (i = 0; i < strlen(str); i++) {
        push(&pilha, str[i]);
    }

    // Desempilhando os caracteres da pilha para reverter a string
    for (i = 0; i < strlen(str); i++) {
        str[i] = pop(&pilha);
    }
}

int main() {
    char str[MAX_SIZE];
    int continuar = 1;
    
    setlocale(LC_ALL, "Portuguese");

	while (continuar){

    printf("Digite qualquer nome ou n�mero: ");
    fgets(str, MAX_SIZE, stdin);

    // Usado para remover o caractere de nova linha inserido pelo fgets
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Caracteres invertido: %s\n", str);
    
    printf("\nDeseja verificar outro nome/n�mero como ficaria inverdido?  digite (1 - Sim, 0 - N�o): ");
    
    while(fgets(str, sizeof(str), stdin) == NULL || sscanf(str, "%d", &continuar) != 1 || (continuar != 0 && continuar != 1)){
    	printf("N�mero inv�lido! Digite (1 - Sim, 0 - N�o): ");
		}
	printf("\n");
	}
	
	printf("\n--------Tenha um excelente dia!--------");
    return 0;
}

