#include<iostream>
using namespace std;

class Stack{
    // its private
    int *data;
    int nextIndex;
    int capacity;
    /* the reason to keep this private its because user can not see all the elts,
    can only access/view the top element */

    public:

    //constructor
    stack(int size){
        data = new int[size];
        capacity = size;
        nextIndex = 0;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return (nextIndex==0);
    }

    void push(int ele){
        if(nextIndex==capacity){
            cout<<"Stack is Full"<<endl;
            return;
        }
        data[nextIndex] = ele;
        nextIndex++;
    }

    void pop(){
        if(nextIndex==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        nextIndex--;
        return data[nextIndex];
    }
    
    int top(){
        if(nextIndex==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return data[nextIndex-1];
    }
};

int main() {
    stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    cout<<st.isEmpty()<<endl;

    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;

    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    cout<<st.isEmpty()<<endl;

    return 0;
}