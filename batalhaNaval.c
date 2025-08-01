#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAMANHO_NAVIO 3

int pode_posicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * dLinha;
        int c = coluna + i * dColuna;

        if (l < 0 || l >= TAM || c < 0 || c >= TAM)
            return 0;

        if (tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * dLinha;
        int c = coluna + i * dColuna;
        tabuleiro[l][c] = NAVIO;
    }
}

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

int main() {
    int tabuleiro[TAM][TAM] = {0};

    int l1 = 1, c1 = 2;
    if (pode_posicionar(tabuleiro, l1, c1, 0, 1))
        posicionar_navio(tabuleiro, l1, c1, 0, 1);

    int l2 = 5, c2 = 4;
    if (pode_posicionar(tabuleiro, l2, c2, 1, 0))
        posicionar_navio(tabuleiro, l2, c2, 1, 0);

    int l3 = 0, c3 = 0;
    if (pode_posicionar(tabuleiro, l3, c3, 1, 1))
        posicionar_navio(tabuleiro, l3, c3, 1, 1);

    int l4 = 0, c4 = 9;
    if (pode_posicionar(tabuleiro, l4, c4, 1, -1))
        posicionar_navio(tabuleiro, l4, c4, 1, -1);

    exibir_tabuleiro(tabuleiro);

    return 0;
}
