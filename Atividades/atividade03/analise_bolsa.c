/*
 * ============================================================================
 * RESPOSTA CURTA (Atividade 03 - Estruturas Condicionais)
 * ----------------------------------------------------------------------------
 * O operador ternário ?: é mais vantajoso quando precisamos fazer uma
 * atribuição condicional simples e direta em uma única linha, como no cálculo
 * do bônus de pontualidade (5% ou 0%), tornando o código mais conciso e legível
 * do que um if-else completo. Já o if aninhado torna-se indispensável quando
 * precisamos verificar condições dependentes em múltiplos níveis hierárquicos,
 * como na concessão de desconto por faixa social combinada com a média
 * acadêmica, pois exige clareza na estrutura de decisão e boa indentação.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char nome[100];
    int idade;
    float renda, media;
    char pontualidade;

    /* ---------------------------------------------------------------------
     * Leitura dos dados
     * --------------------------------------------------------------------- */
    printf("========================================\n");
    printf("    SISTEMA DE AVALIACAO DE DESCONTO\n");
    printf("========================================\n");

    printf("Nome completo do aluno: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        printf("Erro na leitura do nome.\n");
        return 1;
    }
    /* Remove o '\n' deixado pelo fgets */
    nome[strcspn(nome, "\n")] = '\0';

    printf("Idade do aluno: ");
    scanf("%d", &idade);

    printf("Renda familiar mensal (R$): ");
    scanf("%f", &renda);

    printf("Media academica (0.0 a 10.0): ");
    scanf("%f", &media);

    printf("Pontualidade no pagamento (S/N): ");
    scanf(" %c", &pontualidade);  /* o espaço antes de %c ignora '\n' residual */

    /* ---------------------------------------------------------------------
     * 1) Validacao de Entrada (if / if-else)
     * --------------------------------------------------------------------- */
    if (idade < 16 || renda <= 0.0f) {
        printf("\n----------------------------------------\n");
        printf("ERRO: Dados invalidos para analise.\n");
        printf("Idade deve ser >= 16 e renda deve ser > 0.\n");
        printf("Analise encerrada.\n");
        printf("----------------------------------------\n");
        return 1;
    }

    /* ---------------------------------------------------------------------
     * 2) Classificacao da Faixa Social (if-else-if)
     * --------------------------------------------------------------------- */
    char faixa[20];      /* "Faixa A", "Faixa B" ou "Faixa C" */
    float descontoBase = 0.0f;

    if (renda <= 2000.0f) {
        strcpy(faixa, "Faixa A");

        /* 3) Analise de Desconto - Faixa A (if aninhado) */
        if (media >= 8.5f) {
            descontoBase = 50.0f;
        } else {
            descontoBase = 30.0f;
        }
    } else if (renda <= 5000.0f) {
        strcpy(faixa, "Faixa B");

        /* 3) Analise de Desconto - Faixa B (if aninhado) */
        if (media >= 9.0f) {
            descontoBase = 25.0f;
        } else {
            descontoBase = 10.0f;
        }
    } else {
        strcpy(faixa, "Faixa C");

        /* 3) Analise de Desconto - Faixa C (if aninhado) */
        if (media >= 9.5f) {
            descontoBase = 10.0f;
        } else {
            descontoBase = 0.0f;
        }
    }

    /* ---------------------------------------------------------------------
     * 4) Bonus de Pontualidade (Operador Ternario ?:)
     * --------------------------------------------------------------------- */
    float bonusPontual = (pontualidade == 'S' || pontualidade == 's') ? 5.0f : 0.0f;

    /* ---------------------------------------------------------------------
     * 5) Calculo Final
     * --------------------------------------------------------------------- */
    float descontoTotal = descontoBase + bonusPontual;

    /* Status final: aprovado se obtiver algum desconto */
    const char *status = (descontoTotal > 0.0f)
                            ? "APROVADO PARA BOLSA"
                            : "NAO APROVADO";

    /* ---------------------------------------------------------------------
     * Saida formatada
     * --------------------------------------------------------------------- */
    printf("\n========================================\n");
    printf("Aluno         : %s\n", nome);
    printf("Faixa Social  : %s\n", faixa);
    printf("Media         : %.2f\n", media);
    printf("Desconto Base : %.1f%%\n", descontoBase);
    printf("Bonus Pontual : %.1f%%\n", bonusPontual);
    printf("----------------------------------------\n");
    printf("Desconto Total: %.1f%%\n", descontoTotal);
    printf("Status        : %s\n", status);
    printf("========================================\n");

    return 0;
}
