#include<iostream>
using namespace std;
class maxheap{
    public:
    int arr[100];
    int size;
    maxheap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size++;
        arr[size]=val;
        int i=size;
        while(i>1){
            int parent=i/2;
            if(arr[parent]<arr[i]) {
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else{
                break;
            }

        }
    }
    void deleteroot(){
        if(size==0) {
            cout<<"heap already empty";
            return;
        }
        arr[1]=arr[size];
        size--;
        //take root to  correct position
        int i=1;
        while(i<=size){
            int leftidx=2*i;
            int rightidx=2*i+1;
            int largest=i;
            if(leftidx<=size && arr[leftidx] >arr[largest]){
                largest=leftidx;
            }
             if( rightidx<=size &&  arr[rightidx]>arr[largest]){
                largest=rightidx;
            }
            if(largest !=i){
                swap(arr[i],arr[largest]);
                i=largest;
            }
            else break;
        }

    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    maxheap h;
    h.insert(60);
   h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(55);
    h.print();
    h.insert(70);
    h.print();
    h.deleteroot();
    h.print();
    


}