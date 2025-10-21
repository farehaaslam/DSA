//https://leetcode.com/problems/unique-paths-ii/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int fn(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (grid[i][j] == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = fn(i - 1, j, grid, dp);
        int left = fn(i, j - 1, grid, dp);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return 0;
        // return fn(m - 1, n - 1, grid, dp);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    dp[i][j]=1;
                    continue;
                }
                if(grid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                int left=0;
                int up=0;
                if( i>0){
                    up=dp[i-1][j];
                }
                if( j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};