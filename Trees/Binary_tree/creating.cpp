//creating a Binary Tree
#include<stdio.h>
#include<iostream>
using namespace std;

class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Tree
{
public:
    Node *root;
    Tree(){root=NULL;}
    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    void Height(Node *root);
};

class Queue{
    private:
    int front;
    int rear;
    int size;
    Node **Q; // as we are storing the node so Q as node , ** means as already in queue its a pointer so in node again * 

    public:
    //constructor
    Queue(){front=rear=1;size=10;Q=new Node*[size];}
    Queue(int size){front=rear=1;this->size=size;Q= new Node*[this->size];}
    void enqueue(Node* x);
    Node *dequeue();
    void Display();
};

void Queue::enqueue (Node *x){
    if(rear=size-1){
        printf("Queue full\n");
    }
    else{
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue(){
    Node* x =NULL;
    if(front==rear){
        print("Queue is Empty\n");
    }
    else{
        x = Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display(){
    for(int i = front+1;i<=read;i++){
        printf("%d",Q[i]);
    }
    printf("\n"); 
}

