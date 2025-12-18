
#include<iostream>
#include<stdio.h>
using namespace std;

//itervative approach 



void Inorder(Node *t) {
    struct stack st; 
    long int temp; // Used to store the address of the node
    
    // The loop runs as long as there is a node to visit 
    // OR there are nodes saved in the stack to go back to.
    while (t != NULL || !isEmpty(st)) {
        
        if (t != NULL) {
            /* 1. DISCOVERY PHASE (Going Left) */
            // Before moving left, we save the current node (Root) 
            // on the stack so we can come back to it later.
            push(&st, t);
            t = t->lchild; 
        } 
        else {
            /* 2. RETRIEVAL PHASE (Backtracking) */
            // If t is NULL, we've hit the bottom of a left branch.
            // We pop the last saved node from the stack.
            temp = pop(&st);

            if (temp > 0) {
                // In a standard Inorder, we would print the node here.
                // Your code uses a 'temp > 0' check, likely to handle 
                // a specific state or to prevent re-processing.
                
                // 3. MOVE RIGHT
                // After "visiting" the node, we switch to the right child.
                t = ((Node *)temp)->rchild;
            }
        }
    }
}