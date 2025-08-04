#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n, k; cin>>n>>k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    int dp[n+1][k+1];
    memset(dp, 0, sizeof dp);
    // dp[0][0] = 1;
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    set<int> ans;
    for(int i = 1; i <= n; i++){
        for(int j = k; j >= 1; j--){
            int v1,v2=0;
            v1 = dp[i-1][j];
            if(j - a[i] >= 0){
                v2 = dp[i-1][j-a[i]];
            }
            dp[i][j] = v1 | v2;
            
        }
    }
   
bitset<501> dp2[501];  // dp2[i] = bitset of all subset sums possible with total sum = i
dp2[0][0] = 1;

for(int i = 1; i <= n; i++){
    for(int j = k; j >= a[i]; j--){
        dp2[j] |= dp2[j - a[i]] << a[i];
    }
}

// Now dp2[k] contains all x such that there exists a subset of coins summing to k,
// and within that subset, there's a subset summing to x.
for(int x = 0; x <= k; x++){
    if(dp2[k][x]) ans.insert(x);
}

    

   cout<<ans.size()<<endl;
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}