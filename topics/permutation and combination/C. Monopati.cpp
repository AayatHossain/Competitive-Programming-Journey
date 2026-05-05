#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        vector<pair<int,int>> pa(n);
        pa[0]={a[0],a[0]};
        for(int i = 1; i < n; i++){
            pa[i] = {min(a[i],pa[i-1].first),max(a[i],pa[i-1].second)};
        }


        vector<pair<int,int>> sb(n);
        sb[n-1]={b[n-1],b[n-1]};
        for(int i = n-2; i >= 0; i--){
            sb[i] = {min(b[i],sb[i+1].first),max(b[i],sb[i+1].second)};
        }

        // for(auto x: sb){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // cout<<endl;

        vector<pair<int,int>> intervals;
        for(int i = 0; i < n; i++){
            pair<int,int> p1 = pa[i];
            pair<int,int> p2 = sb[i];
            
           
            intervals.push_back({min(p1.first, p2.first), max(p1.second, p2.second)});
        }

      
        sort(intervals.begin(), intervals.end());

       
        vector<pair<int,int>> clean_intervals;
        for(auto p : intervals) {
            
            while(!clean_intervals.empty() && clean_intervals.back().second >= p.second){
                clean_intervals.pop_back();
            }
            clean_intervals.push_back(p);
        }

        
        int ans = 0;
        int prev_L = 0;
        for(auto p : clean_intervals){
           
            if(p.first > prev_L) {
                ans += (p.first - prev_L) * (2 * n - p.second + 1);
                prev_L = p.first;
            }
        }

        cout << ans << endl;

    }
    return 0;
}