#include <bits/stdc++.h>
using namespace std;

bool ok(int k,int n, vector<int> &a, vector<int> &b, int mx, int mn){
    if(mx - mn < k)return false;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(abs(mx - a[i]) < k && abs(a[i] - mn ) < k)return false;
        }
    }
    return true;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int mx = INT_MIN;
        int mn = INT_MAX;
        int f = 1;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            mx = max(mx,a[i]);
            mn = min(mn,a[i]);
            if(i > 0 && a[i] < a[i-1]) f = 0;
        }
        if(f){
            cout<<-1<<endl;
            continue;
        }
        vector<int> b = a;
        sort(b.begin(),b.end());
        int l = 0, r = 2e9;
        int ans =LLONG_MIN; 
        while(l <= r){
            int m = l + (r-l)/2;
            if(ok(m,n,a,b,mx,mn)){
                ans = max(m,ans);
                l = m+1;
            }else{
                r= m-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}