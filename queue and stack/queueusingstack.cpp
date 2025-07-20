#include<iostream>
using namespace std;
#include<stack>
class Queue{
    stack <int> s1;
    stack <int> s2;
    public:
    void push(int val){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        if (s1.empty()){
            cout<<"queue is empty";
            return;
        }
        s1.pop();
    }
    void peek(){
        if (s1.empty()){
            cout<<"queue is empty";
            return;
        }
        s1.top();
    }
    void size(){
        cout<<s1.size();
    }
    void print(){
        if (s1.empty()){
            cout<<"queue is empty";
            return;
        }
        while(!s1.empty()){
            cout<<s1.top()<<endl;
            s1.pop();
        }
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(8);
    q.pop();
q.size();
    // q.print();

}