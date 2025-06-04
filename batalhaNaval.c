#include <stdio.h>

#include <stdio.h>

// Tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser posicionado sem ultrapassar limites e sem sobreposição
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int linhaInicial, int colunaInicial, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaInicial + (orientacao == 1 ? i : 0);     // Vertical
        int coluna = colunaInicial + (orientacao == 0 ? i : 0);   // Horizontal

        // Verifica se está dentro dos limites
        if (linha >= TAMANHO_TABULEIRO || coluna >= TAMANHO_TABULEIRO) {
            return 0;
        }

        // Verifica sobreposição
        if (tabuleiro[linha][coluna] != VALOR_AGUA) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linhaInicial, int colunaInicial, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaInicial + (orientacao == 1 ? i : 0);
        int coluna = colunaInicial + (orientacao == 0 ? i : 0);
        tabuleiro[linha][coluna] = VALOR_NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Define coordenadas e orientações dos navios
    // 0 = horizontal, 1 = vertical
    int linhaNavioH = 2, colunaNavioH = 3, orientacaoH = 0;  // Horizontal
    int linhaNavioV = 5, colunaNavioV = 1, orientacaoV = 1;  // Vertical

    // Verifica e posiciona navio horizontal
    if (podePosicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, orientacaoH)) {
        posicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, orientacaoH);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    // Verifica e posiciona navio vertical
    if (podePosicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, orientacaoV)) {
        posicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, orientacaoV);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
