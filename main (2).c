#include <stdio.h>
#include <math.h>
#include <string.h>

// Função para converter um número binário em decimal
double binarioToDecimal(char *binario) {
    int tamanho = strlen(binario);
    double decimal = 0.0;

    for (int i = tamanho - 1; i >= 0; i--) {
        if (binario[i] == '1') {
            decimal += pow(2, tamanho - 1 - i);
        }
    }

    return decimal;
}

// Função para converter um número decimal em binário
void decimalTobinario(double decimal) {
    int integralPart = (int)decimal;
    double fractionalPart = decimal - integralPart;

    // Convertendo a parte inteira para binário
    char binarioIntegral[64];
    sprintf(binarioIntegral, "%d", integralPart);
    printf("Parte inteira em binário: %s\n", binarioIntegral);

    // Convertendo a parte fracionária para binário
    printf("Parte fracionária em binário: ");
    for (int i = 0; i < 10; i++) {  // Convertendo até 10 casas decimais de precisão
        fractionalPart *= 2;
        int bit = (int)fractionalPart;
        printf("%d", bit);
        fractionalPart -= bit;
    }
    printf("\n");
}

int main() {
    int escolha;
    printf("Escolha uma opção:\n");
    printf("1. Converter binário para decimal\n");
    printf("2. Converter decimal para binário\n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        char binario[64];
        printf("Digite o número binário: ");
        scanf("%s", binario);
        double decimalValue = binarioToDecimal(binario);
        printf("Valor em decimal: %lf\n", decimalValue);
    } else if (escolha == 2) {
        double decimal;
        printf("Digite o número decimal: ");
        scanf("%lf", &decimal);
        decimalTobinario(decimal);
    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}
