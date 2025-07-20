#include <iostream>
using namespace std;
class Node
{ public:
    int data;
    Node *next;


    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    
};
class Stack
{
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }
    bool isEmpty(){
        if(top==nullptr) return true;
        return false;
    }
   //linked list top implemntatuion
    void push(int val){
        Node* newnode=new Node(5);
        newnode->next=top;
        top=newnode;
    }
    void pop(){
        if (isEmpty()) {
            cout<<"stack is empty";
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
    }
    void topelement(){
        if (isEmpty()) {
            cout<<"stack is empty";
            return;
        }
        cout<<top->data<<endl;

    }
    ~Stack(){
        while(isEmpty()){
            pop();
        }
    }

};
int main(){
    
}