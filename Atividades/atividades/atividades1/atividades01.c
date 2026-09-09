#include <stdio.h>

#define VALOR_REFEICAO 12.50f
#define VALOR_CAFE 4.00f

int main(void)
{
    int qtd_refeicoes;
    int qtd_cafes;
    float disponivel;
    float gasto_refeicoes;
    float gasto_cafes;
    float gasto_total;
    float saldo;

    printf("Quantidade de refeicoes: ");
    scanf("%d", &qtd_refeicoes);

    printf("Quantidade de cafes: ");
    scanf("%d", &qtd_cafes);

    printf("Valor disponivel no cartao: ");
    scanf("%f", &disponivel);

    /* Calcula os gastos da semana e o saldo restante. */
    gasto_refeicoes = qtd_refeicoes * VALOR_REFEICAO;
    gasto_cafes = qtd_cafes * VALOR_CAFE;
    gasto_total = gasto_refeicoes + gasto_cafes;
    saldo = disponivel - gasto_total;

    printf("\nGasto refeicoes: %.2f\n", gasto_refeicoes);
    printf("Gasto cafes: %.2f\n", gasto_cafes);
    printf("Gasto total: %.2f\n", gasto_total);
    printf("Saldo restante: %.2f\n", saldo);

    return 0;
}