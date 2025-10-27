#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MX = 2e5 + 5;
int n, m;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> bes[MX];
vector<pair<int, int>> adj[MX];
priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	bes[1].push({0,0});
	pq.push({0, {1,0}});
	while (!pq.empty()) {
		auto a = pq.top();
		pq.pop();
		if (a.first > bes[a.second.first].top().first) continue;
		for (auto &i : adj[a.second.first]) {
			int tmp = a.first + i.second;
                if(bes[i.first].empty() || bes[i.first].top().first >tmp){
                    // while(!bes[i.first].empty() && bes[i.first].top().first >tmp){
                    // }
                    if(!bes[i.first].empty()){
                        bes[i.first].pop();
                    }
                    bes[i.first].push({tmp, a.second.second+1});
				    pq.push({tmp, {i.first, a.second.second+1}});
                }else if(!bes[i.first].empty() && bes[i.first].top().first ==tmp){
                    bes[i.first].push({tmp, a.second.second+1});
				    pq.push({tmp, {i.first, a.second.second+1}});
                }
				
			
		}
	}
	vector<int> ans;
    int c = 0;
    int mn = LLONG_MAX/2;
    int mx = LLONG_MIN/2;
    int v = bes[n].top().first;
	while (!bes[n].empty() && bes[n].top().first==v) {
		mx = max(mx, bes[n].top().second);
		mn = min(mn, bes[n].top().second);
        c++;
		bes[n].pop();
	}
	cout<<v<<" "<<c<<" "<<mn<<" "<<mx<<endl;
}