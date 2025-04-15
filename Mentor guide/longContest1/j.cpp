#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        string s;
        cin>>s;
        map<char,int>m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        bool flag = 1;
        for(auto x: m){
            if(x.second & 1){
                flag = 0; break;
            }
        }
        cout<<(flag? "YES" : "NO")<<endl;
    }
    
    return 0;
}