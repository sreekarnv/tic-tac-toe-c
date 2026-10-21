#include "TicTacToe.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void printBoard(const char* row)
{
    printf("Board:\n\n");
    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        printf("%c\t", row[i]);
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
    }
    printf("\n\n");
}

bool validateBoard(const char* row, char playerInput)
{
    static int correct[WIN_COMBINATION][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (size_t i = 0; i < WIN_COMBINATION; i++)
    {
        if (
            row[correct[i][0]] == playerInput &&
            row[correct[i][1]] == playerInput &&
            row[correct[i][2]] == playerInput
        )
        {
            return true;
        }
    }

    return false;
}

int playGame()
{
    char row[BOARD_SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    printf("\nWelcome to Tic Tac Toe!!!\n\n");
    printf("Player 1 uses 'X'\n");
    printf("Player 2 uses 'O'\n\n");

    bool isPlayer1Turn = true;
    int moveCount = 0;

    while (true)
    {
        long entry;
        char* currentPlay = isPlayer1Turn ? "Player 1" : "Player 2";
        char input = isPlayer1Turn ? 'X' : 'O';

        char buffer[100];

        while (true)
        {
            printf("%s's Turn: ", currentPlay);
            if (fgets(buffer, sizeof(buffer), stdin) != NULL)
            {
                if (strlen(buffer) == 1)
                {
                    printf("Received Empty Input. Try Again!!\n");
                    continue;
                }


                long _entry = strtol(buffer, NULL, 10);

                if (_entry < 1 || _entry > 9)
                {
                    printf("Received Invalid Entry. Try Entering Digits (1-9).\n");
                    continue;
                }

                entry = _entry;
                break;
            }
        }

        if (row[entry - 1] == 'X' || row[entry - 1] == 'O')
        {
            printf("Already some entry exists. Try a different spot!!\n");
            continue;
        }
        else
        {
            row[entry - 1] = input;
        }

        printBoard(row);

        if (validateBoard(row, input)) {
            printf("%s Wins!!!\n\n", currentPlay);
            break;
        }

        if (moveCount == 8) {
            printf("Draw!!");
            break;
        }

        isPlayer1Turn = !isPlayer1Turn;
        moveCount++;
    }

    return 0;
}
