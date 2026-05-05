#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,m;cin>>n>>m;
    map<string, string> ms;
    for(int i = 0; i < m; i++){
        string s,t; cin>>s>>t;
        ms[s] = t;
    }

    for(int i = 0; i < n; i++){
        string s; cin>>s;
        string t = ms[s];
        if(s.size() <= t.size()){
            cout<<s<<" ";
        }else{
            cout<<t<<" ";
        }
    }
    cout<<endl;
    return 0;
}