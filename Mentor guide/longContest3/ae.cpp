#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m,q;cin>>n>>m>>q;
    int g[n][n];//not n*m its n*n
    int INF = LLONG_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j){
                g[i][j] = 0;
            }else{
                g[i][j] = INF;
            }
        }
    }
    for(int i = 0; i < m ; i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        if (w < g[u][v]) { 
            g[u][v] = w;
            g[v][u] = w;
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][k] < INF && g[k][j] < INF){
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
    for(int i = 0; i < q; i++){
        int u, v; cin>>u>>v;
        u--;v--;
        
        if(g[u][v]==INF){
            cout<<-1<<endl;
        }else{
            cout<<g[u][v]<<endl;
        }
    }
    return 0;
}