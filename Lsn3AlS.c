#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int board [5][5]=
{
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

int sqr1 (int a, int b)
{
    if (b==1) return a;
    if (b==0) return 1;
    else
    {
        return a*sqr1(a,b-1);
    }
}

int sqr2(int a, int b)
{   
    if(b==1)return a;
    if (b==0)a=1;
    if (b%2==0)
    {
        return sqr2(a*a,b/2);
    }
    if (b%2!=0)
    {
        return a*sqr2(a,b-1);
    }

}

int bin2(int a)
{
    while(a>0)
    {
    bin2(a/2);
    if (a%2==0) return printf("0");
    if (a%2!=0) return printf("1");
    }

}


int king (int x,int y,int *board[x][y])
{
    if(board[x][y]!=0)return 0;
    if (x==0 && y==0)
    {
        return 0;
    }
    if (x==0^y==0)
    {
        return 1;
    }
    
    else return king (x,y-1,board)+king (x-1,y,board);
}


int main () 
{
    
    printf("%d",sqr1(2,4));
    printf("\n");
    printf("%d",sqr2(2,7));
    printf("\n");
    bin2(100);
    printf("\n\n");
    const int x=5;
    const int y=5;
    
    
    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x)
            printf("%5d", king(3,3,board));
        printf("\n");
    }

    return 0;
}