
//iterative approach 
//note :- queue is initialised okay

void Levelorder(Node *p)
{
    Queue q; 

    
    printf("%d ", p->data);
    enqueue(&q, p);

    // Step 2: While the queue is not empty, process nodes
    while (!isEmpty(q))
    {
        // Remove the front node from the queue
        p = dequeue(&q);

        // Step 3: Check and process the left child
        if (p->lchild)
        {
            printf("%d ", p->lchild->data); // Print left child
            enqueue(&q, p->lchild);        // Add left child to queue
        }

        // Step 4: Check and process the right child
        if (p->rchild)
        {
            printf("%d ", p->rchild->data); // Print right child
            enqueue(&q, p->rchild);        // Add right child to queue
        }
    }
}