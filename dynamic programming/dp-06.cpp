//https://leetcode.com/problems/house-robber-ii/description/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int fn(int i, int end, vector<int>& dp, vector<int>& nums) {
        if (i < end)
            return 0;
        if (i == end)
            return nums[end];
        if (dp[i] != -1)
            return dp[i];
        int pick = nums[i] + fn(i - 2, end, dp, nums);
        int nonpick = fn(i - 1, end, dp, nums);
        return dp[i] = max(pick, nonpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(n, -1);
        int ans1 = fn(n - 2, 0, dp, nums); // not incl last
        vector<int> dp2(n, -1);

        int ans2 = fn(n - 1, 1, dp2, nums);

        return max(ans1, ans2);
    }
};