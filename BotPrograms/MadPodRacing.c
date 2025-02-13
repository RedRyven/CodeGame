#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/*
Game Bounds are 16000u x 9000u
CheckPoints are 1200u Diameter
Pods are 800u diameter

Program takes the following variables into consideration
* checkDist
* checkAngle
* checkX
* checkY

Command "BOOST" can be used one time during gameplay

Situations taken into consideration
* Turn times due to excessive speed
* checkAngle is measured from -180 to 180, not 0-360

*/

int main()
{
    int BOOST = 1;
    int turn = 0;


    while (1) {

        int moveX, moveY, moveSpeed;

        //// GAME CODE ////
        int x;
        int y;
        // x position of the next check point
        int checkX;
        // y position of the next check point
        int checkY;
        // distance to the next checkpoint
        int checkDist;
        // angle between your pod orientation and the direction of the next checkpoint
        int checkAngle;
        scanf("%d%d%d%d%d%d", &x, &y, &checkX, &checkY, &checkDist, &checkAngle);
        int opponent_x;
        int opponent_y;
        scanf("%d%d", &opponent_x, &opponent_y);

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"

        //// END GAME CODE ////

        // Setting speed settings on straights

        if (checkDist < 1200){
            moveX = (moveX + checkX) / 2;
            moveY = (moveY + checkY) / 2;
            moveSpeed = 50;
        }
        else{
            moveX = (moveX + checkX) / 2;
            moveY = (moveY + checkY) / 2;
            moveSpeed = 100;
        }

        // Setting speed settings on turns

        if (abs(checkAngle > 90)){
            moveX = (moveX + checkX) / 2;
            moveY = (moveY + checkY) / 2;
            moveSpeed = 30;
        }
        else if (abs(checkAngle > 45)){
            moveX = (moveX + checkX) / 2;
            moveY = (moveY + checkY) / 2;
            moveSpeed = 60;
        }
        
        // Checking if BOOST is available and good to be used

        if ((BOOST > 0 && checkDist > 5000) && abs(checkAngle < 15)){
            printf("%d %d BOOST\n", checkX, checkY);
            BOOST--;
        }

        // Actual movement
        printf("%d %d %d\n", moveX, moveY, moveSpeed);
        
    }

    return 0;