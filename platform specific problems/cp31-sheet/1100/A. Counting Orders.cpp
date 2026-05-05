#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        for(int i = 0; i < n; i++)cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int c = 1;
        for(int i = 0; i < n; i++){
            int v = b[i]+1;
            int pos = lower_bound(a.begin(), a.begin()+i+1, v) - a.begin();
            
            int el;
            if(pos==-1){
                pos = 0;
            }
            el = i - pos + 1;
           
            // cout<<pos<<" "<<el<<endl;
            c = ((c%mod)*(el%mod))%mod;
        }
        cout<<c<<endl;
    }
    return 0;
}