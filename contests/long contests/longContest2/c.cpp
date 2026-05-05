#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n, k;cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int count = 0;
        sort(a.begin(), a.end());
        for(int i = 0; i < 59; i++){
            int val = (int) pow(k,i);
            if(val > a[n-1]){
                break;
            }
            int l = lower_bound(a.begin(), a.end(), val) - a.begin();
            int r = upper_bound(a.begin(), a.end(), val) - a.begin();
            int amount = r - l;
            count += amount;
        }
        cout<<count<<endl;

    }   
    return 0;
}