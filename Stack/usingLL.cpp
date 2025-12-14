#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

class Stack{
    node* head;
    int size;

    stack(){
        head=NULL;
        size=0;
    }

    void push(int data){
        node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    int pop(){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int t = head->data; // to store the top elt as that will be popped so that we can return the value
        node* a = head; // stored the first node in a separate new node and then delete the newNode (a)
        head = head->next;
        delete a;
        return t;
    }

    bool isEmpty(){
        return (size==0);
    }

    int getSize(){
        return size;
    }

    int top(){
        if(isEmpty()){
            return -1;
        }
        return head->data;
    }

};

int main(){
    
}