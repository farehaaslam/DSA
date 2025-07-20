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
class Queue{
    Node* front ;
    Node* rear;
    public:
    Queue(){
        front=nullptr;
        rear=nullptr;

    }//add at end 
    //remove from begin
    bool isEmpty(){
        return front==nullptr && rear==nullptr;
    }
    void enque(int val){
        Node* newnode=new Node(val);
        if(isEmpty()){
            front=newnode;
            rear=newnode;
            return;
        }
        rear->next=newnode;
        rear=rear->next;  
        return;
    }
    void deque(){
        if(isEmpty()){
            cout<<"already empty"<<endl;
            return;
        }
        if(front==rear){
            delete front;
            front=rear=nullptr;
            return;
        }
        Node* temp=front;
        front=front->next;
        delete temp;
    }


    };