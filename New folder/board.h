#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

using Board = std::vector<std::vector<int>>;
void addRandomTile(Board& board);
bool checkWin(const Board& board);
bool canMove(const Board& board);

#endif // BOARD_H
