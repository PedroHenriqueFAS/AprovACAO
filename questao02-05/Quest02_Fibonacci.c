#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Fun��o recursiva para verificar se um n�mero pertence � sequ�ncia de Fibonacci
int fibonacci(int num, int a, int b) {
    // Se o n�mero atual na sequ�ncia de Fibonacci for igual ao n�mero informado, retorna 1
    if (b == num || num == 0)
        return 1;
    // Se o n�mero atual na sequ�ncia de Fibonacci for maior que o n�mero informado, retorna 0
    else if (b > num)
        return 0;
    // Chamada recursiva para calcular o pr�ximo n�mero na sequ�ncia de Fibonacci
    else
        return fibonacci(num, b, a + b);
}

int main() {
    int num, continuar = 1;
    setlocale(LC_ALL, "Portuguese");

    while (continuar) {
        int validar = 0, y=1;
            printf("Digite um n�mero para verificar se pertence � sequ�ncia de Fibonacci: ");
            while (!validar) {
            if (scanf("%d", &num) == 1) {
                validar = 1;
            } else {
                printf("\nEntrada inv�lida!!!\nPor favor, insira apenas n�meros para verifica��o da sequ�ncia de Fibonacci: ");
                // Limpar o buffer de entrada
                while (getchar() != '\n');
            }
        }

        if (fibonacci(num, 0, 1))
            printf("%d pertence � sequ�ncia de Fibonacci.\n", num);
        else
            printf("%d n�o pertence � sequ�ncia de Fibonacci.\n", num);
		
        printf("\nDeseja verificar outro n�mero? (1 - Sim, 0 - N�o): ");
         while (scanf("%d", &continuar) != 1 || (continuar != 0 && continuar != 1)) {
            printf("Op��o inv�lida! Digite (1 - Sim, 0 - N�o): ");          
            while (getchar() != '\n');
        }
	}
	
	printf("\n\n-------------Tenha um excelente dia!-------------");

    return 0;
}

