#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int q; cin>>q;
    while(q--){
        int n,t; cin>>n>>t;
        map<int,int>m;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            int d = t-x;
            if(d < 0 || m[d]==0){
                cout<<0<<" ";
                m[x]++;
            }else{
                // m[d]--;
                if(m[d]&1){
                    cout<<1<<" ";
                }else{
                    cout<<0<<" ";

                }
                m[x]++;
            }
        }
        cout<<endl;
    }
    return 0;
}