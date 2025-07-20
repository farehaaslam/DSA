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
    int arr[6]={-1,54,55,9,52,50};
    int n=6;
    for(int i=n/2;i>0;i--){
        heapify(arr,i,n);
    }
    for(int x :arr){
        cout<<x<<" ";
    }

}
