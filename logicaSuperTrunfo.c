#include <stdio.h>

// Estrutura da carta
typedef struct {
    char estado[50];
    int codigo;
    char nome_cidade[50];
    unsigned long int populacao;
    float area_km2;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular valores derivados
void calcularValores(Carta* c) {
    c->densidade_populacional = c->populacao / c->area_km2;
    c->pib_per_capita = (c->pib * 1000000000.0f) / c->populacao;
    c->super_poder = (float)c->populacao + c->area_km2 + (c->pib * 1000000000.0f) + c->pontos_turisticos + c->pib_per_capita + (1.0f / c->densidade_populacional);
}

// Função para imprimir uma carta
void imprimirCarta(Carta c) {
    printf("\n==== CARTA ====\n");
    printf("Estado/Regi\xC3\xA3o: %s\n", c.estado);
    printf("Código: %d\n", c.codigo);
    printf("Cidade: %s\n", c.nome_cidade);
    printf("Popula\xC3\xA7\xC3\xA3o: %lu\n", c.populacao);
    printf("\xC3\x81rea (km\xC2\xB2): %.2f\n", c.area_km2);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Tur\xC3\xADsticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km\xC2\xB2\n", c.densidade_populacional);
    printf("PIB per Capita: R$ %.2f\n", c.pib_per_capita);
    printf("Super Poder: %.2f\n", c.super_poder);
}

// Função principal
int main() {
    Carta carta1, carta2;

    // Leitura da carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado/Regiao: ");
    scanf(" %[^\n]%*c", carta1.estado);
    printf("Codigo da Carta: ");
    scanf("%d%*c", &carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]%*c", carta1.nome_cidade);
    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);
    printf("Area em KM2: ");
    scanf("%f", &carta1.area_km2);
    printf("PIB (em bilhoes): ");
    scanf("%f", &carta1.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Leitura da carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado/Regiao: ");
    scanf(" %[^\n]%*c", carta2.estado);
    printf("Codigo da Carta: ");
    scanf("%d%*c", &carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]%*c", carta2.nome_cidade);
    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);
    printf("Area em KM2: ");
    scanf("%f", &carta2.area_km2);
    printf("PIB (em bilhoes): ");
    scanf("%f", &carta2.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculos
    calcularValores(&carta1);
    calcularValores(&carta2);

    // Impressão das cartas
    printf("\n\n===== CARTAS CADASTRADAS =====\n");
    imprimirCarta(carta1);
    imprimirCarta(carta2);

    // Menu interativo de comparação
    int escolha;
    printf("\n\n===== MENU DE COMPARAÇÃO =====\n");
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    printf("\nComparando %s e %s\n", carta1.nome_cidade, carta2.nome_cidade);

    switch (escolha) {
        case 1:
            printf("População: %lu vs %lu\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s\n", carta1.nome_cidade);
            else if (carta2.populacao > carta1.populacao)
                printf("Vencedor: %s\n", carta2.nome_cidade);
            else
                printf("Empate!\n");
            break;
        case 2:
            printf("Área: %.2f km² vs %.2f km²\n", carta1.area_km2, carta2.area_km2);
            if (carta1.area_km2 > carta2.area_km2)
                printf("Vencedor: %s\n", carta1.nome_cidade);
            else if (carta2.area_km2 > carta1.area_km2)
                printf("Vencedor: %s\n", carta2.nome_cidade);
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("PIB: R$ %.2f bi vs R$ %.2f bi\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s\n", carta1.nome_cidade);
            else if (carta2.pib > carta1.pib)
                printf("Vencedor: %s\n", carta2.nome_cidade);
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("Pontos Turísticos: %d vs %d\n", carta1.pontos_turisticos, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Vencedor: %s\n", carta1.nome_cidade);
            else if (carta2.pontos_turisticos > carta1.pontos_turisticos)
                printf("Vencedor: %s\n", carta2.nome_cidade);
            else
                printf("Empate!\n");
            break;
        case 5:
            printf("Densidade Populacional: %.2f vs %.2f hab/km²\n", carta1.densidade_populacional, carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional)
                printf("Vencedor: %s (menor densidade vence)\n", carta1.nome_cidade);
            else if (carta2.densidade_populacional < carta1.densidade_populacional)
                printf("Vencedor: %s (menor densidade vence)\n", carta2.nome_cidade);
            else
                printf("Empate!\n");
            break;
        default:
            printf("Opção inválida! Por favor, escolha um número de 1 a 5.\n");
    }

    return 0;
}