class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        for(int i = 1; i<= n; i++){
            for(int j = W; j >= 1; j--){
                int v1 = dp[i-1][j];
                int v2 = 0;
                if(j - wt[i-1] >= 0){
                    v2 = dp[i-1][j-wt[i-1]] + val[i-1];
                }
                dp[i][j] = max(v1, v2);
            }
        }
        return dp[n][W];
        
    }
};