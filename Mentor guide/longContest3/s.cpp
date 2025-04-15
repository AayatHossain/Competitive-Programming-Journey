#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>g[], int s, int d){
    g[s].push_back(d);
    g[d].push_back(s);
}

void bfs(vector<int>g[], vector<bool> &vis, vector<int> &par, int src, int dst, int m){
    // priority_queue<int, vector<int>, greater<int>> q;
    queue<int> q;
    q.push(src); vis[src] = true;
    while(!q.empty()){
        int s = q.size();
        for(int i = 0; i < s; i++){
            int u = q.front();
            q.pop();
            if(u==dst){
                return;
            }
            sort(g[u].begin(), g[u].end());
            for(auto v: g[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                    par[v] = u;
                }
            }
        }
    }
}

void printPath(vector<int> &par,int src, int dst, int c){
    vector<int> ans;
    ans.push_back(dst);
    int curr = par[dst];
    while(1){
        ans.push_back(curr);
        if(curr==src){
            break;
        }
        curr = par[curr];
    }
    reverse(ans.begin(), ans.end());
    // cout<<"Case "<<c<<":"<<endl;
    printf("Case %d:\n", c);
    c++;
    for(int i = 0; i < ans.size(); i++){
        // cout<<ans[i]+1<<" ";
        printf("%d ", ans[i]+1);
    }
    printf("\n");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    scanf("%d", &t);
    int c = 1;
    while(t--){
        int n;
        scanf("%d", &n);
        vector<int>a(n);
        int nodes = -1;
        for(int i = 0; i < n; i++){
            
            scanf("%d", &a[i]);
            nodes = max(nodes, a[i]);
            
        }
        int src = a[0]-1, dst = a[n-1]-1;
        int m = nodes;
        vector<int>g[m];
        for(int i = 0; i < n-1; i++){
            addEdge(g,a[i]-1,a[i+1]-1);
        }
        vector<bool> vis(m,false);
        vector<int> parent(m,-1);
        bfs(g,vis,parent,src,dst,m);
        printPath(parent,src, dst, c);
        c++;

    }
    return 0;
}