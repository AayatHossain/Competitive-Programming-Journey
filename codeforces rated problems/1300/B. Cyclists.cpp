#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k,p,m; cin>>n>>k>>p>>m;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++)cin>>a[i];

        multiset<int> ms;
        for(int i = 1; i <= k-1; i++){
            ms.insert(a[i]);
        }

        for(int i = k; i <= p-1; i++){
            ms.insert(a[i]);
            m -= *ms.begin();
            ms.erase(ms.begin());
        }
        m -= a[p];
        if( m < 0){
            cout<<0<<endl;
            continue;
        }
        int ans = 1;
        ms.clear();
        for(int i = 1; i <= n; i++){
            if(i==p)continue;
            ms.insert(a[i]);
        }
        int b = a[p];
        
        for(int i = 1; i <= n-k; i++){
            b += *ms.begin();
            ms.erase(ms.begin());
        }
        if(b > 0){
            ans += m/b;
        }
        cout<<ans<<endl;
    }
    return 0;
}