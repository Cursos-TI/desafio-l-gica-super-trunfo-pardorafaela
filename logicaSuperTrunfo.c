#include <stdio.h>

// Desafio Super Trunfo - Países
// Nível Avançado: Comparações com Atributos Múltiplos
// O jogador escolhe dois atributos para comparar duas cartas de países.
// Regra geral: maior valor vence. Exceção: Densidade Demográfica (menor vence).
// O vencedor final é determinado pela maior soma dos dois atributos escolhidos.

int main() {

    // =========================================================
    // CARTAS PRÉ-CADASTRADAS
    // =========================================================

    // --- Carta 1: Brasil ---
    char nome1[]    = "Brasil";
    char codigo1[]  = "A01";
    long long int populacao1         = 215300000;   // habitantes
    double        area1              = 8515767.0;   // km²
    double        pib1               = 1920.0;      // bilhões de USD
    int           pontosTuristicos1  = 12;
    double        densidadeDemografica1 = (double)populacao1 / area1; // hab/km²

    // --- Carta 2: Japão ---
    char nome2[]    = "Japao";
    char codigo2[]  = "B01";
    long long int populacao2         = 125700000;   // habitantes
    double        area2              = 377975.0;    // km²
    double        pib2               = 4940.0;      // bilhões de USD
    int           pontosTuristicos2  = 18;
    double        densidadeDemografica2 = (double)populacao2 / area2; // hab/km²

    // =========================================================
    // VARIÁVEIS DE CONTROLE
    // =========================================================

    int opcao1, opcao2;                          // opções escolhidas nos menus
    double valorAtrib1Carta1, valorAtrib1Carta2; // valores do 1º atributo
    double valorAtrib2Carta1, valorAtrib2Carta2; // valores do 2º atributo
    double somaAtribCarta1,  somaAtribCarta2;    // somas para cada carta
    const char *nomeAtrib1, *nomeAtrib2;         // nomes dos atributos escolhidos
    const char *unidadeAtrib1, *unidadeAtrib2;   // unidades de medida
    int atrib1EhDensidade, atrib2EhDensidade;    // flag: densidade tem regra inversa

    // =========================================================
    // EXIBIÇÃO DAS CARTAS
    // =========================================================

    printf("================================================\n");
    printf("          BEM-VINDO AO SUPER TRUNFO!\n");
    printf("================================================\n\n");

    printf("--- Carta 1: %s (Codigo: %s) ---\n", nome1, codigo1);
    printf("  1. Populacao:              %lld hab\n",       populacao1);
    printf("  2. Area:                   %.2f km2\n",       area1);
    printf("  3. PIB:                    %.2f bi USD\n",    pib1);
    printf("  4. Pontos Turisticos:      %d\n",             pontosTuristicos1);
    printf("  5. Densidade Demografica:  %.4f hab/km2\n\n", densidadeDemografica1);

    printf("--- Carta 2: %s (Codigo: %s) ---\n", nome2, codigo2);
    printf("  1. Populacao:              %lld hab\n",       populacao2);
    printf("  2. Area:                   %.2f km2\n",       area2);
    printf("  3. PIB:                    %.2f bi USD\n",    pib2);
    printf("  4. Pontos Turisticos:      %d\n",             pontosTuristicos2);
    printf("  5. Densidade Demografica:  %.4f hab/km2\n\n", densidadeDemografica2);

    // =========================================================
    // MENU 1 — ESCOLHA DO PRIMEIRO ATRIBUTO
    // =========================================================

    printf("================================================\n");
    printf("  Escolha o PRIMEIRO atributo para comparar:\n");
    printf("================================================\n");
    printf("  1. Populacao\n");
    printf("  2. Area\n");
    printf("  3. PIB\n");
    printf("  4. Pontos Turisticos\n");
    printf("  5. Densidade Demografica\n");
    printf("------------------------------------------------\n");
    printf("Opcao: ");
    scanf("%d", &opcao1);

    // Valida a entrada do primeiro atributo
    if (opcao1 < 1 || opcao1 > 5) {
        printf("Opcao invalida! Encerrando o programa.\n");
        return 1;
    }

    // =========================================================
    // MENU 2 — ESCOLHA DO SEGUNDO ATRIBUTO (DINÂMICO)
    // O atributo já escolhido não aparece como opção.
    // =========================================================

    printf("\n================================================\n");
    printf("  Escolha o SEGUNDO atributo para comparar:\n");
    printf("================================================\n");
    if (opcao1 != 1) printf("  1. Populacao\n");
    if (opcao1 != 2) printf("  2. Area\n");
    if (opcao1 != 3) printf("  3. PIB\n");
    if (opcao1 != 4) printf("  4. Pontos Turisticos\n");
    if (opcao1 != 5) printf("  5. Densidade Demografica\n");
    printf("------------------------------------------------\n");
    printf("Opcao: ");
    scanf("%d", &opcao2);

    // Valida a entrada do segundo atributo: deve ser válido e diferente do primeiro
    if (opcao2 < 1 || opcao2 > 5) {
        printf("Opcao invalida! Encerrando o programa.\n");
        return 1;
    } else if (opcao2 == opcao1) {
        printf("Atributo ja selecionado! Escolha um atributo diferente. Encerrando o programa.\n");
        return 1;
    }

    // =========================================================
    // OBTENÇÃO DOS VALORES E NOMES DOS ATRIBUTOS ESCOLHIDOS
    // =========================================================

    // --- Primeiro atributo ---
    atrib1EhDensidade = 0;
    switch (opcao1) {
        case 1:
            nomeAtrib1        = "Populacao";
            unidadeAtrib1     = "hab";
            valorAtrib1Carta1 = (double)populacao1;
            valorAtrib1Carta2 = (double)populacao2;
            break;
        case 2:
            nomeAtrib1        = "Area";
            unidadeAtrib1     = "km2";
            valorAtrib1Carta1 = area1;
            valorAtrib1Carta2 = area2;
            break;
        case 3:
            nomeAtrib1        = "PIB";
            unidadeAtrib1     = "bi USD";
            valorAtrib1Carta1 = pib1;
            valorAtrib1Carta2 = pib2;
            break;
        case 4:
            nomeAtrib1        = "Pontos Turisticos";
            unidadeAtrib1     = "pts";
            valorAtrib1Carta1 = (double)pontosTuristicos1;
            valorAtrib1Carta2 = (double)pontosTuristicos2;
            break;
        case 5:
            nomeAtrib1        = "Densidade Demografica";
            unidadeAtrib1     = "hab/km2";
            valorAtrib1Carta1 = densidadeDemografica1;
            valorAtrib1Carta2 = densidadeDemografica2;
            atrib1EhDensidade = 1; // regra inversa: menor valor vence
            break;
        default:
            nomeAtrib1        = "Desconhecido";
            unidadeAtrib1     = "";
            valorAtrib1Carta1 = 0.0;
            valorAtrib1Carta2 = 0.0;
            break;
    }

    // --- Segundo atributo ---
    atrib2EhDensidade = 0;
    switch (opcao2) {
        case 1:
            nomeAtrib2        = "Populacao";
            unidadeAtrib2     = "hab";
            valorAtrib2Carta1 = (double)populacao1;
            valorAtrib2Carta2 = (double)populacao2;
            break;
        case 2:
            nomeAtrib2        = "Area";
            unidadeAtrib2     = "km2";
            valorAtrib2Carta1 = area1;
            valorAtrib2Carta2 = area2;
            break;
        case 3:
            nomeAtrib2        = "PIB";
            unidadeAtrib2     = "bi USD";
            valorAtrib2Carta1 = pib1;
            valorAtrib2Carta2 = pib2;
            break;
        case 4:
            nomeAtrib2        = "Pontos Turisticos";
            unidadeAtrib2     = "pts";
            valorAtrib2Carta1 = (double)pontosTuristicos1;
            valorAtrib2Carta2 = (double)pontosTuristicos2;
            break;
        case 5:
            nomeAtrib2        = "Densidade Demografica";
            unidadeAtrib2     = "hab/km2";
            valorAtrib2Carta1 = densidadeDemografica1;
            valorAtrib2Carta2 = densidadeDemografica2;
            atrib2EhDensidade = 1; // regra inversa: menor valor vence
            break;
        default:
            nomeAtrib2        = "Desconhecido";
            unidadeAtrib2     = "";
            valorAtrib2Carta1 = 0.0;
            valorAtrib2Carta2 = 0.0;
            break;
    }

    // =========================================================
    // COMPARAÇÃO INDIVIDUAL DE CADA ATRIBUTO
    // Regra geral: maior valor vence.
    // Exceção — Densidade Demográfica: menor valor vence.
    // Resultado: 1 = Carta1 vence | 2 = Carta2 vence | 0 = empate
    // =========================================================

    int venceuAtrib1, venceuAtrib2;

    // Comparação do primeiro atributo (operador ternário)
    if (valorAtrib1Carta1 == valorAtrib1Carta2) {
        venceuAtrib1 = 0;
    } else if (atrib1EhDensidade) {
        venceuAtrib1 = (valorAtrib1Carta1 < valorAtrib1Carta2) ? 1 : 2;
    } else {
        venceuAtrib1 = (valorAtrib1Carta1 > valorAtrib1Carta2) ? 1 : 2;
    }

    // Comparação do segundo atributo (operador ternário)
    if (valorAtrib2Carta1 == valorAtrib2Carta2) {
        venceuAtrib2 = 0;
    } else if (atrib2EhDensidade) {
        venceuAtrib2 = (valorAtrib2Carta1 < valorAtrib2Carta2) ? 1 : 2;
    } else {
        venceuAtrib2 = (valorAtrib2Carta1 > valorAtrib2Carta2) ? 1 : 2;
    }

    // =========================================================
    // SOMA DOS ATRIBUTOS E VENCEDOR FINAL
    // =========================================================

    somaAtribCarta1 = valorAtrib1Carta1 + valorAtrib2Carta1;
    somaAtribCarta2 = valorAtrib1Carta2 + valorAtrib2Carta2;

    // Vencedor final: maior soma vence (operador ternário)
    int vencedorFinal = (somaAtribCarta1 > somaAtribCarta2) ? 1 :
                        (somaAtribCarta2 > somaAtribCarta1) ? 2 : 0;

    // =========================================================
    // EXIBIÇÃO DOS RESULTADOS
    // =========================================================

    printf("\n================================================\n");
    printf("              RESULTADO DA RODADA\n");
    printf("================================================\n\n");

    printf("Paises comparados: %s  vs  %s\n\n", nome1, nome2);

    // --- Resultado do primeiro atributo ---
    printf("--- Atributo 1: %s", nomeAtrib1);
    if (atrib1EhDensidade) printf(" (menor vence)");
    printf(" ---\n");
    printf("  %-6s : %.4f %s\n", nome1, valorAtrib1Carta1, unidadeAtrib1);
    printf("  %-6s : %.4f %s\n", nome2, valorAtrib1Carta2, unidadeAtrib1);
    if (venceuAtrib1 == 0)
        printf("  Resultado: EMPATE neste atributo\n\n");
    else
        printf("  Vencedor: %s\n\n", (venceuAtrib1 == 1) ? nome1 : nome2);

    // --- Resultado do segundo atributo ---
    printf("--- Atributo 2: %s", nomeAtrib2);
    if (atrib2EhDensidade) printf(" (menor vence)");
    printf(" ---\n");
    printf("  %-6s : %.4f %s\n", nome1, valorAtrib2Carta1, unidadeAtrib2);
    printf("  %-6s : %.4f %s\n", nome2, valorAtrib2Carta2, unidadeAtrib2);
    if (venceuAtrib2 == 0)
        printf("  Resultado: EMPATE neste atributo\n\n");
    else
        printf("  Vencedor: %s\n\n", (venceuAtrib2 == 1) ? nome1 : nome2);

    // --- Soma dos atributos ---
    printf("--- Soma dos Atributos (%s + %s) ---\n", nomeAtrib1, nomeAtrib2);
    printf("  %-6s : %.4f\n", nome1, somaAtribCarta1);
    printf("  %-6s : %.4f\n\n", nome2, somaAtribCarta2);

    // --- Vencedor final ---
    printf("================================================\n");
    if (vencedorFinal == 0) {
        printf("  RESULTADO FINAL: EMPATE!\n");
    } else {
        printf("  VENCEDOR FINAL: %s!\n", (vencedorFinal == 1) ? nome1 : nome2);
    }
    printf("================================================\n");

    return 0;
}
