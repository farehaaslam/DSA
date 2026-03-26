#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fn(int i ,int j,vector<int>&a,vector<int>&b){
    if(i<0|| j<0) return 0;
    if(a[i]==b[j]){
      return 1+fn(i-1,j-1,a,b);
    }
    return max(fn(i-1,j,a,b),fn(i,j-1,a,b));

}
int main() {
    int n,m;

    cin>>n>>m;
    vector<int>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<int>b;
    for(int i=0;i<m;i++){
        int y;
        cin>>y;
        b.push_back(y);
    }
    cout<<fn(n-1,m-1,a,b);


    return 0;
}    