#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int N = 1000;
vector<int> f(N+1,1);
int inv(int a){
    int b = mod-2;
    int res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

int ncr(int n,int r){
    int res = (((f[n]*inv(f[r]))%mod)*inv(f[n-r]))%mod;
    return res;
}

signed main(){
    int t; cin>>t;

    for(int i = 2; i <= N; i++){
        f[i] = (f[i-1]*i)%mod;
    }
    // for(int i = 0; i <= 5; i++){
    //     cout<<f[i]<<endl;
    // }
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.rbegin(),a.rend());
        int kth;
        set<int> s;
        for(int i=0; i < n; i++){
            s.insert(a[i]);
            if(i+1==k){
                kth = a[i];
                break;
            }
        }
        int kthcnt = 0;
        int d = s.size();
        int choices =1;

        for(int i = 0; i < n; i++){
            if(a[i]==kth){
                kthcnt++;
            }
        }

        for(int i = 0; i < n; i++){
            if(a[i]==kth){
                int pos = i+1;
                choices = (k - pos) + 1;
                break;
            }
        }
        int res = ncr(kthcnt, choices);
        // cout<<kthcnt<<endl;
        // cout<<choices<<endl;
        cout<<res<<endl;
    }
    return 0;
}