#include <bits/stdc++.h>
using namespace std;


bool equalPartition(vector<int> &arr)
{
    int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        if(sum&1)return false;
        sum/=2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                int v1 = dp[i-1][j];
                int v2 = 0;
                if(j - arr[i-1] >= 0){
                    v2 = dp[i-1][j-arr[i-1]];
                }
                dp[i][j] = v1 | v2;
            }
        }
        
        return dp[n][sum];
}
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << equalPartition(a) << endl;
    return 0;
}