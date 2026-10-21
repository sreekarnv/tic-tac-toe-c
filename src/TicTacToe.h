#pragma once
#include <stdbool.h>

#ifndef BOARD_SIZE
#define BOARD_SIZE 9
#endif

#ifndef WIN_COMBINATION
#define WIN_COMBINATION 8
#endif

void printBoard(const char* row);

bool validateBoard(const char* row, char playerInput);

int playGame();
