#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int GuessChecker(int x, int y)
{
    if (x == y)
    {
        return 1;
    }

    else
        return 0;
}

void GuessComp(int x, int y)
{
    if (x > y)
    {
        printf("Too low!\n");
    }

    else if (x < y)
    {
        printf("Too high!\n");
    }
}

void GuessMyNumber(void)
{
    srand(time(NULL));
    int x, y, counter = 0;

    x = rand() % 100 + 1;

    printf("Guess My Number Game\n");

    while (GuessChecker(x, y) == 0)
    {
        printf("Enter a guess between 1 and 100: ");
        scanf("%d", &y);

        GuessComp(x, y);
        counter++;
    }

    printf("\nCorrect! You got it in %d guesses!\n\n", counter);
}

int Score(int x, int y)
{
    int point;

    if (x == y)
    {
        point = x;
        return x;
    }

    else
        return 0;
}

void Tetris(void)
{
    srand(time(NULL));
    int x, limit = 0, point = 0, color = 0;

    while (limit < 30)
    {
        x = rand() % 4 + 1;

        switch (x)
        {
        case 1 /*green*/:

            printf("brick 1:#Color of the brick is green\n");

            break;

        case 2 /*yellow*/:

            printf("brick 1:#Color of the brick is yellow\n");

            break;

        case 3 /*blue*/:

            printf("brick 1:#Color of the brick is blue\n");

            break;

        case 4 /*red*/:

            printf("brick 1:#Color of the brick is red\n");

            break;
        }

        limit++;
        point += Score(x, color);

        if (color == x)
        {
            limit -= 2;
        }

        printf("Current Points: %d, Limit: %d\n\n", point, limit);

        while (color == x)
        {
            x = rand() % 4 + 1;

            switch (x)
            {
            case 1 /*green*/:

                printf("brick 1:#Color of the brick is green\n");

                break;

            case 2 /*yellow*/:

                printf("brick 1:#Color of the brick is yellow\n");

                break;

            case 3 /*blue*/:

                printf("brick 1:#Color of the brick is blue\n");

                break;

            case 4 /*red*/:

                printf("brick 1:#Color of the brick is red\n");

                break;
            }

            limit++;
            color = x;

            x = rand() % 4 + 1;

            switch (x)
            {
            case 1 /*green*/:

                printf("brick 2:#Color of the brick is green\n");

                break;

            case 2 /*yellow*/:

                printf("brick 2:#Color of the brick is yellow\n");

                break;

            case 3 /*blue*/:

                printf("brick 2:#Color of the brick is blue\n");

                break;

            case 4 /*red*/:

                printf("brick 2:#Color of the brick is red\n");

                break;
            }

            point += Score(x, color);
            limit++;

            if (color == x)
            {
                limit -= 2;
            }

            printf("Current Points: %d, Limit: %d\n\n", point, limit);
        }
        color = x;
    }
}

void MazeSolver(void)
{
    int x, Start = 1, End = 0, i, j, counter = 1;

    printf("Enter row number: ");
    scanf("%d", &x);

    while (Start >= End)
    {
        Start = rand() % (int)pow(x, 2) + 1;
        End = rand() % (int)pow(x, 2) + 1;
    }

    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= x; j++)
        {
            if (counter == Start)
            {
                printf("S");
                counter++;
            }

            else if (counter == End)
            {
                printf("E");
                counter++;
            }

            else
            {
                printf(".");
                counter++;
            }
        }

        printf("\n");
    }

    printf("number of dots between S end E from left to right is %d\n\n", End - Start - 1);
}

void Menu(void)
{
    int x;

    while (1)
    {
        printf("-------------Welcome to the Game Arena-------------\n");
        printf("1. Guess My Number Game\n2. Tetris Game\n3. Maze Solver\n4. Quit\n");
        scanf("%d", &x);

        if (x == 4)
        {
            break;
        }

        else
        {
            switch (x)
            {
            case 1:
                GuessMyNumber();
                break;

            case 2:
                Tetris();
                break;

            case 3:
                MazeSolver();
                break;
            }
        }
    }
}

int main(void)
{
    srand(time(NULL));

    Menu();

    return 0;
}