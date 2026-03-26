#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fn(int i,int x,vector<int>&price,vector<int>&pages, vector<vector<int>> &dp){
    if(x==0) return 0;
   if(i==0 && x>=price[0]) return pages[0];
   if(i==0) return 0;
   if(dp[i][x]!=-1) return dp[i][x];
    int take=-1e9;
    int nottake=fn(i-1,x,price,pages,dp);
    if(x>=price[i])take=fn(i-1,x-price[i],price,pages,dp)+pages[i];
    return  dp[i][x]=max(take,nottake);
}
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int>price;
    vector<int>pages;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        price.push_back(p);
    }
    for(int i=0;i<n;i++){
        int pg;
        cin>>pg;
        pages.push_back(pg);
    }
   // vector<vector<int>>dp(n,vector<int>(x+1,-1));
    //cout<<fn(n-1,x,price,pages,dp);
     vector<vector<int>>dp(n,vector<int>(x+1,0));
     for(int i=price[0];i<=x;i++) dp[0][i]=pages[0];

     for(int i=1;i<n;i++){
        for(int j=0;j<=x;j++){
            int take=-1e9;
            int nottake=dp[i-1][j];
            if(j>=price[i])take=dp[i-1][j-price[i]]+pages[i];
              dp[i][j]=max(take,nottake);

        }
     }
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<=x;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    //  }
        cout<<dp[n-1][x]<<endl;


}