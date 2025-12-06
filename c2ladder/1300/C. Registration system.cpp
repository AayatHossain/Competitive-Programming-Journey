#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    map<string,int> m;
    while(t--){
        string s; cin>>s;
        if(m.find(s)==m.end()){
            cout<<"OK"<<endl;
            m[s]=1;
        }else{
            cout<<s<<m[s]<<endl;
            m[s]++;
        }
    }
}