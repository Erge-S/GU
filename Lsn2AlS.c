#include <stdio.h>


int main() {
    int a, k;
    k = 0;
    printf (" Enter integer number\n");
    scanf( "%d", &a );
    if ((a == 1) || (a == 0)|| (a<0))
    {
        printf ("Incorrect input\n"); return 0;
    }
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            k++;
        }
    }
    if (k > 2)
    {
        printf ("Number is not simple\n");
    }
    if (k <= 2)
    {
        printf ("Number is simple!!!\n");
    }
    return 0;
}