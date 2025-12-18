
#include<iostream>
#include<stdio.h>
using namespace std;

//itervative approach 



void Postorder(Node *t) {
    struct stack st; // A stack to store node addresses
    long int temp;   // Variable to store popped values (as addresses)

    // The loop continues if we have a node to visit OR if the stack is not empty
    while (t != NULL || !isEmpty(st)) {
        
        if (t != NULL) {
            /* 1. GO LEFT PHASE */
            // Push current node address to stack and move to the left child.
            // In VS Code/C++, we cast the pointer to long int to store it.
            push(&st, (long int)t);
            t = t->lchild;
        } 
        else {
            /* 2. BACKTRACKING PHASE */
            // If we hit NULL, we pop the last node from the stack.
            temp = pop(&st);

            if (temp > 0) {
                /* 3. FIRST TIME POPPING (FROM LEFT) */
                // The value is positive, meaning we just finished the left subtree.
                // We push it back as a NEGATIVE value to flag it.
                push(&st, -temp);
                
                // Now, move to the right child to process that subtree.
                t = ((Node *)temp)->rchild;
            } 
            else {
                /* 4. SECOND TIME POPPING (FROM RIGHT) */
                // The value is negative, meaning we just finished the right subtree.
                // Now it's finally time to "visit" the root node.
                
                // Print the data by converting the negative address back to a pointer.
                printf("%d ", ((Node *)(-temp))->data);
                
                // Set t to NULL so that on the next loop, we pop the parent from the stack.
                t = NULL;
            }
        }
    }
}