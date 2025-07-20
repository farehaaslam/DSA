#include<iostream>
using namespace std;
class stack{
    private:
    int top;
    int capacity;
    int* arr;
    public:
    stack(int size){
        capacity=size;
        arr=new int[capacity];
        top=-1;
    }
    
    bool isEmpty(){
        if(top==-1) return true;
        return false;
    }
    bool isFull(){
        if(top==capacity-1) return true;
        return false;
    }
    void push(int val){
        if(isFull()){
            cout<<"stack is full"<<endl;
            return;
        }
        arr[++top]=val;
        // cout<<"pushed"<<val;
    }
    void pop(){
        if(isEmpty()){
            cout<<"stack is already empty"<<endl;
            return ;
        }
        cout<<"poped "<<arr[top];
        top--;
    }
    void topelement(){
        if(isEmpty()){
            cout<<"stack is already empty"<<endl;
            return ;
        }
        cout<<"top element is" <<arr[top]<<endl;
    }
    void size(){
        cout<<top+1<<endl;
    }
};
int main(){
    stack s (5);
    s.push(6);
    s.push(9);
    s.push(0);
    s.push(2);
    // s.size();
    s.pop();
    s.size();

}
