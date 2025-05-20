#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "board.h"
#include <vector>

bool processLine(std::vector<int>& line, int& score);
bool move(Board& board, int& score, int dx, int dy);

#endif // GAMELOGIC_H
