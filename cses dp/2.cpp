#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fn(int i, int sum ,vector<int>& coin,vector<vector<int>>& dp){
    if(sum==0) return 1;
    if(i==0) return sum%coin[0]==0? sum/coin[0]:0;
        if(dp[i][sum]!=-1) return dp[i][sum];

    int take=1e9;
    int nottake=fn(i-1,sum,coin,dp);
    if(coin[i]<=sum){
        take=1+fn(i,sum-coin[i],coin,dp);
    }
    return dp[i][sum]= min(take,nottake);
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
    sort(coin.begin(),coin.end());
    int INF=1e9;

    vector<vector<int>>dp(n,vector<int>(x+1,INF));
   //cout<< fn(n-1,x,coin,dp);
   for(int i=0;i<n;i++){
    dp[i][0]=0;
   }
   for(int i=1;i<=x;i++){
    dp[0][i]=i%coin[0]==0?i/coin[0]:INF;
   }
   for(int i=1;i<n;i++){
    for(int j=1;j<=x;j++){
         int take=INF;
    int nottake=dp[i-1][j];
    if(coin[i]<=j){
        take=1+dp[i][j-coin[i]];
    }
    dp[i][j]=min(take,nottake);

    }
   }

 cout << (dp[n - 1][x] >= INF ? -1 : dp[n - 1][x]);

}