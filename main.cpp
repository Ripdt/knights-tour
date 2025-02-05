
#include "chessboard.h"

#include <iostream>

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
    std::cout << "init validSquares\n";
    std::vector<Square*> valids;

    // Check if currentSquare is nullptr
    if (currentSquare == nullptr) {
        std::cerr << "Error: currentSquare is nullptr." << std::endl;
        return valids; // Return an empty vector
    }

    const int currentLine = currentSquare->line;
    const int currentColumn = currentSquare->column;

    // Generate valid squares
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

    std::cout << "leaving validSquares\n";
    return valids;
}

void tour(Chessboard& board, const Square* currentSquare) 
{
    std::cout << "init tour\n"; 
    if (currentSquare == nullptr) {
        std::cerr << "Error: Current square is nullptr." << std::endl;
        return;
    }

    Chessboard model = board;
    std::vector<Square*> valids = validSquares(currentSquare, board);

    std::cout << "init connects\n";
    
    for (Square* current : valids)
    {
        std::cout << "inside\n";
        tour(model, current);
        if (!model.hasUnvisittedSquare()) {
            board = model;
            break;
        }
    }
    
    for (Square* current : valids)
    {
        delete current;
    }

    std::cout << "leaving\n";
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <initialLine> <initialColumn>" << std::endl;
        return 1;
    }

    // Convert command line arguments to integers
    const int initialLine = std::atoi(argv[1]);
    const int initialColumn = std::atoi(argv[2]);

    Chessboard board;

    std::cout << "before\n";
    board.printChessboard();

    Square* initialSquare = newSquare(initialLine, initialColumn, board);

    if (initialSquare == nullptr) {
        std::cerr << "Error: Initial square is invalid." << std::endl;
        return 1; // Exit with an error code
    }

    tour(board, initialSquare);

    std::cout << "after\n";
    board.printChessboard();

    delete initialSquare;

    return 0;
}