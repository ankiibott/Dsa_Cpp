//recursive pre-order traversal 

#include<stdio.h>
#include<iostream>
using namespace std;

void Preorder(Node* t){
    if(t!=NULL){ //its having a node
        printf("%d",t->data); //visit(node)
        Preorder(t->lchild); // checks for lchild
        Preorder(t->rchild); // checks for rchild
    } 
}


//iterative pre-order traversal 

void Preorder(Node *t)
{
    struct stack st;
    
    while(t != NULL || !isEmpty(st))
    {
        if(t != NULL)
        {
            printf("%d ", t->data);
            push(&st, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&st);
            t = t->rchild;
        }
    }
}