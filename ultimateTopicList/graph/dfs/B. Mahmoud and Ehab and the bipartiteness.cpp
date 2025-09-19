#include <bits/stdc++.h>
using namespace std;
#define int long
const int N = 1e5 + 1;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> t(N, -1);
int n;
int ans = 0;

bool dfs(int u, int c)
{
    vis[u] = true;
    t[u] = c;
    
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            if(!dfs(v,!c)){
                return false;
            }
        }
        else
        {
            if (t[v] == t[u])
            {
                return false;
            }
        }
    }
    return true;
}

signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            bool f = dfs(i,0);
        }
    }
    int c1 = 0, c2 = 0;
    for(int i=1;i<=n;i++){
        if(t[i]==0){
            c1++;
        }else{
            c2++;
        }
    }
    int ans = c1*c2 - (n-1);
    cout << ans << endl;
}