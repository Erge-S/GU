#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;


int  hash(char *S)
{
     int i,r=0;
     while(*S)
     {
         r+=(int)(*S);
         S++;
     }
     return r;
}

int profitCaculation(int* coin, const int n, const int maxN) {
    int arr[n];
 
    clearIntArr(arr, n);
 
    int sum = 0;
    int o = 0;
    for (int i = 0; i < maxN; i++) {
        if ((coin[i]*2) < 98) {
            sum += coin[i];
            o++;
        }
        if (sum < 98) break;
    }
    return o;
}
 
void task2() {
    const int Cmax = 5;
    const int maxN = 98;
    int coin[] = { 50, 10, 5, 2, 1 };
 
    printf("%d", profitCaculation(coin, Cmax, maxN));
}
int main()
{



    return 0;

}