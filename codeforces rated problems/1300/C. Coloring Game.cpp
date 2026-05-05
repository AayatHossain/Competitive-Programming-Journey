#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int x = max(2*a[i],a[n-1]) - a[i] - a[j];
                int index = upper_bound(a.begin(),a.begin() + j, x) - a.begin();
                if(index >= 0 && index < j){
                    ans += j - index;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}