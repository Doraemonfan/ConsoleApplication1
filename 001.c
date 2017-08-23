#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 16
char Board[N+1][N+1];
void board_default(void);
void board_print(void);
void input(int c);
int judge(void);

int main(void)
{
    int count = 1;
    int victory;

    printf("甲为●, 乙为○\n");
    board_default();
    board_print();

    while( count <= N * N )
    {
        input(count);
        board_print();
        victory = judge();
        if(victory)
            break;
        count++;
        system("cls");
    }
    if(victory)
        printf("%s胜利！\n", (count % 2 == 0) ? "乙" : "甲");
    else
        printf("平局！\n");

    return 0;
}

int judge(void)
{
    int i, j, k;
    int b;

    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= N; j++)
        {
            if (Board[i][j] != '*')
            {
                if(i <= N-4)
                {
                    b = 1;
                    for(k = 1; k < 5; k++)
                    {
                        if (Board[i+k][j] != Board[i][j])
                        {
                            b = 0;
                            break;
                        }
                    }
                    if(b == 1)
                        return 1;
                }

                if(j <= N-4)
                {
                    b = 1;
                    for(k = 1; k < 5; k++)
                    {
                        if (Board[i][j+k] != Board[i][j])
                        {
                            b = 0;
                            break;
                        }
                    }
                    if(b == 1)
                        return 1;
                }

                if(i <= N-4 && j <= N-4)
                {
                    b = 1;
                    for(k = 1; k < 5; k++)
                    {
                        if (Board[i+k][j+k] != Board[i][j])
                        {
                            b = 0;
                            break;
                        }
                    }
                    if(b == 1)
                        return 1;
                }

                if(i <= N-4 && j >= 5)
                {
                    b = 1;
                    for(k = 1; k < 5; k++)
                    {
                        if (Board[i-k][j+k] != Board[i][j])
                        {
                            b = 0;
                            break;
                        }
                    }
                    if(b == 1)
                        return 1;
                }
            }
        }
    }
    return 0;
}

void input(int c)
{
    int col, row;

    srand((unsigned)time(NULL));
    printf("%s落子:",(c % 2 == 0)? "乙" : "甲");
    while(1)
    {
        row = rand() % N + 1;
        col = rand() % N + 1;
        printf("%d %d\n", row, col);
        //scanf("%d %d", &row, &col);
        if(Board[row][col] != '*')
            printf("该处已有棋子！请重新落子：");
        else
            break;
    }
    Board[row][col] = (c % 2 == 0)? '$' : '#';
}

void board_default(void)
{
	int i, j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            Board[i][j] = '*';
}

void board_print(void)
{
	int i, j;

	printf("\n%2c", ' ');
	for(i = 1; i <= N; i++)
        printf("%4d", i);
    printf("\n\n");
    for(i = 1; i <= N; i++)
    {
        printf("%2d  ", i);
        for(j = 1; j <= N; j++)
        {
            if(Board[i][j] == '#')
                printf("%s", "●");
            else if(Board[i][j] == '$')
                printf("%s", "○");
            else
                printf("%s", "┼");
            if(j < N)
                printf("─");
        }
        printf("\n  ");
        if(i < N)
        {
            for(j = 1; j <= N; j++)
                printf("%4s", "│");
        }
        printf("\n");
    }
}


