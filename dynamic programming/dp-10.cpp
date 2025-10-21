//https://leetcode.com/problems/minimum-path-sum/description/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
int fn(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& dp ){
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];

    int up=fn(i-1,j,grid,dp);
    int down=fn(i,j-1,grid,dp);
    return dp[i][j]=min(up,down)+grid[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>>dp (m,vector<long long>(n,-1));
        //return fn(m-1,n-1,grid,dp);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }
                long long up=INT_MAX;
                long long left=INT_MAX;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];

                dp[i][j]=min(up,left)+grid[i][j];

            }
        }
        return dp[m-1][n-1];
        
    }
};