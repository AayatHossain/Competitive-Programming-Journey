#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, s, t;
const int N = 100000 + 5;
int e[N][3];
vector<pair<int,int>> g[N];
vector<pair<int,int>> rg[N];
vector<long long> d, rd;

// Dijkstra (generic, on given adjacency list)
void dijkstra(int src, vector<pair<int,int>> G[], vector<long long>& dist) {
    dist.assign(n+1, LLONG_MAX/4);
    vector<char> vis(n+1, false);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int u = cur.second;
        long long du = cur.first;
        if (vis[u]) continue;
        vis[u] = true;
        for(auto &pr : G[u]) {
            int v = pr.first;
            int w = pr.second;
            if (dist[v] > du + w) {
                dist[v] = du + w;
                pq.push({dist[v], v});
            }
        }
    }
}

// For bridge finding on undirected graph built from DAG edges
vector<vector<pair<int,int>>> und; // (to, edge_index)
vector<int> tin, low;
vector<char> usedDFS;
int timerDFS;
vector<char> is_bridge;

void dfs_bridges(int v, int peid) {
    usedDFS[v] = 1;
    tin[v] = low[v] = ++timerDFS;
    for(auto &pr : und[v]) {
        int to = pr.first;
        int id = pr.second;
        if (id == peid) continue;
        if (usedDFS[to]) {
            // back edge
            low[v] = min(low[v], tin[to]);
        } else {
            dfs_bridges(to, id);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                // edge id is a bridge in the undirected graph
                is_bridge[id] = 1;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m >> s >> t)) return 0;
    for(int i = 0; i < m; i++){
        int u,v,w; cin>>u>>v>>w;
        e[i][0] = u;
        e[i][1] = v;
        e[i][2] = w;
        g[u].push_back({v,w});
        rg[v].push_back({u,w});
    }

    d.resize(n+1);
    rd.resize(n+1);
    dijkstra(s, g, d);
    dijkstra(t, rg, rd);

    long long dist = d[t];

    // mark edges that belong to some shortest path
    vector<char> in_dag(m, 0);
    for(int i = 0; i < m; i++){
        int u = e[i][0];
        int v = e[i][1];
        int w = e[i][2];
        if (d[u] + w + rd[v] == dist) in_dag[i] = 1;
    }

    // build undirected graph of DAG edges (nodes 1..n), edge id = original index i
    und.assign(n+1, {});
    for(int i = 0; i < m; i++){
        if (!in_dag[i]) continue;
        int u = e[i][0];
        int v = e[i][1];
        // add undirected connection with id = i
        und[u].push_back({v, i});
        und[v].push_back({u, i});
    }

    // prepare bridge arrays
    tin.assign(n+1, 0);
    low.assign(n+1, 0);
    usedDFS.assign(n+1, 0);
    is_bridge.assign(m, 0);
    timerDFS = 0;

    // run DFS from all nodes (graph may be disconnected)
    for(int i = 1; i <= n; i++){
        if (!usedDFS[i]) dfs_bridges(i, -1);
    }

    // Now answer each edge
    for(int i = 0; i < m; i++){
        int u = e[i][0];
        int v = e[i][1];
        long long w = e[i][2];

        if (in_dag[i]) {
            // If this DAG edge is a bridge in the undirected DAG graph AND it's on some s->t path,
            // then it is on every shortest s->t path => YES.
            // But we must ensure the bridge actually separates s and t. In DAG of shortest paths,
            // any bridge on a path from s to t that belongs to some s->t path will separate s and t.
            // To be safe: check that edge is in some s->t path (in_dag true) and is_bridge true.
            if (is_bridge[i]) {
                cout << "YES\n";
            } else {
                cout << "CAN 1\n";
            }
        } else {
            // Not on any current shortest path. Try to reduce weight so that path via this edge
            // becomes strictly shorter than current shortest path:
            // new_w <= dist - 1 - d[u] - rd[v]
            long long max_new_w = dist - 1 - d[u] - rd[v];
            if (max_new_w >= 1 && max_new_w < w) {
                cout << "CAN " << (w - max_new_w) << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
