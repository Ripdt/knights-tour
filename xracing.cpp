#include <iostream>
#include <vector>
using namespace std;

#define N 8 // Tamanho do tabuleiro 8x8

// Movimentos possíveis do cavalo
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Função para verificar se a posição (x, y) é válida no tabuleiro
bool isSafe(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Função recursiva de busca por profundidade (DFS) para resolver o problema
bool dfs(int x, int y, int moveCount, vector<vector<int>>& board) {
    cout << "Tentando: (" << x << ", " << y << ") - Move: " << moveCount << endl; // Debug

    if (moveCount == N * N) {
        return true; // Se o cavalo visitou todas as casas
    }

    // Tentar todos os 8 movimentos possíveis
    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isSafe(newX, newY, board)) {
            board[newX][newY] = moveCount; // Marca a posição como visitada
            if (dfs(newX, newY, moveCount + 1, board)) {
                return true; // Encontrou uma solução
            }
            board[newX][newY] = -1; // Desfaz o movimento se não for a solução
        }
    }

    return false; // Não encontrou solução a partir desta posição
}

// Função para resolver o problema
bool solveKnightTour(int startX, int startY) {
    vector<vector<int>> board(N, vector<int>(N, -1)); // Tabuleiro 8x8
    board[startX][startY] = 0; // Marca a posição inicial como 0 (primeiro movimento)

    // Inicia a busca por profundidade
    if (dfs(startX, startY, 1, board)) {
        // Se encontrar uma solução, imprime o tabuleiro
        cout << "Solução encontrada! Tabuleiro final:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
        return true;
    }
    
    // Caso não encontre solução, imprime o tabuleiro com as tentativas realizadas
    cout << "Nao foi possivel encontrar uma solucao. Tabuleiro final com tentativas:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << "\t"; // Imprime o tabuleiro mostrando as tentativas feitas
        }
        cout << endl;
    }

    return false; // Se não encontrar solução
}

int main() {
    int startX, startY;
    
    // Entrada: posição inicial do cavalo (deve ser entre 0 e 7 para um tabuleiro 8x8)
    cout << "Digite as coordenadas iniciais do cavalo (x, y): ";
    cin >> startX >> startY;

    if (!solveKnightTour(startX, startY)) {
        cout << "Nao foi possivel encontrar uma solucao para o problema do cavalo." << endl;
    }

    return 0;
}
