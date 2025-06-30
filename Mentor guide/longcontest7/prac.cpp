#include<bits/stdc++.h>
using namesapce std;
class Solution {
    int f(int curr, vector<int>& nums, int target, int i, int n, vector<vector<int>> &dp){
        if(curr==target){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(dp[target-curr][i] != -1){
            return dp[target-curr][i];
        }
        int count = 0;
        for(int k = i; k < n; k++){
            count += f(curr+nums[k], nums, target, k, n, dp);
        }
        return dp[target-curr][i] = count;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(target+1, vector<int>(nums.size(), -1));
        return f(0, nums, target, 0, nums.size() - 1, dp);
    }
};