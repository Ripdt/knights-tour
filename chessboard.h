#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "matrix.h"

#define N_BOARD_LINE 8
#define N_BOARD_COLUMN 8

class Chessboard
{
private:
    Matrix<int> matrix;

public:
    Chessboard();

    void printChessboard() const;
    bool hasUnvisittedSquare() const;
    bool isVisitedSquare(const int i, const int j) const;

    Chessboard& operator=(const Chessboard& other);
};

#endif