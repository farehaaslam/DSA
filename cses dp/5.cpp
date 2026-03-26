#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fn(int n,vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1 || n<=9) return dp [n];
    int num=n;
    int mini=1e9;
    
    while (num>0)
    { 
        int digit=num%10;
        if(digit==0){
            num/=10;
            continue;
        }
        num/=10;
        mini=min(mini,fn(n-digit,dp));
    }
    return dp[num]=mini+1;
    
}
int main(){
    int n;
    cin>>n;
      if (n<=9){
        cout<<1<<endl;
        return 0;
    }
    vector<int>dp(n+1,-1);
    for(int i=0;i<=9;i++){
        dp[i]=1;
    }
    //cout<<fn(n,dp)<<endl;
  
    for(int i=10;i<=n;i++){
        int num=i;
        int mini=1e9;
        while(num>0){
            int digit=num%10;
            if(digit==0){
                num/=10;
                continue;
            }
            num/=10;
            mini=min(mini,dp[i-digit]);
        }
        dp[i]=mini+1;
    }
    cout<<dp[n]<<endl;


}