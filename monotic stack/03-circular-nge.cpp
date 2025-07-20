// Input: nums = [1,2,1]
// Output: [2,-1,2]
// circular array

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>fn(vector<int> & arr){
 int n=arr.size();
vector <int> ans(n,-1);
stack <int> s;

for(int i=2*n-1;i>=0;i--){
while(!s.empty() && s.top()<=arr[i%n]){
  s.pop();  
}
if(i<n){
    if(s.empty()) ans[i]=-1;
else ans[i]=s.top();

}

s.push(arr[i%n]);
}
return ans;
}
int main(){
    vector<int> arr={1,2,3,4,3};
    vector<int> ans=fn(arr);
    for(int x: ans) cout<<x<<endl;

}
