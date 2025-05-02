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

// Função para calcular densidade, PIB per capita e super poder
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

// Função que compara duas cartas com base no atributo População
void compararPorPopulacao(Carta c1, Carta c2) {
    printf("\n\n===== Comparação de Cartas (Atributo: População) =====\n");
    printf("Carta 1 - %s (%s): %lu habitantes\n", c1.nome_cidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%s): %lu habitantes\n", c2.nome_cidade, c2.estado, c2.populacao);

    if (c1.populacao > c2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else if (c2.populacao > c1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

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

    // Comparação baseada em População
    compararPorPopulacao(carta1, carta2);

    return 0;
}
