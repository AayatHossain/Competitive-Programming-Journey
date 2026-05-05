class Solution {
    int f(int i,int j,string s1, string s2, vector<vector<int>> &dp,int n,int m){
        if(i==n)return m-j;
        if(j==m)return n-i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=f(i+1,j+1,s1,s2,dp,n,m);
        }else{
            int v1 = 1 + f(i,j+1,s1,s2,dp,n,m);
            int v2 = 1 + f(i+1,j,s1,s2,dp,n,m);
            int v3 = 1 + f(i+1,j+1,s1,s2,dp,n,m);
            return dp[i][j]=min(v1,min(v2,v3));
        }
    }
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = f(0,0,s1,s2,dp,n,m);
        return ans;
    }
};