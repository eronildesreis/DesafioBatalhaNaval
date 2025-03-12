#include <stdio.h>
#include <stdlib.h>

#define N 10 // Tamanho do tabuleiro (10x10)

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = '.';  // Representa água no tabuleiro
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[N][N]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navios no tabuleiro
void posicionarNavios(char tabuleiro[N][N]) {
    // Exemplo: Colocando navios fixos (N para navio)
    tabuleiro[2][3] = 'N'; // Navio na posição (2, 3)
    tabuleiro[5][6] = 'N'; // Navio na posição (5, 6)
    tabuleiro[7][8] = 'N'; // Navio na posição (7, 8)
}

// Função para realizar um ataque (simples)
void atacar(char tabuleiro[N][N], int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
        if (tabuleiro[x][y] == 'N') {
            printf("Acertou um navio na posição (%d, %d)!\n", x, y);
            tabuleiro[x][y] = 'X'; // Marca o navio atingido com 'X'
        } else {
            printf("Água na posição (%d, %d).\n", x, y);
            tabuleiro[x][y] = '~'; // Marca a água atingida com '~'
        }
    } else {
        printf("Posição inválida no tabuleiro!\n");
    }
}

// Função para simular um ataque de habilidade especial (área de efeito)
void atacarAreaEfeito(char tabuleiro[N][N], int x, int y) {
    printf("Realizando ataque de área de efeito na posição (%d, %d)...\n", x, y);
    // Verificar a área ao redor do ponto de impacto (raio de 1)
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < N && j >= 0 && j < N) {
                if (tabuleiro[i][j] == 'N') {
                    printf("Navio atingido na posição (%d, %d) devido ao ataque de área de efeito!\n", i, j);
                    tabuleiro[i][j] = 'X'; // Marca navio atingido
                } else if (tabuleiro[i][j] == '.') {
                    tabuleiro[i][j] = '~'; // Marca água atingida
                }
            }
        }
    }
}

int main() {
    // Inicializa o tabuleiro
    char tabuleiro[N][N];
    inicializarTabuleiro(tabuleiro);

    // Posiciona alguns navios no tabuleiro
    posicionarNavios(tabuleiro);

    // Exibe o tabuleiro inicial
    exibirTabuleiro(tabuleiro);

    // Realiza um ataque simples
    int x, y;
    printf("\nDigite as coordenadas para o ataque (linha e coluna, 0-9): ");
    scanf("%d %d", &x, &y);
    atacar(tabuleiro, x, y);
    exibirTabuleiro(tabuleiro);

    // Realiza um ataque de área de efeito
    printf("\nDigite as coordenadas para o ataque de área de efeito (linha e coluna, 0-9): ");
    scanf("%d %d", &x, &y);
    atacarAreaEfeito(tabuleiro, x, y);
    exibirTabuleiro(tabuleiro);

    return 0;
}
