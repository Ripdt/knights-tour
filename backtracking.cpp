#include <iostream>
#include <chrono>
#include <algorithm>

#include "chessboard.h"

const int moves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool solveKTUtil(int x, int y, Chessboard& board) {
    if (!board.hasUnvisitedSquare()) {
        return true;
    }

    std::vector<std::pair<int, int>> orderedMoves;
    for (int i = 0; i < 8; i++) {
        int nextX = x + moves[i][0];
        int nextY = y + moves[i][1];
        if (board.isValidSquare(nextX, nextY)) {
            int distanceToEdge = std::min({nextX, nextY, board.getHeight() - nextX - 1, board.getWidth() - nextY - 1});
            orderedMoves.emplace_back(distanceToEdge, i);
        }
    }

    std::sort(orderedMoves.begin(), orderedMoves.end());
    
    for (int i = 0; i < 8; i++) {
        const int nextX = orderedMoves.at(i).first, nextY = orderedMoves.at(i).second;
        if (board.isValidSquare(nextX, nextY) && !board.isVisitedSquare(nextX, nextY)) {
            board.markVisitedSquare(nextX, nextY);
            if (solveKTUtil(nextX, nextY, board)) {
                return true;
            }
            board.unmarkVisitedSquare(nextX, nextY);
        }
    }
    return false;
}

void solveKT(const int initialLine, const int initialColumn) {
    Chessboard board;

    board.markVisitedSquare(initialLine, initialColumn);

    if (solveKTUtil(initialLine, initialColumn, board)) {
        board.printChessboard();
    } else {
        std::cout << "Solution does not exist" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <initialLine> <initialColumn>" << std::endl;
        return 1;
    }

    const int initialLine = std::atoi(argv[1]);
    const int initialColumn = std::atoi(argv[2]);

    auto start = std::chrono::high_resolution_clock::now();

    solveKT(initialLine, initialColumn);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << std::endl << std::endl << "Execution time: " << duration.count() << " seconds" << std::endl;
    
    return 0;
}
