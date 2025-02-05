#include "chessboard.h"


Chessboard::Chessboard() : matrix(N_BOARD_LINE, N_BOARD_COLUMN) {}

bool Chessboard::hasUnvisittedSquare() const
{
    for (int i = 0; i < N_BOARD_LINE; i++)
        for (int j = 0; j < N_BOARD_COLUMN; j++)
            if (matrix[i][j] == 0)
                return true;

    return false;
}