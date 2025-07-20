// next greatest element

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>fn(vector<int> & arr){
 int n=arr.size();
vector <int> ans(n,-1);
stack <int> s;

for(int i=n-1;i>=0;i--){
while(!s.empty() && s.top()<=arr[i]){
  s.pop();  
}
if(s.empty()) ans[i]=-1;
else ans[i]=s.top();
s.push(arr[i]);
}
return ans;
}
int main(){
    vector<int> arr={6,0,8,1,3};
    vector<int> ans=fn(arr);
    for(int x: ans) cout<<x<<endl;

}