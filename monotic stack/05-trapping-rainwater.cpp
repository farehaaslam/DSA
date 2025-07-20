//0,1,0,2,1,0,1,3,2,1,2,1
//ans =6

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int fn(vector<int> & arr){
 int n=arr.size();
 vector<int> prefixmax (n,1);
 vector<int> suffixmax(n,1);
 prefixmax[0]=arr[0]; //us aur us se pehle mai sabse max element
 for(int i=1;i<n;i++){
    prefixmax[i]=max(prefixmax[i-1],arr[i]);
 }
 suffixmax[n-1]=arr[n-1]; // wo ya uske baad mai sab se maax element
 for(int i=n-2;i>=0;i--){
    suffixmax[i]=max(suffixmax[i+1],arr[i]);
 }
 int ans=0;
 for(int i=0;i<n;i++){
    if(prefixmax[i]>arr[i] && suffixmax[i]>arr[i])
    ans+=min(suffixmax[i],prefixmax[i])-arr[i];

 }
return ans;
}
int main(){
    vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<fn(arr);
   

}