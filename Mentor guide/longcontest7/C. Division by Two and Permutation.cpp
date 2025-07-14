#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        set<int> s;
        for(int i = 0; i < n; i++){
            int v = a[i];
            while(v > 0){
                if(s.find(v) != s.end()){
                    v /= 2;
                }else{
                    if(v >= 1 && v <= n){
                        s.insert(v);
                        break;
                    }else{
                        v/=2;
                    }
                }
            }
        }
        if(s.size()==n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}