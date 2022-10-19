#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1 == 1
#define false 1 != 1
#define T char
typedef int boolean;
const int n=6;
int matrix [6][6]=
{
    {0,1,1,0,0,0},
    {0,0,0,1,1,1},
    {0,0,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,1,0}
};
int visited[6]={0};
typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

void deepTR(int st)
{
    int r;
    printf("%d ",st);
    visited[st]=1;
    for (r=0;r<n;++r)
    {
        if (matrix[st][r]==1 && !visited [r])
        {
            deepTR(r);
        }
    }
}
void resetARR()
{
    for (int i=0;i<n;++i)
    {
        visited[i]=0;
    }
}
void initTwoLinkList(TwoLinkList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}
void clearVis(int* arr,int size)
{
    for (int i=0;i<size;++i)
    {
        arr[i]=0;
    }
}
boolean TwoLinkEnqueue(TwoLinkList *queue, T value) {
    TwoLinkNode *tmp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}
T TwoLinkDequeue(TwoLinkList *queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode *tmp = queue->head;
    T data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}
int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);}
int** init2dIntArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}
void set2dInt(int** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}

int widthTR(int**matrix,int start,const int size)
{
    TwoLinkList*queve=(TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queve);
    int visited[size];
    clearVis(visited,size);
    TwoLinkEnqueue(queve,size);
    while(queve->size>0)
    {
        int index=TwoLinkDequeue(queve);
        if (visited[index]==1) continue;
        visited[index]=1;
        printf("%d",index);
        for (int i=0;i<size;++i)
        {
            if (get2dInt(matrix,index,i)==1 && visited[i]==0)
            TwoLinkEnqueue(queve,i);
        }
    }

}

int main ()
{
    deepTR(0);
    resetARR();
    printf("\n");
    deepTR(2);
    resetARR();
    printf("\n");
    deepTR(1);
    resetARR();
    printf("\n");
    deepTR(4);
    resetARR();
    printf("\n");
    
    const int SZ =6;
    int ** adj= init2dIntArray(adj,SZ,SZ);
    set2dInt(adj,0,1,1);
    set2dInt(adj,0,2,1);
    set2dInt(adj,1,3,1);
    set2dInt(adj,1,4,1);
    set2dInt(adj,1,5,1);
    set2dInt(adj,2,5,1);
    set2dInt(adj,3,0,1);
    set2dInt(adj,5,4,1);
    widthTR(adj,0,SZ);
    printf("\n");
    widthTR(adj,3,SZ);
    printf("\n");
    widthTR(adj,0,SZ);
    printf("\n");

    return 0;
}