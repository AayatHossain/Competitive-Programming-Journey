// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        int w = capacity;
        vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= w; j++){
                int v1 = dp[i-1][j];
                int v2 = 0;
                if(j - wt[i-1] >= 0){
                    v2 = dp[i][j-wt[i-1]] + val[i-1];
                    
                }
                dp[i][j] = max(v1,v2);
            }
        }
        return dp[n][w];
    }
};