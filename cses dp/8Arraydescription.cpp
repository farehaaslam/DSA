#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mod=1e9+7;

int fn(int i,int prev,int m,vector<int> & arr,vector<vector<long long>> & dp){
    if(i==-1) return 1;
    if(dp[i][prev]!=-1) return dp[i][prev];
    if(arr[i]!=0){
        if(arr[i]==prev || arr[i]==prev+1 || arr[i]==prev-1  )
        return dp[i][prev]=fn(i-1,arr[i],m,arr,dp);
        return dp[i][prev]=0;

    }
    else{
        int ways=0;
        for(int k=-1;k<=1;k++){
            if(prev+k>0 && prev+k<=m){
                ways=(ways+fn(i-1,prev+k,m,arr,dp)%mod);
            }
        }
        return dp[i][prev]=ways;
    }

}
int  main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<vector<long long>>dp(n,vector<long long>(m+1,-1));
    if(arr[n-1]==0){
        long long ans=0;
        for(int i=1;i<=m;i++){
            ans=(ans+fn(n-2,i,m,arr,dp)%mod);
           // dp[n-2][i]=ans;
        }
        cout<<ans%mod;
        return 0;
    }
    else {
        fn(n-2,arr[n-1],m,arr,dp); 
        cout<<dp[n-2][arr[n-1]]%mod;
    }

    //tabulation


}