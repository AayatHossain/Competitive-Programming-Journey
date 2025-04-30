#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v(31);
signed main(){
    for(int i = 0; i <= 30; i++){
        v[i] = 1LL<<i;
    }
    int t;cin>>t;
    while(t--){
        int n,q; cin>>n>>q;
        vector<int> a(n);
        vector<int> x(q);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < q; i++){
            cin>>x[i];
        }
        int last = -1;
        for(int i = 0; i < q; i++){
            int pow = x[i];
            int v1 = v[pow];
            int v2 = v[pow-1];
            if(last == -1 || last > v1){
                for(int j = 0; j < n; j++){
                    if(a[j] % v1 == 0){
                        a[j] += v2;
                    }
                }
                last = v1;
            }
        }
        for(int i = 0; i < n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}