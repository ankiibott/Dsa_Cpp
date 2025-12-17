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