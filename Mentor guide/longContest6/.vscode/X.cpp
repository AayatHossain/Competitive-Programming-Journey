#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 160;
char a[N][N];
int dp[N][N][2];

int f(int w, int i, int j, int f, int n, int m){
    int invalid = 
}

signed main(){
    memset(dp, -1, sizeof(dp));
    int n,m;cin>>n>>m;
    int w = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            if(a[i][j]=='W'){
                w++;
            }
        }
    }
    int ans = f(w,0,0,1,n,m);
    cout<<ans<<endl;

}