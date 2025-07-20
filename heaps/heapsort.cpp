#include <iostream>
using namespace std;
void heapify(int arr[100],int i,int n){
    int left=2*i;
    int right=2*i+1;
    int largest=i;
    if(left<=n &&  arr[left]>arr[largest]) largest=left;
    if( right<=n && arr[right]>arr[largest]) largest=right;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }
    return;

}
int main(){
    int arr[6]={-1,54,10,9,52,39};
    int n=5;
    //first we create it a heap 
    for(int i=n/2;i>0;i--){
        heapify(arr,i,n);
    }
    for(int x :arr){
        cout<<x<<" ";
    }
    cout<<endl;

    while(n>=1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,1,n);


    }
    for(int x :arr){
        cout<<x<<" ";
    }

}
