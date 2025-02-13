#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
For this game, we use Binary Search Algorithm to find the point due to the mass quantity of options in the game.
Research Website for Binary Search: https://www.geeksforgeeks.org/binary-search/#
*/

int main()
{
    // GAME CODE //

    int W;
    int H;
    scanf("%d%d", &W, &H);
    int N;
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);

    //  END GAME CODE //

    // Setting Bounds of the Game
    int left = 0, right = W - 1;
    int top = 0, bottom = H - 1;
    int currentX = X0, currentY = Y0;

    // game loop
    while (1) {
        char bomb_dir[4];
        scanf("%s", bomb_dir);

        if (strchr(bomb_dir, 'U')){
            bottom = currentY - 1;
        }
        if (strchr(bomb_dir, 'D')){
            top = currentY + 1;
        }
        if (strchr(bomb_dir, 'L')){
            right = currentX - 1;
        }
        if (strchr(bomb_dir, 'R')){
            left = currentX + 1;
        }

        currentX = (left + right) / 2;
        currentY = (top + bottom) / 2;

        printf("%d %d\n", currentX, currentY);
        fflush(stdout);
    }

    return 0;
}