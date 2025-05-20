#include "display.h"
#include "constants.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        std::cout << "\033[2J\033[H";
    #endif
}

void displayBoard(const Board& board, int score) {
    std::cout << "======== 2048 Game ========\n";
    std::cout << " Diem: " << score << "\n";

    int cellWidth = 6;

    char top_left_corner    = 218;
    char top_right_corner   = 191;
    char bottom_left_corner = 192;
    char bottom_right_corner= 217;
    char horizontal_line    = 196;
    char vertical_line      = 179;
    char cross              = 197;
    char tee_up             = 193;
    char tee_down           = 194;
    char tee_left           = 180;
    char tee_right          = 195;

    std::cout << top_left_corner;
    for (int j = 0; j < BOARD_SIZE; ++j) {
        for (int k = 0; k < cellWidth; ++k) {
            std::cout << horizontal_line;
        }
        if (j < BOARD_SIZE - 1) {
            std::cout << tee_down;
        }
    }
    std::cout << top_right_corner << "\n";

    for (int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << vertical_line;

        for (int j = 0; j < BOARD_SIZE; ++j) {
            int value = board[i][j];
            if (value == 0) {
                std::cout << std::setw(cellWidth) << " ";
            } else {
                std::cout << std::setw(cellWidth) << value;
            }
            std::cout << vertical_line;
        }
        std::cout << "\n";
        if (i < BOARD_SIZE - 1) {
            std::cout << tee_right;
            for (int j = 0; j < BOARD_SIZE; ++j) {
                for (int k = 0; k < cellWidth; ++k) {
                    std::cout << horizontal_line;
                }
                if (j < BOARD_SIZE - 1) {
                    std::cout << cross;
                }
            }
            std::cout << tee_left << "\n";
        }
    }
    std::cout << bottom_left_corner;
    for (int j = 0; j < BOARD_SIZE; ++j) {
        for (int k = 0; k < cellWidth; ++k) {
            std::cout << horizontal_line;
        }
        if (j < BOARD_SIZE - 1) {
            std::cout << tee_up;
        }
    }
    std::cout << bottom_right_corner << "\n";
}
