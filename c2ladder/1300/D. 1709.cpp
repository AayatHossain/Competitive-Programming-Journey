#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> g[N+1];
vector<int> ind(N+1, 0);
int n,m; 
vector<int> ans;

void bfs(){
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= n; i++){
        if(ind[i]==0){
            q.push(i);
           
        }
    }
    while(!q.empty()){
        int u = q.top();
        q.pop();
         ans.push_back(u);
        for(int v: g[u]){
            ind[v]--;
            if(ind[v]==0){
                
                q.push(v);
            }
            

        }
    }
}

signed main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        ind[v]++;
    }
    bfs();
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;



    

    
    return 0;
}