#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N = 101;
vector<vector<int>> a(N, vector<int>(N));
vector<vector<int>> dp(N, vector<int>(N));
vector<vector<bool>> vis(N, vector<bool>(N, false));

int f(int i, int j, int t){
    if(i==0 && j == 0 && t == 1)return 0;
    int invalid = i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == true;
    if(invalid)return LLONG_MIN/2;
    if(dp[i][j] != -1)return dp[i][j];
    if(i==n-1 && j == m-1)t = 1;
    vis[i][j] = true;
    int v1,v2;
    if(!t){
         v1 = a[i][j] + f(i+1, j, t);
         v2 = a[i][j] + f(i, j+1, t);
        
    }else{
         v1 = a[i][j] + f(i, j-1, t);
         v2 = a[i][j] + f(i-1, j, t);
       
    }
    vis[i][j] = false;
    return dp[i][j] =  max(v1,v2);
}
signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        string s; getline(cin, s);
        cin>>n>>m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>a[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vis[i][j] = false;
                dp[i][j] = -1;
            }
        }
        
        cout<<"Case "<<c<<": "<<f(0,0,0)<<endl;
        c++;
    }
}