#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int,int> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x; cin>>x;
                m[x]++;
            }
        }
        int f = 1;
        for(auto x: m){
            if(x.second > n*n - n){
                f = 0;
                break;
            }
        }
        if(f)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}