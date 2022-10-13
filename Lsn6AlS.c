#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10
#define binar int
#define SIZE2 100

int numS= -1;
binar stack[SIZE2];
int outBin(binar data)
{
    while (data!=0)
    {
        if (data%2==0){stack[++numS]=0;}
        if (data%2!=0){stack[++numS]=1;}
        data/=2;
    }
}
void printBin()
{
    for (int i=numS;i>=0;i--)
    {
        printf("%d",stack[i]);
    }
}

typedef struct 
{
    int pr;
    int dat;
} Node;

Node *arr[SIZE];
int head;
int tail;
int items;

void init()
{
    for (int i=0;i<SIZE;++i)
    {
        arr[i]=NULL;
    }
    head=0;
    tail=0;
    items=0;
}
void ins(int pr,int dat)
{
    Node *node=(Node*) malloc(sizeof(Node));
    node->dat=dat;
    node->pr=pr;
    int flag;

    if (items==0)
    {
        arr[tail++]=node;
        items++;
    }
    else if (items==SIZE)
    {
        printf("%s \n","Queue is full");
        return;
    }
    else 
    {
        int i=0;
        int idx=0;
        Node*tmp;
        for (i=head;i<tail;++i)
        {
            idx=i%SIZE;
            if (arr[idx]->pr>pr)
            break;
            else
            idx++;
        }
        flag=idx%SIZE;
        i++;
        while (i<=tail)
        {
            idx=i%SIZE;
            tmp=arr[idx];
            arr[idx]=arr[flag];
            arr[flag]=tmp;
            i++;
        }
        arr[flag]=node;
        items++;
        tail++;
    }
}

Node* rem()
{
    if (items==0){return NULL;}
    else
    {
        int idx=--tail%SIZE;
        Node* tmp=arr[idx];
        arr[idx]=NULL;
        items--;
        return tmp;
    }

}

void printq()
{
    printf("[");
    for (int i=0;i<SIZE;++i)
    {
        if (arr[i]==NULL)
        printf(" [*,*] ");
        else
        printf(" [%d,%d] ",arr[i]->pr,arr[i]->dat);
        printf("]");
    }

}




int main()
{
    init();
    ins(2,11);
    ins(1,22);
    ins(3,33);
    ins(5,44);
    ins(3,55);
    ins(6,66);
    ins(3,77);
    ins(8,88);
    ins(7,99);
    ins(5,100);
    printq();
    printf("\n");
    for(int i=3;i<6;i++)
    { 
       Node* n= rem();
    }
    printq();
    printf("\n");
    ins(6,14);
    printq();
    printf("\n");
    outBin(100);
    printBin();



    return 0;
}