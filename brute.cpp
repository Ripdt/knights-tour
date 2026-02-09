#include <iostream>
#include <chrono>
#include <algorithm>

#include "chessboard.h"

const int moves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool brute(int x, int y, Chessboard& board, int& step) {
    if (!board.hasUnvisitedSquare()) {
        return true;
    }

    ++step;
    std::vector<std::pair<int, int>> available;
    for (int i = 0; i < 8; i++) {
        int nextX = x + moves[i][0];
        int nextY = y + moves[i][1];
        if (board.isValidSquare(nextX, nextY) && !board.isVisitedSquare(nextX, nextY)) {
            int distanceToEdge = std::min({nextX, nextY, board.getHeight() - nextX - 1, board.getWidth() - nextY - 1});
            available.emplace_back(distanceToEdge, i);
        }
    }

    for (const auto& move : available) {
        const int i = move.second;
        const int nextX = x + moves[i][0];
        const int nextY = y + moves[i][1];

        board.markVisitedSquare(nextX, nextY);
        if (brute(nextX, nextY, board, step)) {
            return true;
        }
        board.unmarkVisitedSquare(nextX, nextY);
    }
    return false;
}

void tour(const int initialLine, const int initialColumn, int& step) {
    Chessboard board;

    board.markVisitedSquare(initialLine, initialColumn);
    ++step;
    if (brute(initialLine, initialColumn, board, step)) {
        std::cout << "Path:" << std::endl;
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
    int step = 0;

    auto start = std::chrono::high_resolution_clock::now();

    tour(initialLine, initialColumn, step);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << std::endl << std::endl << "Execution time: " << duration.count() << " seconds" << std::endl;
    std::cout << "Steps: " << step << std::endl;
    
    return 0;
}
