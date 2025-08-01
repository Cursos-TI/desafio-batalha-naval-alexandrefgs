#include <stdio.h>

#define TAM 10
#define TAM_HAB 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void construir_cone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = (j >= TAM_HAB/2 - i && j <= TAM_HAB/2 + i) ? 1 : 0;
        }
    }
}

void construir_cruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = (i == TAM_HAB/2 || j == TAM_HAB/2) ? 1 : 0;
        }
    }
}

void construir_octaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = (abs(i - TAM_HAB/2) + abs(j - TAM_HAB/2) <= TAM_HAB/2) ? 1 : 0;
        }
    }
}

void aplicar_habilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int linha, int coluna) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linTab = linha - offset + i;
            int colTab = coluna - offset + j;

            if (linTab >= 0 && linTab < TAM && colTab >= 0 && colTab < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linTab][colTab] == AGUA) {
                    tabuleiro[linTab][colTab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;
    tabuleiro[8][7] = NAVIO;

    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    construir_cone(cone);
    construir_cruz(cruz);
    construir_octaedro(octaedro);

    aplicar_habilidade(tabuleiro, cone, 1, 2);
    aplicar_habilidade(tabuleiro, cruz, 5, 5);
    aplicar_habilidade(tabuleiro, octaedro, 7, 2);
    exibir_tabuleiro(tabuleiro);

    return 0;
}
