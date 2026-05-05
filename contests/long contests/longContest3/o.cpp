#include<bits/stdc++.h>
using namespace std;
vector<int> g[101];
int color[101][3];
void dfs(int src, int turn){
    if(turn != -1){
        color[src][turn] = 1;
    }
    int newTurn = 1;
    if(turn==1){
        newTurn = 2;
    }
    for(auto v : g[src]){
        if(!color[v][newTurn]){
            dfs(v, newTurn);
        }
    }
}
int main(){
    int t;cin>>t;
    int it = 1;
    while(t--){
        for(int i = 0; i < 101; i++){
            g[i].clear();
        }
        memset(color, 0, sizeof(color));
        int n,m;cin>>n>>m;
        for(int i = 0; i < m; i++){
            int x,y; cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1, -1);
        int count = 0;
        for(int i = 1; i < 101; i++){
         
            if(color[i][2]==1){
                count++;
            }
        }
        cout<<"Case "<<it<<": "<<count<<endl;
        it++;
    }
    return 0;
}