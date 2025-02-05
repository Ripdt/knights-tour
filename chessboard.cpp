#include "chessboard.h"

#include <iostream>

Chessboard::Chessboard() : matrix(N_BOARD_LINE, N_BOARD_COLUMN) {}

Chessboard& Chessboard::operator=(
    const Chessboard& other
)
{
    std::cout << "Assigning Chessboard" << std::endl;
    if (this != &other) {
        std::cout << "Copying matrix" << std::endl;
        matrix = other.matrix; // Check if this line is reached
    }
    return *this;
}

bool Chessboard::hasUnvisittedSquare() const
{
    for (int i = 0; i < N_BOARD_LINE; i++)
        for (int j = 0; j < N_BOARD_COLUMN; j++)
            if (!isVisitedSquare(i, j))
                return true;

    return false;
}

bool Chessboard::isVisitedSquare(
    const int i,
    const int j
) const
{
    return matrix[i][j] > 0;
}


void Chessboard::printChessboard() const 
{
    for (unsigned int i = 0; i < N_BOARD_LINE; i++) {
        for (unsigned int j = 0; j < N_BOARD_COLUMN; j++) {
            std::cout << "\t" << matrix[i][j];
        }
        std::cout << std::endl;
    }
}