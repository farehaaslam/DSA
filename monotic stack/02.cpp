// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>fn(vector<int> & arr1,vector<int> & arr2){
 int m=arr1.size();
 int n=arr2.size();
vector <int> ans(m,-1);


for(int i=0;i<m;i++){
    stack <int> s;
    for(int j=n-1;j>=0;j--){
        if(arr1[i]==arr2[j]){
            if(s.empty()) ans[i]=-1;
            else ans[i]=s.top();
            break;
        }
        if(arr1[i]<arr2[j]) s.push(arr2[j]);
    }
}
return ans;
}
int main(){
    vector<int> arr1={4,1,2};
    vector<int> arr2={1,3,4,2};
    vector<int> ans=fn(arr1,arr2);
    for(int x: ans) cout<<x<<endl;

}