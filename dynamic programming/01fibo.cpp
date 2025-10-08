#include<iostream>
#include<vector>
using namespace std;
int fiboMemo(int n ,vector<int> &dp){ //up to down
    if (n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n]=fiboMemo(n-1,dp)+fiboMemo(n-2,dp);
    return dp[n];
}
int fiboTabulation(int n,vector<int> &dp){  //down to up 
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];

    }
    return dp[n];

}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    vector<int> dp(n+1,-1);
   // cout<<fiboMemo(n ,dp)<<endl;
   cout<<fiboTabulation(n,dp);
}








