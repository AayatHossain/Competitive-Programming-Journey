#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        int f0 = 1, f1 = 1;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int ind; cin>>ind;
        ind--;
        for(int i = 0; i < ind; i++){
            if(a[i] != a[i+1]){
                c1++;
            }
        }
        for(int i = ind; i < n-1; i++){
            if(a[i] != a[i+1]){
                c2++;
            }
        }
        int ans = max(c1,c2);
        if(ans&1)ans++;
        cout<<ans<<endl;
        

    }
    return 0;
}