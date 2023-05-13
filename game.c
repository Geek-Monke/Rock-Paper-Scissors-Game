#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateRandomNumber(int n)
{
    srand((time)NULL);
    return rand() % n;
}
int greater(char c1, char c2)
{
    if (c1 == c2)
        return -1;
    else if ((c1 == 'r') && (c2 == 's'))
        return 1;
    else if ((c2 == 'r') && (c1 == 's'))
        return 0;
    else if ((c1 == 'p') && (c2 == 'r'))
        return 1;
    else if ((c2 == 'p') && (c1 == 'r'))
        return 0;
    else if ((c1 == 's') && (c2 == 'p'))
        return 1;
    else if ((c2 == 's') && (c1 == 'p'))
        return 0;
}
int main()
{
    int i;
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("---------------------------------------\n");
    printf("Welcome to the ROCK-PAPER-SCISSORS Game\n");
    printf("---------------------------------------\n\n");
    printf("------------------- RULES -------------------\n");
    printf("Enter 1 for ROCK, 2 for PAPER, 3 for SCISSORS\n");
    printf("---------------------------------------------\n\n");
    for (i = 0; i < 3; i++)
    {
        // Take user input
        printf("Your turn: \n");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];
        if (playerChar == 'r')
            printf("You choose ROCK\n\n");
        else if (playerChar == 's')
            printf("You choose SCISSORS\n\n");
        else
            printf("You choose PAPER\n\n");

        // Generates computer input
        printf("Computer's turn: \n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        if (compChar == 'r')
            printf("Computer choose ROCK\n\n");
        else if (compChar == 's')
            printf("Computer choose SCISSORS\n\n");
        else
            printf("Computer choose PAPER\n\n");

        // Score decision
        if (greater(compChar, playerChar) == 1)
        {
            compScore += 1;
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore += 1;
            playerScore += 1;
        }
        else
        {
            playerScore += 1;
        }
        printf("You: %d\n", playerScore);
        printf("Computer: %d\n\n", compScore);
    }
    if (playerScore > compScore)
    {
        printf("--------------------\n");
        printf("You Win!! Hurrayyy!!\n");
        printf("--------------------\n");
    }
    else if (compScore > playerScore)
    {

        printf("---------------------------------------\n");
        printf("Computer Wins! Better luck next time :)\n");
        printf("---------------------------------------\n");
    }
    else
    {
        printf("-------------------------------------\n");
        printf("It's a Draw, Nobody wins - Play again\n");
        printf("-------------------------------------\n");
    }
    return 0;
}