#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort (int * arr,int row,int col)
{
    for(int z=0;z<9;z++){
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            if ((*(arr+i*col+j))<((*(arr+i*col+j-1))))
            {swap(((arr+i*col+j)),((arr+i*col+j-1)));}
        }
    }
    }
}
int InversePratt(int *array,int len)
{
    for (int i=0;i<len-1;i++)
    {
        if(array[i]<array[i+1])
        swap(&array[i],&array[i+1]);
    }
}
int printArr(int*arr,const int row,const int col)
{
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            printf("%3d",(*(arr+i*col+j)));
        }
        printf("\n");
    }
}
void swap(int *a,int*b)
{
    int sw=*a;
    *a=*b;
    *b=sw;
}

double  Pratt(double  t)
{
    return  sqrt(fabs(t)) + 5 * pow(t, 3);
}

int main ()
{
    const int col=3;
    const int row=3;
    int mass [3][3]=
    {{1,9,2},
    {5,7,6}, 
    {4,3,8}};
    

    printArr(mass,row,col);
    printf("\n");
    sort(mass,row,col);
    printArr(mass,row,col);
    printf("\n");
    printf("Input eleven numbers");
    double a[11]={},y;
    for (int  i = 0; i < 11; i++)
        scanf("%lf", &a[i]);
    InversePratt(a,11);

    for (int  i = 10; i >= 0; i--) {
        y = Pratt(a[i]);
        if (y > 400)
            printf("number #%d bigger than 400 \n", i);
        else
             printf("number #%d is %.3g \n", i, y);
    }
    
    
    return 0;
}