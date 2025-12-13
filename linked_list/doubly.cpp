#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL:
        this->prev = NULL;


    }
};

void insertAtHead(Node* &head,Node* &tail,int d){
    //empty list
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        //not empty list
        Node* temp = new Node(d);  // first create a new node
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int d){
    //empty list
    if(tail==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        //create a new node
        Node* temp = new Node(d);

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtAnyPos(Node* &head,Node* &tail,int position,int d){
    //at 1st positon :-head
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return;
    }
    int count = 1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    Node* NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert;
    temp->next = NodeToInsert;
    NodeToInsert->prev= temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    insertAtHead(head,tail,5);
    print(head);
}