#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mod=1e9+7;
int fn(int i, int j ,vector<vector<char>> &mat,vector<vector<int>> & dp){
    if(i<0 || j<0 || mat[i][j]=='*') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 && j==0) return 1;
    int up=0,left=0;
    if(i>0) up=fn(i-1,j,mat,dp);
    if(j>0)left=fn(i,j-1,mat,dp);
    return dp[i][j]=(up+left)%mod;

}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>mat(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    //  vector<vector<int>>dp(n,vector<int>(n,-1));
if(mat[n-1][n-1]=='*'|| mat[0][0]=='*') {
    cout<<0<<endl;
    return 0;
}
    // cout<<fn(n-1,n-1,mat,dp);
         vector<vector<int>>dp(n,vector<int>(n,0));
         dp[0][0]=1;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(mat[i][j]=='*') {
                    dp[i][j]=0;
                    continue;
                }
                   int up=0,left=0;
    if(i>0) up=dp[i-1][j];
    if(j>0)left=dp[i][j-1];
    dp[i][j]=(up+left)%mod;

            }
         }
         cout<<dp[n-1][n-1]<<endl;


}