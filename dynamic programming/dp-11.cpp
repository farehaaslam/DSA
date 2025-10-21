//https://leetcode.com/problems/triangle/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int fn(int i, int j, int n, vector<vector<int>>& tri,
           vector<vector<int>>& dp) {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == n - 1)
            return tri[i][j];
        int dow = fn(i + 1, j, n, tri, dp);
        int dia = fn(i + 1, j + 1, n, tri, dp);
        return dp[i][j] = min(dow, dia) + tri[i][j];
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return fn(0,0,n,tri,dp);
        //tabulation base case;
        for(int i=0;i<n;i++){
            dp[n-1][i]=tri[n-1][i];
        }
        for (int i = n-2; i>=0; i--) {
            for (int j = i; j >=0; j--) {
                
                int down=dp[i+1][j]+tri[i][j];
                int dia=dp[i+1][j+1]+tri[i][j];
                dp[i][j] = min(down, dia) ;
            }
        }
        
        return dp[0][0];
    }
};