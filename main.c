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

int main() {
    char row[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int rowLength = sizeof(row) / sizeof(char);

    printf("\nWelcome to Tic Tac Toe!!!\n\n");
    printf("Player 1 uses 'X'\n");
    printf("Player 2 uses 'O'\n\n");

    bool isPlayer1Turn = true;
    int entry;
    while (true)
    {
        char* currentPlay = isPlayer1Turn ? "Player 1" : "Player 2";
        char input = isPlayer1Turn ? 'X' : 'O';
        printf("%s's turn: ", currentPlay);
        scanf("%d", &entry);

        if (row[entry - 1] != '-')
        {
            printf("Already some entry exists. Try a different spot!!\n");
            continue;
        }
        else
        {
            row[entry - 1] = input;
        }

        printBoard(row, rowLength);
        isPlayer1Turn = !isPlayer1Turn;
    }

    return 0;
}
