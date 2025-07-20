//arr=[4,5,2,10,8]
//ans=[-1,4,-1,2,2]
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>fn(vector<int> & arr){
 int n=arr.size();
vector <int> ans(n,-1);
stack <int> s;

for(int i=0;i<n;i++){
    while(!s.empty() && arr[i] <=s.top()) s.pop();//jab tak mujhe us se chota nhi milta 
    if(s.empty())  ans[i]=-1;
    else ans[i]=s.top();
    s.push(arr[i]);
}
return ans;
}
int main(){
    vector<int> arr={4,5,2,10,8};
    vector<int> ans=fn(arr);
    for(int x: ans) cout<<x<<endl;

}