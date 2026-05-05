#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int n,m;
const int N = 1e5+1;
vector<pair<int,int>> g[N];
vector<int> d(N, LLONG_MAX/2);
vector<int> mn(N, LLONG_MAX/2);
vector<int> mx(N, LLONG_MIN/2);
vector<int> cnt(N, 0);
void f(int s){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	d[s]=0; 
	cnt[s]=1;
	mn[s]=0;
	mx[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u = q.top().second;
		int du = q.top().first;
		q.pop();
		if(du != d[u])continue;
		for(auto x: g[u]){
			int v = x.first;
			int w = x.second;
			int tmp = du + w;
			if(tmp < d[v]){
				d[v]=tmp;
				q.push({tmp, v});
				cnt[v]=cnt[u];
				mn[v] = mn[u]+1;
				mx[v] = mx[u]+1;

			}else if(tmp==d[v]){
				cnt[v] = (cnt[v]+cnt[u])%mod;
				mn[v] = min(mn[v], mn[u]+1);
				mx[v] = max(mx[v], mx[u]+1);
			}
		}
	}
	
}
signed main(){
	cin>>n>>m;
	for(int i = 0; i <m; i++){
		int u,v,w; cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	f(1);
	cout<<d[n]<<" "<<cnt[n]<<" "<<mn[n]<<" "<<mx[n]<<endl;
	return 0;
}
