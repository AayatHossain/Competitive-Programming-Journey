#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int n,m;
vector<int>a(N+1);
vector<int> g[N+1];
int f(int u, int c){
    if(c > m){
        cout<<u<<" "<<c<<endl;
        return 0;
    }
    if(c <= m && g[u].empty() && u != 1){
        return 1;
    }
    int ans = 0;
    for(auto v: g[u]){
        int fl = c > 0 && a[v];
        if(fl){
            ans += f(v,c+1);
        }else{
            ans += f(v, a[v]);
        }
    }
    return ans;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n-1;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
    }
    int v = f(1,a[1]);
    cout<<v<<endl;
    return 0;
}