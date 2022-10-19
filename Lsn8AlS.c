#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1==1
#define false 1!=1

typedef int boolean;

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} TreeNode;

TreeNode* treeIns(TreeNode *tr,int data)
{
    TreeNode *newtree;
    newtree= (TreeNode*) malloc(sizeof(TreeNode));
    newtree->key=data;
    newtree->left=NULL;
    newtree->right=NULL;
    TreeNode *current=tr;
    TreeNode *parent=tr;
    
    if (tr==NULL) 
    {tr=newtree;}
    else
    {
        while (current->key != data)
        {
            parent=current;
            if (current->key > data)
            {
                current=current->left; 
                if (current==NULL)
                {
                    parent->left=newtree; 
                    return tr;
                }
            }
            else 
            {
                current=current->right;
                if (current==NULL)
                {
                    parent->right=newtree; 
                    return tr;
                }
            }
        }
    }
    
    return tr;
}

void printtr( TreeNode *root)
{
    if (root)
    {
        printf("%d",root->key);
        if (root->left || root->right)
        {
            printf("(");
            if (root->left)printtr(root->left);
            else printf("NULL");
            printf(",");
            if(root->right) printtr(root->right);
            else printf("NULL");
            printf(")");
        }
    }
}
TreeNode *getSuccessor(TreeNode*node)
{
    TreeNode *current=node->right;
    TreeNode *parent=node;
    TreeNode *s=node;
    while (current !=0)
    {
        parent =s;
        s =current;
        current =current->left;

    }
    if (s !=node->right)
    {
        parent->right = s->right;
        s->right=node->right;
    }
    return s;
}

boolean delete(TreeNode *root,int data)
{
    TreeNode *current=root;
    TreeNode *parent=root;
    boolean isLeftChild=true;
    while (current->key !=data)
    {
        parent=current;
        if (data<current->key)
        {
            current=current->left;
            isLeftChild=true;
        }
        else 
        {
            current=current->right;
            isLeftChild=false;
        }
        if (current==NULL)
        return false;
    }
    if (current->left==NULL && current->right==NULL)
    {
        if (current ==root)
        root=NULL;
        else if (isLeftChild)
        parent->left=NULL;
        else parent->right=NULL;
    }
    else if (current->right==NULL)
    {
        if (isLeftChild)
        parent->left=current->left;
        else parent->right=current->left;
    }
    else if (current->left==NULL)
    {
        if (isLeftChild)
        parent->left=current->right;
        else parent->right=current->right;
    }
    else 
    {
        TreeNode *successor=getSuccessor(current);
        if (current==root) root =successor;
        else if (isLeftChild)
        parent->left=successor;
        else parent->right=successor;
        successor->left=current->left;        
    }
    return true;

}


int main ()
{
    TreeNode *tree=treeIns(tree,10);
    treeIns(tree,2);
    treeIns(tree,7);
    treeIns(tree,3);
    treeIns(tree,11);
    treeIns(tree,19);
    treeIns(tree,6);
    
    printtr(tree);
    delete(tree, 11);
    printf("\n");
    printtr(tree);
    return 0;
}