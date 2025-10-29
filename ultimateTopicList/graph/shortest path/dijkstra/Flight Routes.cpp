#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N = 1e5+1;
vector<pair<int,int>> g[N];
// vector<int> d(N,LLONG_MAX/2);
priority_queue<int> g2[N];
void f(int s){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,s});
	g2[s].push(0);
	// d[s]=0;
	while(!q.empty()){
		int u = q.top().second;
		int du = q.top().first;
		q.pop();
		if(du > g2[u].top())continue;
		for(auto x: g[u]){
			int v= x.first;
			int w = x.second;
			int tmp = du+w;
			
				if(g2[v].size() == k && g2[v].top() > tmp){
					g2[v].pop();
					g2[v].push({tmp});
					q.push({tmp, v});
				}else if(g2[v].size() < k){
					g2[v].push({tmp});
					q.push({tmp, v});
					
				}
			
		}
	}
}
signed main(){
	cin>>n>>m>>k;
	for(int i = 0; i < m; i++){
		int u,v,w; cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	f(1);
	vector<int> ans;
	while(!g2[n].empty()){
		ans.push_back(g2[n].top());
		g2[n].pop();
	}
	reverse(ans.begin(), ans.end());
	for(auto x: ans){
		cout<<x<<" ";
	}
	cout<<'\n';
	return 0;
}