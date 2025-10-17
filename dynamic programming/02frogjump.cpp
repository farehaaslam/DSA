//https://www.geeksforgeeks.org/problems/geek-jump/1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int fn(int idx,vector <int> &arr,vector<int> &dp){
        if(dp[idx]!=-1) return dp[idx];
        int twojump=INT_MAX;
        int onejump=fn(idx-1,arr,dp)+abs(arr[idx]-arr[idx-1]);
        if(idx>1) twojump=fn(idx-2,arr,dp)+abs(arr[idx]-arr[idx-2]);
        return dp[idx]=min(onejump,twojump);
    }
    int minCost(vector<int>& arr) {
        // Code here
        //dp  with memo
        int n=arr.size();
        vector<int>dp(n,-1);
        dp[0]=0;
        //int ans=fn(n-1,arr,dp);
        //return ans;
        for(int i=1;i<n;i++){
            int twojump=INT_MAX;
            int onejump=dp[i-1]+abs(arr[i]-arr[i-1]);
            if(i>1) twojump=dp[i-2]+abs(arr[i]-arr[i-2]);
            dp[i]=min(onejump,twojump);

        }
        return dp[n-1];
    }
};
