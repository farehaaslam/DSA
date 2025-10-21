//https://leetcode.com/problems/unique-paths/description/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
int fn(int m ,int n,vector<vector<int>>&dp){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    //up
   int up=fn(m-1,n,dp);
   //left
   int left=fn(m,n-1,dp);
return dp[m][n]=up+left;

}
    int uniquePaths(int m, int n) {
        vector<vector<long long>>dp(m,vector<long long>(n,-1));
       // return fn(m-1,n-1,dp);
       for(int i=0;i<m;i++ ){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }
            long long up=0;
            long long left=0;

            if(i>0){
                up=dp[i-1][j];
            }
            if(j>0){
                left=dp[i][j-1];
            }
           dp[i][j]=up+left;
        }
       }
       return dp[m-1][n-1];

        
    }
};