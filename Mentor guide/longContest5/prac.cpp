#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
vector<pair<int,int>> graph[N];
vector<bool> vis(N, false);
int mst(){
    int src = 1;
    int cost = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(vis[u.second]){
            continue;
        }
        cost += u.first;
        vis[u.second] = true;
        for(auto v: graph[u.second]){
            if(!vis[v.first]){
                pq.push({v.second, v.first});
            }
        }
    }
    return cost;
}
signed main(){
    int n,m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int src, dst, wt; cin>>src>>dst>>wt;
        graph[src].push_back({dst, wt});
        graph[dst].push_back({src, wt});
    }
    cout<<mst()<<endl;
    return 0;
}