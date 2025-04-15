#include <bits/stdc++.h>
using namespace std;
vector<int> money;
void addEdge(vector<int> graph[], int src, int dst)
{
    graph[src].push_back(dst);
    graph[dst].push_back(src);
}
void dfs(vector<int> g[], vector<bool> &vis, int src, int &coins, int &nodes)
{
    vis[src] = true;
    coins+= money[src];
    nodes++;
    for (auto x : g[src])
    {
        if (!vis[x])
        {
            dfs(g, vis, x, coins, nodes);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            money.push_back(x);
        }
        vector<int> g[n];
        vector<bool> vis(n, false);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            addEdge(g, x, y);
        }
        bool ans = true;
        vector<int> dist;
        for (int i = 0; i < n; i++)
        {
            // cout<<i<<endl;

            int coins = 0, nodes = 0;
            if (!vis[i])
            {
                dfs(g, vis, i, coins, nodes);
                int pN = coins / nodes;
                int total = pN * nodes;
                // cout<<"asds"<<coins<<" "<<nodes<<endl;
                if (total != coins)
                {
                    ans = false;
                    break;
                }else{
                    dist.push_back(pN);
                }
            }
        }
        if(dist.size() >= 1){
            for(int i = 0; i < dist.size() - 1; i++){
                if(dist[i] != dist[i+1]){
                    ans = false; break;
                }
            }
        }
        if(ans){
            cout<<"Case "<<c<<": "<<"Yes"<<endl;
       
        }else{
            cout<<"Case "<<c<<": "<<"No"<<endl;
        
        }
        c++;
        money.clear();
    }
    return 0;
}