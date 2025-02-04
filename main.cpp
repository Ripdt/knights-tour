#include <iostream>
#include <list>

#define MAX_POSSIBLE_MOVES 8;

class Square {
    private:
    const int line, column;

    public:
    Square(const int _line, const int _column) : line(_line), column(_column) {}
    int getLine() const { return line; }
    int getColumn() const { return column; }
    bool isValid() const { return line >= 0 && line < 8 && column >= 0 && column < 8; }
};

bool hasUnvisittedSquares(const bool chessBoard[8][8])
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (!chessBoard[i][j]) 
                return true;

    return false;
}

void tour(std::list<Square>& path, const Square& sq, bool (&chessBoard)[8][8]) {
    bool& isVisitted = chessBoard[sq.getLine()][sq.getColumn()];
    if (isVisitted || !sq.isValid())
        return;

    isVisitted = true;
    path.push_back(sq);

    Square newHorizontalSquare1(sq.getLine() - 2, sq.getColumn() - 1);
    Square newHorizontalSquare2(sq.getLine() - 2, sq.getColumn() + 1);
    Square newHorizontalSquare3(sq.getLine() + 2, sq.getColumn() - 1);
    Square newHorizontalSquare4(sq.getLine() + 2, sq.getColumn() + 1);

    Square newVerticalSquare1(sq.getLine() - 1, sq.getColumn() - 2);
    Square newVerticalSquare2(sq.getLine() - 1, sq.getColumn() + 2);
    Square newVerticalSquare3(sq.getLine() + 1, sq.getColumn() - 2);
    Square newVerticalSquare4(sq.getLine() + 1, sq.getColumn() + 2);
}


int main(const int initialLine, const int initialColumn) {
    bool chessBoard[8][8];
    Square initialSquare(initialLine, initialColumn);
    std::list<Square> path;

    tour(path, initialSquare, chessBoard);

    return 0;
}