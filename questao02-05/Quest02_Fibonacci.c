#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Função recursiva para verificar se um número pertence à sequência de Fibonacci
int fibonacci(int num, int a, int b) {
    // Se o número atual na sequência de Fibonacci for igual ao número informado, retorna 1
    if (b == num || num == 0)
        return 1;
    // Se o número atual na sequência de Fibonacci for maior que o número informado, retorna 0
    else if (b > num)
        return 0;
    // Chamada recursiva para calcular o próximo número na sequência de Fibonacci
    else
        return fibonacci(num, b, a + b);
}

int main() {
    int num, continuar = 1;
    setlocale(LC_ALL, "Portuguese");

    while (continuar) {
        int validar = 0, y=1;
            printf("Digite um número para verificar se pertence à sequência de Fibonacci: ");
            while (!validar) {
            if (scanf("%d", &num) == 1) {
                validar = 1;
            } else {
                printf("\nEntrada inválida!!!\nPor favor, insira apenas números para verificação da sequência de Fibonacci: ");
                // Limpar o buffer de entrada
                while (getchar() != '\n');
            }
        }

        if (fibonacci(num, 0, 1))
            printf("%d pertence à sequência de Fibonacci.\n", num);
        else
            printf("%d não pertence à sequência de Fibonacci.\n", num);
		
        printf("\nDeseja verificar outro número? (1 - Sim, 0 - Não): ");
         while (scanf("%d", &continuar) != 1 || (continuar != 0 && continuar != 1)) {
            printf("Opção inválida! Digite (1 - Sim, 0 - Não): ");          
            while (getchar() != '\n');
        }
	}
	
	printf("\n\n-------------Tenha um excelente dia!-------------");

    return 0;
}

