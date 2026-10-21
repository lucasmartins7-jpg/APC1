/*
 * Por que o menu precisa de do-while, e nao de while?
 * O do-while garante que o menu seja exibido pelo menos uma vez, mesmo antes
 * de qualquer leitura da opcao. Com while, seria necessario ler a opcao antes
 * do laço, o que poderia deixar o menu sem aparecer se a condicao falhasse.
 *
 * Em qual trecho o continue evita contar uma senha invalida?
 * No registro de lote (opcao 1): ao ler senha negativa, o continue salta o
 * restante do corpo do while, evitando incrementar atendidas e pares.
 *
 * O que ocorreria na busca prioritaria se o break fosse omitido?
 * O laço infinito continuaria lendo senhas para sempre, sem nunca sair,
 * mesmo apos encontrar prioritaria ou zero.
 */

#include <stdio.h>

int main(void) {
    int opcao;

    do {
        printf("===== PAINEL DE SENHAS =====\n");
        printf("1 - Registrar lote\n");
        printf("2 - Simular chamadas\n");
        printf("3 - Grade de guiches\n");
        printf("4 - Buscar senha prioritaria\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) {
            /* limpa entrada invalida */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            opcao = -1;
        }

        if (opcao == 0) {
            /* sai do do-while */
        } else if (opcao == 1) {
            /* Registrar lote: while + continue */
            int senha;
            int atendidas = 0;
            int ignoradas = 0;
            int pares = 0;

            printf("Senha: ");
            scanf("%d", &senha);

            while (senha != 0) {
                if (senha < 0) {
                    ignoradas++;
                    /* continue evita contar em atendidas/pares */
                    printf("Senha: ");
                    scanf("%d", &senha);
                    continue;
                }
                /* senha positiva */
                atendidas++;
                if (senha % 2 == 0) {
                    pares++;
                }
                printf("Senha: ");
                scanf("%d", &senha);
            }

            printf("Atendidas : %d\n", atendidas);
            printf("Ignoradas : %d\n", ignoradas);
            printf("Pares : %d\n", pares);

        } else if (opcao == 2) {
            /* Simular chamadas: for com passo */
            int inicio, fim, passo;
            printf("Inicio: ");
            scanf("%d", &inicio);
            printf("Fim: ");
            scanf("%d", &fim);
            printf("Passo: ");
            scanf("%d", &passo);

            if (passo == 0) {
                printf("Passo invalido\n");
            } else {
                int i;
                int executou = 0;
                printf("Chamadas: ");
                if (passo > 0) {
                    for (i = inicio; i <= fim; i += passo) {
                        if (executou) {
                            printf(" ");
                        }
                        printf("%d", i);
                        executou = 1;
                    }
                } else {
                    for (i = inicio; i >= fim; i += passo) {
                        if (executou) {
                            printf(" ");
                        }
                        printf("%d", i);
                        executou = 1;
                    }
                }
                if (!executou) {
                    printf("Nenhuma chamada");
                }
                printf("\n");
            }

        } else if (opcao == 3) {
            /* Grade de guiches: laços aninhados */
            int G, S;
            printf("Guiches (1 a 4): ");
            scanf("%d", &G);
            printf("Senhas por guiche (1 a 5): ");
            scanf("%d", &S);

            if (G < 1 || G > 4 || S < 1 || S > 5) {
                printf("Grade invalida\n");
            } else {
                int g, s;
                for (g = 1; g <= G; g++) {
                    printf("Guiche %d:", g);
                    for (s = 1; s <= S; s++) {
                        printf(" %d", s);
                    }
                    printf("\n");
                }
            }

        } else if (opcao == 4) {
            /* Buscar senha prioritaria: laço infinito + break */
            int senha;
            int lidas = 0;

            for (;;) {
                printf("Senha: ");
                scanf("%d", &senha);

                if (senha == 0) {
                    printf("Nao encontrada\n");
                    printf("Lidas : %d\n", lidas);
                    break;
                }
                if (senha > 0 && senha % 10 == 0) {
                    printf("Prioritaria : %d\n", senha);
                    printf("Lidas antes : %d\n", lidas);
                    break;
                }
                /* qualquer outro valor (positivo nao multiplo de 10 ou negativo) */
                lidas++;
            }

        } else {
            printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    printf("Painel encerrado.\n");
    return 0;
}
