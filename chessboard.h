#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "matrix.h"

#define N_BOARD_LINE 8
#define N_BOARD_COLUMN 8

class Chessboard
{
private:
    Matrix<int> matrix;
    int numberOfVisitedSquares = 0;

public:
    Chessboard();

    void printChessboard() const;
    bool hasUnvisitedSquare() const;
    bool isVisitedSquare(const int i, const int j) const;
    void markVisitedSquare(const int i, const int j);
    void unmarkVisitedSquare(const int i, const int j);
    bool isValidSquare(const int i, const int j) const;
    int getHeight() const;
    int getWidth() const;

    Chessboard& operator=(const Chessboard& other);
};

#endif