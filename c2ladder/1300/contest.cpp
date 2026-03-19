#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,k,p,m;
        cin >> n >> k >> p >> m;

        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];

        // min heap: {cost, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        queue<pair<int,int>> q;

        // first k → pq
        for(int i=1;i<=k;i++){
            pq.push({a[i], i});
        }

        // rest → queue
        for(int i=k+1;i<=n;i++){
            q.push({a[i], i});
        }

        int energy = m;
        int win_count = 0;

        while(energy > 0){
            pair<int,int> chosen;
            vector<pair<int,int>> temp;

            bool found = false;

            // 🔍 check if p is inside pq
            while(!pq.empty()){
                auto cur = pq.top(); pq.pop();
                if(cur.second == p && !found){
                    chosen = cur;
                    found = true;
                } else {
                    temp.push_back(cur);
                }
            }

            // restore pq
            for(auto &x: temp) pq.push(x);

            // if p not found → take smallest
            if(!found){
                if(pq.empty()) break;
                chosen = pq.top(); pq.pop();
            }

            // check energy
            if(energy < chosen.first) break;

            energy -= chosen.first;

            if(chosen.second == p){
                win_count++;
            }

            // move chosen to back
            q.push(chosen);

            // move next queue element → pq
            if(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }

        cout << win_count << "\n";
    }

    return 0;
}