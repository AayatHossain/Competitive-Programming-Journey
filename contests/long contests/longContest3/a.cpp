#include<bits/stdc++.h>
using namespace std;
vector<int> g[20000];
vector<bool> vis(20000, false);

void addEdge(int src, int dst){
    g[src].push_back(dst);
    g[dst].push_back(src);
}
int bfs(int src, int n){
    queue<pair<int,int>> q;
    int c1 = 0;
    int c2 = 0;
    q.push({src, 1});
    c1++;
    vis[src] = true;
    while(!q.empty()){
        int s = q.size();
        for(int i = 0; i < s; i++){
            auto x = q.front();
            q.pop();
            for(auto y: g[x.first]){
                if(!vis[y]){
                    if(x.second==1){
                        q.push({y,2});
                        c2++;
                    }else{
                        q.push({y,1});
                        c1++;
                    }
                    vis[y] = true;
                }
            }
        }
    }
    return max(c1,c2);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;scanf("%d",&t);
    int c = 1;
    while(t--){
        int n;scanf("%d",&n);
        set<int> nodes;
        for(int i = 0; i < n; i++){
            int x,y;scanf("%d%d",&x,&y);
            x--;y--;
            addEdge(x,y);
            nodes.insert(x);
            nodes.insert(y);
        }
        int ans = 0;
        for(auto x: nodes){
            if(vis[x]==false){
                ans += bfs(x,n);

            }
        }
        
        for(int i = 0; i < 20000; i++){
            g[i].clear();
        }
        fill(vis.begin(), vis.end(), false);

        printf("Case %d: %d\n",c,ans);
        c++;
    }
    return 0;
}