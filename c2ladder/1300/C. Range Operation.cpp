#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        int s = 0;
        vector<int> p(n+1,0);
        for(int i= 1; i <= n; i++){
            p[i] = p[i-1]+a[i];
        }
         s = p[n];
        int mn = LLONG_MAX;
        int mx = LLONG_MIN;
        for(int r = 1; r <= n; r++){
            int l = r;
            int flm1 = (l-1)*(l-1) + (l-1) - p[l-1];
            mn = min(flm1,mn);
            int fr = r*r + r - p[r];
            int diff = fr - mn;
            mx = max(mx, diff); 
        }
        cout<<s+mx<<endl;
    }
    return 0;
}