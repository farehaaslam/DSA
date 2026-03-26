#include<iostream>
#include<vector>
using namespace std;
long long fn(int n, vector<long long>& dp){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
     long long tot=0;
    for(int i=1;i<=6;i++){
        if(n-i>=0)
       tot+= fn(n-i,dp);
    } 
    return dp[n]=tot;
}
int mod=1e9+7;
int main(){
    long long n;
    cin>>n;
    vector<long long>dp(n+1,0);

    dp[0]=1;
    for(int i=1;i<=n;i++){
        long long tot=0;
        for(int j=6;j>=0;j--){
            if(i>=j){
                tot+=dp[i-j];
                tot%=mod;


            }
        }
        dp[i]=tot;
        
    }
    cout<<dp[n];
    
}
