#include<bits/stdc++.h>
using namespace std;
#define int long long
const int H = 1000, W = 1000;
int dp[H][W];
char a[H][W];
const int mod = 1e9+7;
int f(int i, int j, int h, int w){
    if(i < 0 || i >=h || j < 0 || j >= w || a[i][j] == '#'){
        return 0;
    }
    if(i==h-1 && j == w-1){
        return 1;
    }
    if(dp[i][j] != -1)return dp[i][j];
    return dp[i][j] = (f(i+1,j,h,w)%mod + f(i, j+1, h, w)%mod)%mod;  
}
signed main(){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            dp[i][j] = -1;
        }
    }
    int h, w; cin>>h>>w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin>>a[i][j];
        }
    }
    int ways = f(0,0,h,w);
    cout<<ways<<endl;
    return 0;
}