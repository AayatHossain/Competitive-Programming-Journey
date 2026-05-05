// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5+7;
// const int H = 1e4+7;
// // int a[N];
// // int dp[N][N];

// vector<int> a(N);
// vector<vector<int>> dp(N, vector<int>(H, -1));

// int f(int curr, int prev, int n){
//     if(curr==n-1){
//         return abs(a[curr] - prev);
//     }
//     if(curr >= n){
//         return LLONG_MAX/2;
//     }
//     if(dp[curr][prev] != -1)return dp[curr][prev];
//     int cost = abs(a[curr] - prev);
//     int v1 = f(curr+1, a[curr], n)+cost;
//     int v2 = f(curr+2, a[curr], n) + cost;
//     return dp[curr][prev] = min(v1,v2);
    
// }
// signed main(){
//     // for(int i = 0; i < N; i++){
//     //     for(int j = 0; j < H; j++){
//     //         dp[i][j] = -1;
//     //     }
//     // }

//     int n;
//     cin>>n;
//     for(int i = 0; i < n; i++){
//         cin>>a[i];
//     }
    
//     int total = f(0,a[0],n);
//     cout<<total<<endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
// int a[N];
// int dp[N][N];

int f(int curr, int prev, int n, vector<int> &a, vector<vector<int>> &dp){
    if(curr==n-1){
        return abs(a[curr] - a[prev]);
    }
    if(curr >= n){
        return LLONG_MAX/2;
    }
    if(dp[curr][prev] != -1)return dp[curr][prev];
    int cost = abs(a[curr] - a[prev]);
    int v1 = f(curr+1, curr, n, a, dp)+cost;
    int v2 = f(curr+2, curr, n, a, dp) + cost;
    return dp[curr][prev] = min(v1,v2);
    
}
signed main(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int total = f(0,0,n, a, dp);
    cout<<total<<endl;
    return 0;
}