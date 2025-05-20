#include "board.h"
#include "constants.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

void addRandomTile(Board& board) {
    std::vector<std::pair<int, int>> emptyCells;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 0) {
                emptyCells.push_back({i, j});
            }
        }
    }
    if (!emptyCells.empty()) {
        int randomIndex = rand() % emptyCells.size();
        int r = emptyCells[randomIndex].first;
        int c = emptyCells[randomIndex].second;
        board[r][c] = (rand() % 10 < 9) ? 2 : 4;
    }
}

bool checkWin(const Board& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] >= TARGET_WIN) {
                return true;
            }
        }
    }
    return false;
}

bool canMove(const Board& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 0) return true;
            if (j + 1 < BOARD_SIZE && board[i][j] == board[i][j + 1]) return true;
            if (i + 1 < BOARD_SIZE && board[i][j] == board[i + 1][j]) return true;
        }
    }
    return false;
}
