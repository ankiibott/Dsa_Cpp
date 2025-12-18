//recursive approach 

#include<stdio.h>
#include<iostream>
using namespace std;

void Inorder(Node* t){
    if(t!=NULL){ //its having a node
        Inorder(t->lchild); 
        printf("%d",t->data);
        Inorder(t->rchild); 
    } 
}

//iterative approach 
void Preorder(Node *t)
{
    struct stack st;
    
    while(t != NULL || !isEmpty(st))
    {
        if(t != NULL)
        {
            
            push(&st, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&st);
            printf("%d ", t->data);
            t = t->rchild;
        }
    }
}