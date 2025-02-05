
#include "chessboard.h"

#include <iostream>
#include <chrono>

struct Square
{
    int line, column;
};

bool isValidLine(const int line) {
    return line >= 0 && line < N_BOARD_LINE;
}

bool isValidColumn(const int column) {
    return column >= 0 && column < N_BOARD_COLUMN;
}

bool isValidSquare(const Chessboard& board, const int line, const int column) {
    return isValidLine(line) && isValidColumn(column) &&
           !board.isVisitedSquare(line, column);
}

Square* newSquare(const int line, const int column, const Chessboard& board) 
{
    if (isValidSquare(board, line, column)) {
        auto newSqr = new Square;
        newSqr->line = line; newSqr->column = column;
        return newSqr;
    }

    return nullptr;
}

std::vector<Square*> validSquares(const Square* currentSquare, const Chessboard& board) 
{
    std::vector<Square*> valids;

    if (currentSquare == nullptr) {
        std::cerr << "Error: currentSquare is nullptr." << std::endl;
        return valids;
    }

    const int currentLine = currentSquare->line;
    const int currentColumn = currentSquare->column;

    if (Square* next = newSquare(currentLine + 2, currentColumn + 1, board))
         valids.push_back(next);
    
    if (Square* next = newSquare(currentLine + 2, currentColumn - 1, board))
         valids.push_back(next);
    
    if (Square* next = newSquare(currentLine - 2, currentColumn + 1, board))
         valids.push_back(next);
    
    if (Square* next = newSquare(currentLine - 2, currentColumn - 1, board))
         valids.push_back(next);
    
    if (Square* next = newSquare(currentLine + 1, currentColumn + 2, board))
         valids.push_back(next);
    
    if (Square* next = newSquare(currentLine + 1, currentColumn - 2, board))
         valids.push_back(next);
    
    if (Square* next = newSquare(currentLine - 1, currentColumn + 2, board))
         valids.push_back(next);
    
    if (Square* next = newSquare(currentLine - 1, currentColumn - 2, board))
         valids.push_back(next);

    return valids;
}

void tour(Chessboard& board, const Square* currentSquare) 
{
    if (currentSquare == nullptr) {
        std::cerr << "Error: Current square is nullptr." << std::endl;
        return;
    }

    board.markVisitedSquare(currentSquare->line, currentSquare->column);

    Chessboard model = board;
    std::vector<Square*> valids = validSquares(currentSquare, board);
    
    for (Square* current : valids)
    {
        tour(model, current);
        if (!model.hasUnvisitedSquare()) {
            board = model;
            break;
        }
        else {
            model = board;
        }
    }
    
    for (Square* current : valids)
    {
        delete current;
    }
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <initialLine> <initialColumn>" << std::endl;
        return 1;
    }

    const int initialLine = std::atoi(argv[1]);
    const int initialColumn = std::atoi(argv[2]);

    Chessboard board;

    Square* initialSquare = newSquare(initialLine, initialColumn, board);

    if (initialSquare == nullptr) {
        std::cerr << "Error: Initial square is invalid." << std::endl;
        return 1;
    }

    auto start = std::chrono::high_resolution_clock::now();

    tour(board, initialSquare);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Path:" << std::endl;
    board.printChessboard();

    std::cout << std::endl << std::endl << "Execution time: " << duration.count() << " seconds" << std::endl;

    delete initialSquare;

    return 0;
}