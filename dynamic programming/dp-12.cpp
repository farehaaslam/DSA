//https://leetcode.com/problems/minimum-falling-path-sum/
#include<iostream>
#include<vector>
using namespace std;
// memoization
class Solution {
public:
int fn(int i,int j,vector<vector<int>> & matrix,vector<vector<int>> & dp){
    if(i==matrix.size()-1) return matrix[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int downright=1e9;
    int downleft=1e9;
    int down=fn(i+1,j,matrix,dp);
    if(j!=0) downleft=fn(i+1,j-1,matrix,dp);
    if(j!=matrix.size()-1) downright=fn(i+1,j+1,matrix,dp);
    return dp[i][j]=matrix[i][j]+min({down,downleft,downright});

}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=1e9;
        vector<vector<int>>dp(n,vector<int>(vector<int>(n,-1)));
        // for(int i=0;i<n;i++){
        //     mini=min(mini,fn(0,i,matrix,dp));

        // }
        // return mini;

        //tabulation
        for(int i=0;i<n;i++) dp[n-1][i]=matrix[n-1][i];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down=dp[i+1][j];
                int downleft=(j>0)? dp[i+1][j-1]:1e9;
                int downright=(j<n-1) ? dp[i+1][j+1]:1e9;
                dp[i][j]=matrix[i][j]+min({down,downleft,downright});
            }
        }
        int minsum=*min_element(dp[0].begin(),dp[0].end());
        return minsum;
        
    }
};