#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greater(char charc1, char charc2)
{
    // return 1 if c1>c2  and -1 if c1=c2 and 0 if c2>c1
    if (charc1 == charc2)
    {
        return -1;
    }
    else if ((charc1 == 'r') && (charc2 == 's'))
    {
        return 1;
    }
    else if ((charc1 == 's') && (charc2 == 'r'))
    {
        return 0;
    }
    else if ((charc1 == 's') && (charc2 == 'p'))
    {
        return 1;
    }
    else if ((charc1 == 'p') && (charc2 == 's'))
    {
        return 0;
    }
    else if ((charc1 == 'r') && (charc2 == 'p'))
    {
        return 0;
    }
    else if ((charc1 == 'p') && (charc2 == 'r'))
    {
        return 1;
    }
    return 0;
    
}
int main()
{
    int playerscore = 0, compscore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("welcome to the rock paper sicssors");

    for (int i = 0; i < 3; i++)
    {
        printf("player 1's turn:\n");
        printf("choose 1 for rock 2 for paper and 3 for scissor\n");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];
        printf("you chose %c:\n",playerChar);

        printf("Computer's  turn:\n");
        
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf("CPU chose %c:\n", compChar);

        if (greater(compChar, playerChar) == 1)
        {
            compscore += 1;
            printf("CPU got it!!\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compscore += 1;
            playerscore += 1;
            printf("its a draw!!\n");
        }
        else
        {
            playerscore += 1;
            printf("you got it!!\n");
        }
        printf("YOU:%d\n CPU : %d\n", playerscore, compscore);
    }
    if (playerscore > compscore)
    {
        printf("you won!");
    }
    else if (compscore > playerscore)
    {
        printf("CPU won!");
    }
    else
    {
        printf("its a draw!");
    }
    
}