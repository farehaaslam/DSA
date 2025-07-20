#include<iostream>
using namespace std;
#include <queue>
class Stack{
    queue <int> q;
    public:
void push(int val){
   int size=q.size();
   q.push(val);
   for(int i=1;i<size;i++){
    q.push(q.front());
    q.pop();
   }
}
void pop(){
    if(q.empty()){
        cout<<"stack is already empty";
        return;
    }
    q.pop();
}
void top(){
     if(q.empty()){
        cout<<"stack is  empty";
        return;
    }
    cout<<q.front()<<endl;

}
void size(){
    cout<<q.size();
}
};
int main(){
    Stack s;
    s.push(8);
}
