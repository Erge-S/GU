#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1==1
#define false 1 !=1
typedef int boolean;


typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;
typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;
void initOneLinkList(OneLinkList *lst) {
    lst->head = NULL;
    lst->size = 0;
}
char popOneLinkStack(OneLinkList *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    char data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}
boolean pushOneLinkStack(OneLinkList *stack, char value) {
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}
//проверка скобок
int checkBrack(char *str)
{
    int type =3;
    char examp [][2]={{'(',')'},{'{','}'},{'[',']'}};
    OneLinkList *st= (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(st);
    int index =0;
    while(*str !='\n')
    {
        for (int i=0;i<type;++i)
        {
            if (*str==examp[i][0])
            pushOneLinkStack(st,i);
            
        }
        for(int i=0;i<type;++i)
        {
            if (*str==examp[i][1])
            {
                if (st->size==0)return index;
                if (i==st->head->dat)popOneLinkStack(st);
                else return index;
            }
        }
        str++;
        index++;
    }
    if (st->size !=0)
    return st->head->dat;
    return -1;

}
//копирование структур
struct Node {
    int data;
    struct Node* next;
};
struct Node* copyList(struct Node* head)
{
    if (head == NULL) {
        return NULL;
    }
    else 
    {
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
        newNode->data = head->data;
        newNode->next = copyList(head->next);
        return newNode;
    }
}
//сортировка по возратанию
struct list
{
    int data;
    struct list *next;
};
struct list * sort( struct list *root )
{
    struct list *new_root = NULL;

    while ( root != NULL )
    {
        struct list *node = root;
        root = root->next;

        if ( new_root == NULL || node->data < new_root->data )
        {
            node->next = new_root;
            new_root = node;
        }
        else
        {
            struct list *current = new_root;
            while ( current->next != NULL && !( node->data < current->next->data ) )
            {                   
                  current = current->next;
            }                

            node->next = current->next;
            current->next = node;
        }
    }

    return new_root;
}
int main()
{
    
    return 0;
}