#include <stdio.h>
#include <string.h>
#include <time.h>

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
    c->super_poder = (float)c->populacao + c->area_km2 + (c->pib * 1000000000.0f)
                     + c->pontos_turisticos + c->pib_per_capita + (1.0f / c->densidade_populacional);
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

// Função para obter o valor de um atributo
float obterAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area_km2;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade_populacional;
        case 6: return c.pib_per_capita;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
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

    // Menu de comparação com dois atributos
    int atributo1, atributo2;

    printf("\n===== MENU DE COMPARAÇÃO COM DOIS ATRIBUTOS =====\n");
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != atributo1) {
                printf("%d - %s\n", i, nomeAtributo(i));
            }
        }
        printf("Opção: ");
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) {
            printf("Você não pode escolher o mesmo atributo duas vezes!\n");
        }
    } while (atributo2 == atributo1);

    float valor1_attr1 = obterAtributo(carta1, atributo1);
    float valor2_attr1 = obterAtributo(carta2, atributo1);

    float valor1_attr2 = obterAtributo(carta1, atributo2);
    float valor2_attr2 = obterAtributo(carta2, atributo2);

    // Regra especial para densidade: menor vence
    int vencedor_attr1 = (atributo1 == 5) ? (valor1_attr1 < valor2_attr1 ? 1 : (valor2_attr1 < valor1_attr1 ? 2 : 0))
                                          : (valor1_attr1 > valor2_attr1 ? 1 : (valor2_attr1 > valor1_attr1 ? 2 : 0));

    int vencedor_attr2 = (atributo2 == 5) ? (valor1_attr2 < valor2_attr2 ? 1 : (valor2_attr2 < valor1_attr2 ? 2 : 0))
                                          : (valor1_attr2 > valor2_attr2 ? 1 : (valor2_attr2 > valor1_attr2 ? 2 : 0));

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    int vencedor_final = (soma1 > soma2) ? 1 : (soma2 > soma1 ? 2 : 0);

    // Exibição dos resultados
    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("%s vs %s\n", carta1.nome_cidade, carta2.nome_cidade);
    printf("\nAtributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2f | %s: %.2f\n", carta1.nome_cidade, valor1_attr1, carta2.nome_cidade, valor2_attr1);

    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2f | %s: %.2f\n", carta1.nome_cidade, valor1_attr2, carta2.nome_cidade, valor2_attr2);

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", carta1.nome_cidade, soma1);
    printf("%s: %.2f\n", carta2.nome_cidade, soma2);

    printf("\nResultado Final: ");
    switch (vencedor_final) {
        case 1:
            printf("Vencedor: %s\n", carta1.nome_cidade);
            break;
        case 2:
            printf("Vencedor: %s\n", carta2.nome_cidade);
            break;
        default:
            printf("Empate!\n");
    }

    return 0;
}