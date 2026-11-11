#include <stdio.h>
#include <string.h>

#define MAX 30

enum StatusAluno { REPROVADO = 0, RECUPERACAO = 1, APROVADO = 2 };

struct Aluno {
    int matricula;
    char nome[41];
    float a1;
    float a2;
    enum StatusAluno status;
};

// Função auxiliar para remover a quebra de linha (\n) do fgets
void limpar_quebra_linha(char *str) {
    size_t tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

// Converte o enum StatusAluno para texto explicativo
const char* status_para_texto(enum StatusAluno status) {
    switch (status) {
        case APROVADO:
            return "APROVADO";
        case RECUPERACAO:
            return "RECUPERACAO";
        case REPROVADO:
            return "REPROVADO";
        default:
            return "DESCONHECIDO";
    }
}

// Exibe os dados formatados de um único aluno
void imprimir_aluno(const struct Aluno *a) {
    float media = 0.4f * a->a1 + 0.6f * a->a2;
    printf("%-9d | %-20s | %-4.1f | %-4.1f | %-5.2f | %-11s\n",
           a->matricula,
           a->nome,
           a->a1,
           a->a2,
           media,
           status_para_texto(a->status));
}

int main(void) {
    struct Aluno turma[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n=== MINI CADASTRO DE TURMA ===\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Buscar por matricula\n");
        printf("4. Buscar por trecho do nome\n");
        printf("5. Exibir estatisticas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Saindo...\n");
            break;
        }

        // Limpa o buffer após a leitura da opção
        while (getchar() != '\n');

        switch (opcao) {
            case 1: { // Cadastrar aluno
                if (total >= MAX) {
                    printf("\n[ERRO] Turma cheia! Capacidade maxima de %d alunos atingida.\n", MAX);
                    break;
                }

                struct Aluno novo;

                printf("\n--- Novo Cadastro (%d/%d) ---\n", total + 1, MAX);
                printf("Matricula: ");
                scanf("%d", &novo.matricula);
                while (getchar() != '\n'); // Limpa buffer

                printf("Nome (max 40 chars): ");
                fgets(novo.nome, sizeof(novo.nome), stdin);
                limpar_quebra_linha(novo.nome);

                printf("Nota A1: ");
                scanf("%f", &novo.a1);

                printf("Nota A2: ");
                scanf("%f", &novo.a2);
                while (getchar() != '\n'); // Limpa buffer

                // Cálculo da média e definição do status
                float media = 0.4f * novo.a1 + 0.6f * novo.a2;
                if (media >= 5.0f) {
                    novo.status = APROVADO;
                } else if (media >= 3.0f) {
                    novo.status = RECUPERACAO;
                } else {
                    novo.status = REPROVADO;
                }

                turma[total] = novo;
                total++;
                printf("[SUCESSO] Aluno cadastrado!\n");
                break;
            }

            case 2: { // Listar alunos
                if (total == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                    break;
                }

                printf("\n---------------------------------------------------------------\n");
                printf("Matricula | Nome                 | A1   | A2   | Media | Status     \n");
                printf("---------------------------------------------------------------\n");
                for (int i = 0; i < total; i++) {
                    imprimir_aluno(&turma[i]);
                }
                printf("---------------------------------------------------------------\n");
                break;
            }

            case 3: { // Buscar por matrícula
                if (total == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                    break;
                }

                int mat_busca;
                int encontrado = 0;

                printf("\nInforme a matricula para busca: ");
                scanf("%d", &mat_busca);
                while (getchar() != '\n');

                for (int i = 0; i < total; i++) {
                    if (turma[i].matricula == mat_busca) {
                        printf("\n[ALUNO ENCONTRADO]\n");
                        printf("Matricula | Nome                 | A1   | A2   | Media | Status     \n");
                        printf("---------------------------------------------------------------\n");
                        imprimir_aluno(&turma[i]);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("\n[AVISO] Aluno com matricula %d nao encontrado.\n", mat_busca);
                }
                break;
            }

            case 4: { // Buscar por trecho do nome
                if (total == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                    break;
                }

                char trecho[41];
                int encontrados = 0;

                printf("\nDigite um trecho do nome para busca: ");
                fgets(trecho, sizeof(trecho), stdin);
                limpar_quebra_linha(trecho);

                printf("\n--- Resultados da busca por '%s' ---\n", trecho);
                for (int i = 0; i < total; i++) {
                    // strstr verifica se 'trecho' é subcadena de 'turma[i].nome'
                    if (strstr(turma[i].nome, trecho) != NULL) {
                        if (encontrados == 0) {
                            printf("Matricula | Nome                 | A1   | A2   | Media | Status     \n");
                            printf("---------------------------------------------------------------\n");
                        }
                        imprimir_aluno(&turma[i]);
                        encontrados++;
                    }
                }

                if (encontrados == 0) {
                    printf("Nenhum aluno encontrado contendo '%s' no nome.\n", trecho);
                } else {
                    printf("---------------------------------------------------------------\n");
                    printf("Total de correspondencias: %d\n", encontrados);
                }
                break;
            }

            case 5: { // Estatísticas
                if (total == 0) {
                    printf("\nNenhum aluno cadastrado para gerar estatisticas.\n");
                    break;
                }

                int aprob = 0, recup = 0, reprob = 0;
                float soma_medias = 0.0f;

                for (int i = 0; i < total; i++) {
                    float m = 0.4f * turma[i].a1 + 0.6f * turma[i].a2;
                    soma_medias += m;

                    if (turma[i].status == APROVADO) aprob++;
                    else if (turma[i].status == RECUPERACAO) recup++;
                    else reprob++;
                }

                printf("\n=== ESTATISTICAS DA TURMA ===\n");
                printf("Total de alunos: %d\n", total);
                printf("Aprovados:       %d\n", aprob);
                printf("Recuperacao:     %d\n", recup);
                printf("Reprovados:      %d\n", reprob);
                printf("Media geral:     %.2f\n", soma_medias / total);
                break;
            }

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
