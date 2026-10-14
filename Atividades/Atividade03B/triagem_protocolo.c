/*
O fall-through consciente e vantajoso ocorre no switch da prioridade,
quando as letras 'U' e 'u' compartilham o mesmo tratamento de urgencia.
Assim, evitamos repetir o mesmo bloco de codigo para letras maiusculas
e minusculas, mantendo o programa mais simples e organizado.
O switch seleciona casos por valores especificos, enquanto o if-else-if
e mais adequado para classificar faixas de renda usando comparacoes
como menor que, maior ou igual, que representam intervalos numericos.
*/

#include <stdio.h>

int main(void) {
    int servico, dia;
    char prioridade;

    printf("=== TRIAGEM DE PROTOCOLOS ===\n");

    printf("Codigo do servico (1 a 8): ");
    if (scanf("%d", &servico) != 1) {
        printf("Entrada invalida para o servico.\n");
        return 1;
    }

    printf("Prioridade (N = normal, U/u = urgente): ");
    if (scanf(" %c", &prioridade) != 1) {
        printf("Entrada invalida para a prioridade.\n");
        return 1;
    }

    printf("Dia da semana (4 = expediente pleno, 6 = sexta reduzida): ");
    if (scanf("%d", &dia) != 1) {
        printf("Entrada invalida para o dia.\n");
        return 1;
    }

    printf("\n=== RESULTADO DA TRIAGEM ===\n");

    printf("Servico: ");
    switch (servico) {
        case 1:
        case 2:
            printf("Documento simples\n");
            break;

        case 3:
        case 4:
            printf("Solicitacao administrativa\n");
            break;

        case 5:
        case 6:
            printf("Ato solene\n");
            break;

        case 7:
        case 8:
            printf("Atendimento especial\n");
            break;

        default:
            printf("Codigo de servico invalido\n");
            break;
    }

    printf("Prioridade: ");
    switch (prioridade) {
        case 'N':
        case 'n':
            printf("Normal\n");
            break;

        case 'U':
        case 'u':
            printf("Urgente\n");
            break;

        default:
            printf("Prioridade invalida\n");
            break;
    }

    printf("Expediente: ");
    switch (dia) {
        case 4:
            printf("Expediente pleno\n");
            break;

        case 6:
            printf("Sexta-feira com expediente reduzido\n");
            break;

        case 1:
        case 2:
        case 3:
        case 5:
        case 7:
            printf("Dia valido, horario nao especificado\n");
            break;

        default:
            printf("Dia invalido\n");
            break;
    }

    return 0;
}
