#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k,a,b; cin>>n>>k>>a>>b;
        vector<vector<int>> cities(n, vector<int>(2));
        pair<int,int> s;
        pair<int,int> d;
        for(int i = 0; i < n; i++){
            cin>>cities[i][0]>>cities[i][1];
            if(i==a-1){
                s = {cities[i][0], cities[i][1]};
            }
            if(i==b-1){
                d = {cities[i][0], cities[i][1]};
            }
        }
        if(a <= k && b <= k){
            cout<<0<<endl;
        }else{
            int ans1 = LLONG_MAX;
            int ans2 = LLONG_MAX;
           if(k >= 2){
            int costa = LLONG_MAX;
            int costb = LLONG_MAX;
            for(int i = 0; i < k; i++){
                costa = min(costa, abs(s.first-cities[i][0])+abs(s.second-cities[i][1]));
            }
            for(int i = 0; i < k; i++){
                costb = min(costb, abs(d.first-cities[i][0])+abs(d.second-cities[i][1]));
            }
            ans1 = costa+costb;
           }
                ans2 = abs(s.first - d.first) + abs(s.second - d.second);
           
            cout<<min(ans1, ans2)<<endl;
        }

    }
    return 0;
}