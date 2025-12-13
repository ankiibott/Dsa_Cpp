#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor 
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this->data;
        if(this->next!= NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory Free"<<value<<endl;
    }
};

void InsertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtAnyPos(Node* &head,int position , int d){
    //traversing 
    //intialising temp as in pointing on head 

    Node* temp = head;
    int count = 1;
    while(count<position-1){
        temp= temp->next;
        count++;
    }

    Node* NodeToInsert= new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;

}
void delete(int position, Node* &head){
    //delete first position
    if(position==1){
        Node* temp = head;
        head=head->next;
        //memory free
        temp->next = NULL;
        delete temp;
    }else{
        //at any positon
        Node* curr= head;
        Node* prev= NULL;
        int count=1;

        while(count<position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        //memory free
        curr->next = NULL;
        delete curr;

    }
}


void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    InsertAtHead(head,5);
    print(head);

    InsertAtTail(tail,15);
    print(head);


    return 0;

}