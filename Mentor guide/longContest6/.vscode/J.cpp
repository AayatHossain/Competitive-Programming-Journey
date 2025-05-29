#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
// int a[N];
// int dp[N][N];

vector<int> a(N);
vector<int> dp(N,-1);

int f(int curr, int n, int k){
    if(curr==n-1){
        return 0;
    }
    if(curr >= n){
        return LLONG_MAX/2;
    }
    if(dp[curr] != -1)return dp[curr];
    int v1 = LLONG_MAX;
    int optimal = LLONG_MAX;
    for(int i = 1; i <= k; i++){
        if(curr + i < n){
            v1 = abs(a[curr+i] - a[curr]) + f(curr+i, n, k);
            optimal = min(v1, optimal);
        }
    }

    return dp[curr] = optimal;
    
}
signed main(){
    int n,k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    int total = f(0,n, k);
    cout<<total<<endl;
    return 0;
}