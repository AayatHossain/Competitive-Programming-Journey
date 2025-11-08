#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        vector<int> o(n+1,0);
        vector<int> e(n+1,0);
        set<int> s;
        int f = 0;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
            if(f)continue;
            if(i&1){
                o[i]=o[i-1]+a[i];
                e[i]=e[i-1];
            }else{
                e[i]=e[i-1]+a[i];
                o[i]=o[i-1];
            }
            int d = o[i]-e[i];
            if(s.find(d)!=s.end() || d==0){
                f=1;
            }else{
                s.insert(d);
            }
        }
        // for(auto x: o){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: e){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        if(f){
            cout<<"Yes"<<'\n';
        }
        else {
            cout<<"No"<<'\n';
        }
    }
    return 0;
}