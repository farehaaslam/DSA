//coin change problem
#include <iostream>
#include <vector>
using namespace std;
int fn(int sum,vector<int>&coin,vector<int>&dp){
 if(sum==0) return 1;
 if(dp[sum]!=-1) return dp[sum];
    int ways=0;
    for(int i=0;i<coin.size();i++){
        if(sum>=coin[i])
        ways+=fn(sum-coin[i],coin,dp);
    }
    return dp[sum]=ways;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    //vector<int>dp(x+1,-1);
    //cout<<fn(x,coins,dp);
    //tabulation
    vector<int>dp(x+1,0);
    dp[0]=1 ; //from bc
    int mod=1e9+7;
    for(int i=1;i<=x;i++){
        long long ways=0;
        for(int j=0;j<n;j++){
            if(i>=coins[j]){
                ways=(ways+dp[i-coins[j]])%mod;

            }
            dp[i]=ways;
        }
    }
    cout<<dp[x];


}