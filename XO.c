#include <stdio.h>

typedef struct Pos
{
    char x;
    char y;
} pos;

void show(char feild[][3], size_t axis)
{
    for (size_t y = 0; y < axis; y++)
    {
        for (size_t x = 0; x < axis; x++)
        {
            printf("%c", feild[y][x]);
        }
        printf("\n");
    }
}

void mark(char map[][3], char player)
{
    pos point;
    while (1)
    {
        printf("%c's turn: enter: x y \n", player);
        scanf("%d %d", &point.x, &point.y);

        if ((point.x < 3 && point.y < 3) && map[point.y][point.x] == '#')
        {
            map[point.y][point.x] = player;
            break;
        }
        else
        {
            printf("sorry mate try again : ");
        }
    }
}

char check(char map[][3])
{
    char flag = 0;
    int sum_rows= 0 ;
    int sum_cols = 0;
    int sum_mdiag = 0;
    int sum_sdiag = 0;
    for(int i = 0 ; i < 3 ; i++)
    {
        sum_rows= 0 ;
        sum_cols = 0;
        for(int j = 0 ; j < 3 ;j++)
        {
            sum_rows += map[i][j];
            sum_cols += map[j][i];
        }
        if(sum_rows == 'x' * 3 || sum_cols == 'x' * 3)
        {
            return 'x';
        }
        if(sum_rows == 'o' * 3 || sum_cols == 'o' * 3)
        {
            return 'o';
        }
    }
    for(int d = 0 ; d < 3; d++)
    {
        sum_mdiag += map[d][d];
        sum_sdiag += map[d][2-d];
    }

    if(sum_mdiag == 'x' * 3 || sum_sdiag == 'x' * 3)
    {
        return 'x';
    }
    if(sum_mdiag == 'o' * 3 || sum_sdiag == 'o' * 3)
    {
        return 'o';
    }
    return 0;
}

int main()
{
    char map[3][3] = {"###",
                      "###",
                      "###"};
    char players[2] = {'x', 'o'};
    
    char winner= 0; 
    show(map, 3);
    for (char i = 0; i < 9 ; i++)
    {
        mark(map, players[i % 2]);
        show(map, 3);
        if(winner = check(map))
        {
            break;
        }
    }
    printf("and the winner isssssss  %c", winner);

}