#include "chessboard.h"

#include <iostream>

Chessboard::Chessboard() : matrix(N_BOARD_LINE, N_BOARD_COLUMN) {}

Chessboard& Chessboard::operator=(
    const Chessboard& other
)
{
    if (this != &other) {
        numberOfVisitedSquares = other.numberOfVisitedSquares;
        matrix = other.matrix;
    }
    return *this;
}

bool Chessboard::hasUnvisitedSquare() const
{
    return numberOfVisitedSquares != N_BOARD_LINE * N_BOARD_COLUMN;
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

void Chessboard::markVisitedSquare(
    const int i,
    const int j
)
{
    numberOfVisitedSquares++;
    matrix[i][j] = numberOfVisitedSquares;
}