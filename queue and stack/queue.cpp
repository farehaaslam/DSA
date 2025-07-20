#include <iostream>
using namespace std;
class Queue{
    private:
    int front;
    int rear;
    int *arr;
    int capacity;
    public:
    Queue(int size){
        capacity=size;
        arr=new int[capacity];
        front=-1;
        rear=-1;
    }
    bool isEmpty(){
        return front==-1 && rear==-1;   
    }
    bool isFull(){
        return (rear+1)%capacity==front;
    }
    void enque(int val){
        if(isFull()) {
            cout<<"queue is full";
            return ;
        }
        if(isEmpty()){
            front=rear=0;  
        }
        else{
            rear=(rear+1)%capacity;
        }
        arr[rear]=val;
    }
    void  deque(){
        if(isEmpty()){
            cout<<"queue is already empty"<<endl;
            return;
        }
        if(front==rear){
            front=-1;
            rear=-1;
        }
        front=(front+1)%capacity;
    }
    void peek(){
        if(isEmpty()) {
            cout<<"queue is empty";
        }
        cout<<arr[front];

    }
};
int main(){
    
}