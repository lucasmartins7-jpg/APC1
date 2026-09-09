/*
 * O scanf("%s") lê apenas uma palavra até encontrar um espaço.
 * Por isso, ele não consegue ler corretamente nomes compostos.
 * Por exemplo, ao ler "Maria Silva Souza", o scanf("%s")
 * armazenaria somente "Maria".
 * Neste programa, usamos fgets() para ler o nome completo,
 * permitindo espaços entre as palavras.
 * Depois da leitura, o '\n' deixado pelo fgets() é substituído
 * por '\0', evitando que ele apareça na saída do recibo.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char cliente[100];
    char produto[100];
    char categoria;
    int codigo;
    int quantidade;
    float preco_unitario;
    float total;

    printf("Nome completo do cliente: ");
    fgets(cliente, sizeof(cliente), stdin);
    cliente[strcspn(cliente, "\n")] = '\0';

    printf("Codigo do produto: ");
    scanf("%d", &codigo);

    /*
     * Limpa o '\n' deixado pelo scanf antes de usar fgets().
     */
    while (getchar() != '\n');

    printf("Nome do produto: ");
    fgets(produto, sizeof(produto), stdin);
    produto[strcspn(produto, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    printf("Preco unitario: ");
    scanf("%f", &preco_unitario);

    printf("Categoria (A, B ou C): ");
    scanf(" %c", &categoria);

    total = quantidade * preco_unitario;

    printf("\n========================================\n");
    printf("           RECIBO DE COMPRA\n");
    printf("========================================\n");
    printf("%-10s: %s\n", "Cliente", cliente);
    printf("%-10s: %s\n", "Produto", produto);
    printf("%-10s: %d\n", "Codigo", codigo);
    printf("%-10s: %c\n", "Categoria", categoria);
    printf("%-10s: %d\n", "Qtd", quantidade);
    printf("%-10s: R$ %.2f\n", "Unitario", preco_unitario);
    printf("%-10s: R$ %.2f\n", "Total", total);
    printf("========================================\n");

    return 0;
}