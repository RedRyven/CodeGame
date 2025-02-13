#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    // game loop
    while (1) {
        int maxHeight = -1;
        int targetIndex = 0;

        for (int i = 0; i < 8; i++) {
            // represents the height of one mountain.
            int mountain_h;
            scanf("%d", &mountain_h);

            if (mountain_h > maxHeight){
                maxHeight = mountain_h;
                targetIndex = i;
            }

        }
        printf("%d\n", targetIndex);
        fflush(stdout);
    }

    return 0;
}