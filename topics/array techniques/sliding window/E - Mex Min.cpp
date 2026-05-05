#include<bits/stdc++.h>
using namespace std;
void print(multiset<pair<int,int>> ms){
    for(auto x: ms){
        cout<<x.first<<" "<<x.second<<endl;
    }
}
signed main(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i < n; i++)cin>>a[i];

    map<int,int> m;
    multiset<pair<int,int>> ms;
    
    for(int i = 0; i <= n; i++){
        ms.insert({0,i});
    }
    int res = INT_MAX;
    for(int i = 0; i < n; i++){
        if(i <= k-1){
            int key = a[i];
            int val = m[a[i]];
            int nval = val+1;
            ms.erase({val,key});
            ms.insert({nval,key});
            m[key]++;
            
            int ans = (*ms.begin()).second;
            if(i==k-1){
                // print(ms);
                // cout<<ans<<" ";
                res = min(res, ans);
            }
        }else{
            int key = a[i];
            int val = m[a[i]];
            int nval = val+1;
            ms.erase({val,key});
            ms.insert({nval,key});
            m[key]++;

            int keyfront = a[i-k];
            int valfront = m[keyfront];
            int nvalfront = valfront-1;
            ms.erase({valfront,keyfront});
            ms.insert({nvalfront,keyfront});
            m[keyfront]--;


            int ans = (*ms.begin()).second;
            res = min(res, ans);

            // if(i==6){
            //     print(ms);
            //     cout<<ans<<" ";
            // }

        }
    }
        cout<<res<<endl;


}