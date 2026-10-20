#include <stdio.h>
#include <stdbool.h>


void printBoard(char* _row, int _rowLength)
{
    printf("Board:\n\n");
    for (size_t i = 0; i < _rowLength; i++)
    {
        printf("%c\t", _row[i]);
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
    }
    printf("\n\n");
}

bool boardComplete(char* _row, char _playerInput)
{
    int correct[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++)
    {
        if (
            _row[correct[i][0]] == _playerInput &&
            _row[correct[i][1]] == _playerInput &&
            _row[correct[i][2]] == _playerInput
        )
        {
            return true;
        }
    }

    return false;
}


int main() {
    char row[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int rowLength = sizeof(row) / sizeof(char);

    printf("\nWelcome to Tic Tac Toe!!!\n\n");
    printf("Player 1 uses 'X'\n");
    printf("Player 2 uses 'O'\n\n");

    bool isPlayer1Turn = true;

    while (true)
    {
        int entry;
        char* currentPlay = isPlayer1Turn ? "Player 1" : "Player 2";
        char input = isPlayer1Turn ? 'X' : 'O';

        do {
            printf("%s's turn: ", currentPlay);
            scanf("%d", &entry);
        } while (!entry || entry < 1 || entry > 9);

        if (row[entry - 1] == 'X' || row[entry - 1] == 'O')
        {
            printf("Already some entry exists. Try a different spot!!\n");
            continue;
        }
        else
        {
            row[entry - 1] = input;
        }

        printBoard(row, rowLength);

        if (boardComplete(row, input)) {
            printf("%s Wins!!!\n\n", currentPlay);
            break;
        }

        isPlayer1Turn = !isPlayer1Turn;
    }

    return 0;
}
