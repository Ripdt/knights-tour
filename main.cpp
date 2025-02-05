
#include <iostream>
#include "chessboard.h"

void printChessboard(const Chessboard& chessboard) {
    for (unsigned int i = 0; i < N_BOARD_LINES; i++) {
        for (unsigned int j = 0; j < N_BOARD_COLUMNS; j++) {
            std::cout << "\t" << chessboard[i][j]; // Print element directly
        }
        std::cout << std::endl;
    }
}

int main() {
    Chessboard chessboard;

    printChessboard(chessboard);



    return 0;
}