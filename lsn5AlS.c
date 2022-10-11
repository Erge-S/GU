#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a,int*b)
{
    int sw=*a;
    *a=*b;
    *b=sw;
}

void Shell (int* array,int len)
{
    int i;
    int j;
    int step;
    int temp;
    for (step =len/2;step>0;step /=2)
    {
        for(i=step;i<len;i++)
        {
            temp=array[i];
            for(j=i;j>=step;j-=step)
            {
                if (temp<array[j-step]){
                    array[j]=array[j-step];
                } else{
                    break;
                }
            }
            array[j]=temp;
        }
    }
}
int Hoar(int* array,int first, int last)
{
    int i=first;
    int j=last;
    int x=array[(first+last)/2];

    do
    {
        while (array[i]<x) i++;
        while (array[j]>x) j--;
        if (i<=j)
        {
            swap(&array[i],&array[j]);
            i++;
            j--;
        }
    } while(i<=j);
    if(i<last) Hoar(array,i,last);
    if(first<j) Hoar(array,first,j);

}
void quickSort (int* array,int len,int first,int last)
{
    if (len-1<=10) Shell(array,len-1);
    else
    {
        Hoar(array,0,len-1);
    }
}

int printArray(int* array,int len)
{
    for(int i=0;i<len;i++)
    {
         printf("%d ",array[i]);
         
    }
    return 0;
}


void dell (int* arr, int n)
{
   for (int i = 0; i < n; ++i) 
   {  
        for (int i = 0; i < n; ++i) 
        { if (arr[i] % 2 == 0) 
            { for (int j = 0; j < n - 1; ++j) 
                  { if (arr[j] % 2 == 0) 
                  { if (arr[i] < arr[j]) 
                    { int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp; } } } } } 


}
}


int main ()
{
    const int x=12;
    int arr[12]={0,2,8,3,4,6,5,9,8,2,7,3};
    printArray(arr,x);
    quickSort(arr,x,0,x);
    printf("\n");
    
    dell(arr,x);
    printArray(arr,x);
    printf("\n");
    
    //printArray(arr,x);
    return 0;
}