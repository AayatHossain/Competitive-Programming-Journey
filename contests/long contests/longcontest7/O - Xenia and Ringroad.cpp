#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,m; cin>>n>>m;
    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin>>a[i];
    }
    int ans = 0;
    int prev = 1;
    for(int i = 0; i < m; i++){
        
        if(a[i] < prev){
            ans += (n-prev) + a[i];
        }else{
            ans += a[i] - prev;
        }
        prev = a[i];
    }
    cout<<ans<<endl;
    return 0;
}