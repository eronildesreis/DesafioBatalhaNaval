#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10 // Tamanho do tabuleiro
#define NUM_SHIPS 5   // Número de embarcações

// Estrutura para o tabuleiro
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];  // Tabuleiro de jogo
    int ships[NUM_SHIPS][2];             // Coordenadas das embarcações
} GameBoard;

// Função para inicializar o tabuleiro com água (representada por '.')
void initBoard(GameBoard *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = '.'; // Cada célula é inicialmente água
        }
    }
}

// Função para exibir o tabuleiro (com as embarcações visíveis para o jogador)
void printBoard(GameBoard *game, int showShips) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (showShips && game->board[i][j] == 'S') {
                printf("S ");  // Exibe 'S' se a embarcação estiver visível
            } else {
                printf("%c ", game->board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Função para colocar as embarcações no tabuleiro de maneira aleatória
void placeShips(GameBoard *game) {
    srand(time(NULL));  // Para garantir que os números aleatórios sejam diferentes a cada execução

    for (int i = 0; i < NUM_SHIPS; i++) {
        int x, y;

        // Procurar posições válidas para as embarcações
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
        } while (game->board[x][y] == 'S');  // Verificar se a posição já está ocupada

        game->board[x][y] = 'S';  // Coloca a embarcação no tabuleiro
        game->ships[i][0] = x;    // Salva as coordenadas da embarcação
        game->ships[i][1] = y;
    }
}

// Função para realizar um ataque e verificar se o jogador acertou ou errou
int attack(GameBoard *game, int x, int y) {
    if (game->board[x][y] == 'S') {
        game->board[x][y] = 'X'; // Marca o ataque como "acerto"
        return 1;  // Retorna 1 para "acerto"
    } else {
        game->board[x][y] = 'O'; // Marca o ataque como "erro"
        return 0;  // Retorna 0 para "erro"
    }
}

// Função para verificar se o jogo acabou (todas as embarcações foram afundadas)
int gameOver(GameBoard *game) {
    for (int i = 0; i < NUM_SHIPS; i++) {
        if (game->board[game->ships[i][0]][game->ships[i][1]] == 'S') {
            return 0; // Ainda há embarcações no tabuleiro
        }
    }
    return 1; // Todas as embarcações foram afundadas
}

int main() {
    GameBoard player1, player2;

    // Inicializa os tabuleiros dos dois jogadores
    initBoard(&player1);
    initBoard(&player2);

    // Coloca as embarcações nos tabuleiros dos jogadores
    placeShips(&player1);
    placeShips(&player2);

    int x, y;
    int currentPlayer = 1;  // Começa com o jogador 1
    int result;

    // Loop do jogo
    while (1) {
        printf("Jogador %d, faça seu ataque!\n", currentPlayer);
        printBoard(currentPlayer == 1 ? &player2 : &player1, 0);  // Exibe o tabuleiro do adversário (sem mostrar as embarcações)

        // Solicita ao jogador as coordenadas para o ataque
        printf("Digite as coordenadas do ataque (linha e coluna): ");
        scanf("%d %d", &x, &y);

        // Verificar se as coordenadas são válidas
        if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Coordenadas inválidas! Tente novamente.\n");
            continue;
        }

        // Realiza o ataque
        result = attack(currentPlayer == 1 ? &player2 : &player1, x, y);

        // Exibe o resultado do ataque
        if (result) {
            printf("Acertou! Você afundou uma embarcação.\n");
        } else {
            printf("Errou! Não houve acerto.\n");
        }

        // Verifica se o jogo acabou
        if (gameOver(currentPlayer == 1 ? &player2 : &player1)) {
            printf("Jogador %d venceu!\n", currentPlayer);
            break;
        }

        // Alterna para o próximo jogador
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}