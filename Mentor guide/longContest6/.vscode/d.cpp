#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 31;
bool vis[31][31];
int n,k;
int f(int i, int k){
    if(k==0)return 1;
    if(i==n)return 0;
    int ans = 0;
    // cout<<i<<k<<endl;
    for(int j = 0; j < n; j++){
        if(!vis[i][j]){
            for(int k = 0; k < n; k++){
                vis[i][k] = true;
                vis[k][j] = true;
            }
            ans+=f(i+1, k-1);
            for(int k = 0; k < n; k++){
                vis[i][k] = false;
                vis[k][j] = false;
            }
        }
    }
    return ans;
}
signed main(){
    memset(vis, false, sizeof vis);
    // for(int i = 1; i <= 30; i++){
    //     for(int j = 1; j <= 30; j++){
    //         cout<<vis[i][j]<<endl;
    //     }
    // }
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        int ans = 0;
        for(int i = 0; i < n; i++){
            
                ans += f(i,k);
            
        }
        cout<<ans<<endl;
    }
}