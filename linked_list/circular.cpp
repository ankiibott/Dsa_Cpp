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
        int val = this->data;
        if(this->next!= NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory Free"<val<<endl;
    }
};

void insertNode(Node* &tail,int element, int d){
    //empty list
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //non empty list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

    }
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        // cout << "empty list " << endl;
        return;
    }
    else {
        Node* prev = tail;
        Node* curr = prev->next;
        
        while(curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        //ek node wala case
        if(curr == prev) 
            tail = NULL;
        else if (tail == curr)  // 2 node case
            tail = prev;
            
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* &tail){
    Node* temp = tail;
    //empty list
    if(tail==NULL){
        cout<<"list is empty"<<endl;
    }do{
        cout<<tail->data<<" ";
        tail= tail->next;
    }while(tail! = temp);
    cout<<endl;

}

int main(){

}