#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fn(int i ,int sum ,vector<int>&coin,vector<vector<int>>&dp){
    if(sum==0){
        return 1;
    }
    if(i==0){
        return sum%coin[0]==0?1:0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    int take=0;
    int nottake=fn(i-1,sum,coin,dp);
    if(coin[i]<=sum){
        take=fn(i,sum-coin[i],coin,dp);
    }
    return dp[i][sum]=(take+nottake);
}
int main(){
      int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int>coin;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        coin.push_back(num);
    }
    // vector<vector<int>>dp(n,vector<int>(x+1,-1));
    // cout<<fn(n-1,x,coin,dp)<<endl;
 int mod=1e9+7;
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
   }
   for(int j=0;j<=x;j++){
    dp[0][j]= j%coin[0]==0?1:0;
   }
   for(int i=1;i<n;i++){
    for(int j=0;j<=x;j++){
        int take=0;
        if(j>=coin[i])take=dp[i][j-coin[i]];
        int nottake=dp[i-1][j];
         dp[i][j]=( take+nottake )%mod;
    }
   }
    cout<<dp[n-1][x]<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=x;j++){
    //         cout<<dp[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }
}
