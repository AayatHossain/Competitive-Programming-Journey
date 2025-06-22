#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N = 3001;
vector<int> a(N);
int dp[N][N];
int f(int i, int j){
    if(i>j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int v1 = a[i] + min(f(i+2,j), f(i+1,j-1));
    int v2 = a[j] + min(f(i,j-2), f(i+1,j-1));
    return dp[i][j] = max(v1,v2);
}
signed main(){
    cin>>n;
    int sum = 0; 
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    memset(dp, -1, sizeof dp);
    int x = f(0,n-1);
    int y = sum-x;
    cout<<x-y<<endl;

    return 0;
}