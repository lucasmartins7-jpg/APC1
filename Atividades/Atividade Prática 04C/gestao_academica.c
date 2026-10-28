/*
 * Resposta teórica:
 * Ao declarar char nome[50], reservamos 50 posições de memória. O último índice
 * (posição 49) deve conter o caractere nulo '\0' que marca o fim da string em C.
 * Portanto, só podemos armazenar no máximo 49 caracteres úteis.
 *
 * Em int M[3][4], o primeiro índice representa as linhas (3) e o segundo as
 * colunas (4). A linguagem C organiza os elementos em memória contígua no
 * modo row-major (ordem por linhas): primeiro todos os elementos da linha 0
 * (M[0][0] até M[0][3]), depois a linha 1, e assim por diante, formando um
 * bloco linear de 12 inteiros consecutivos.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    int opcao;

    do {
        printf("\n===== SISTEMA DE GESTAO ACADEMICA =====\n");
        printf("1 - Cadastrar Lista de Alunos (Vetor de Strings)\n");
        printf("2 - Estatisticas de Desempenho (Vetor de Float)\n");
        printf("3 - Matriz de Notas da Turma (Matriz Bidimensional)\n");
        printf("4 - Consultar Aluno em Destaque (Pesquisa em Matriz/Vetor)\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        /* Limpa o buffer residual do scanf */
        while (getchar() != '\n');

        switch (opcao) {
            case 1: {
                /* Opcao 1: Vetor de strings (matriz de char) */
                char alunos[5][50];
                printf("\n--- Cadastro de Alunos ---\n");
                for (int i = 0; i < 5; i++) {
                    printf("Nome do aluno %d: ", i + 1);
                    fgets(alunos[i], sizeof(alunos[i]), stdin);
                    /* Remove a quebra de linha capturada pelo fgets */
                    alunos[i][strcspn(alunos[i], "\n")] = '\0';
                }
                printf("\nLista de Alunos cadastrados:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d - %s\n", i + 1, alunos[i]);
                }
                break;
            }

            case 2: {
                /* Opcao 2: Vetor de float - estatisticas */
                float notas_finais[5];
                float soma = 0.0f;
                printf("\n--- Estatisticas de Desempenho ---\n");
                /* Primeiro preenche todo o vetor */
                for (int i = 0; i < 5; i++) {
                    printf("Nota final do aluno %d: ", i + 1);
                    scanf("%f", &notas_finais[i]);
                    soma += notas_finais[i];
                }
                while (getchar() != '\n'); /* limpa buffer */

                /* Depois processa os dados */
                float media = soma / 5.0f;
                int qtd_acima = 0;
                for (int i = 0; i < 5; i++) {
                    if (notas_finais[i] >= media) {
                        qtd_acima++;
                    }
                }
                printf("\nMedia geral da turma: %.2f\n", media);
                printf("Quantidade de alunos com nota >= media: %d\n", qtd_acima);
                break;
            }

            case 3: {
                /* Opcao 3: Matriz bidimensional 3x4 */
                float boletim[3][4];
                printf("\n--- Matriz de Notas da Turma ---\n");
                /* Preenchimento com laços aninhados */
                for (int i = 0; i < 3; i++) {
                    printf("Notas do aluno %d:\n", i + 1);
                    for (int j = 0; j < 4; j++) {
                        printf("  Bimestre %d: ", j + 1);
                        scanf("%f", &boletim[i][j]);
                    }
                }
                while (getchar() != '\n'); /* limpa buffer */

                /* Exibe a matriz em formato de tabela + media por aluno */
                printf("\nBoletim da Turma:\n");
                printf("Aluno | Bim1   Bim2   Bim3   Bim4  | Media\n");
                printf("------|---------------------------|-------\n");
                for (int i = 0; i < 3; i++) {
                    float soma_aluno = 0.0f;
                    printf("  %d   | ", i + 1);
                    for (int j = 0; j < 4; j++) {
                        printf("%5.1f  ", boletim[i][j]);
                        soma_aluno += boletim[i][j];
                    }
                    printf("| %.2f\n", soma_aluno / 4.0f);
                }
                break;
            }

            case 4: {
                /* Opcao 4: Pesquisa da maior nota e seu indice */
                float notas[5];
                printf("\n--- Consultar Aluno em Destaque ---\n");
                for (int i = 0; i < 5; i++) {
                    printf("Nota do aluno %d: ", i + 1);
                    scanf("%f", &notas[i]);
                }
                while (getchar() != '\n'); /* limpa buffer */

                float maior = notas[0];
                int indice = 0;
                for (int i = 1; i < 5; i++) {
                    if (notas[i] > maior) {
                        maior = notas[i];
                        indice = i;
                    }
                }
                printf("\nMaior nota da turma: %.2f\n", maior);
                printf("Indice (posicao) encontrado: %d (aluno %d)\n", indice, indice + 1);
                break;
            }

            case 0:
                printf("\nEncerrando o sistema. Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}