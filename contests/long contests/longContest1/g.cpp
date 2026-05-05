#include<bits/stdc++.h>
using namespace std;
signed main(){
    string s,t;cin>>s>>t;
    int n = s.size();
    int m = t.size();
    int flag = 0;
    if(m > n){
        set<int> se;
        for(int i = 0; i < m; i++){
            se.insert(t[i]);
        }
        for(int i = 0; i < n; i++){
            if(se.find(s[i]) != se.end()){
                flag = 1;break;
            }
        }
    }else{
        set<int> se;
        for(int i = 0; i < n; i++){
            se.insert(s[i]);
        }
        for(int i = 0; i < m; i++){
            if(se.find(t[i]) != se.end()){
                flag = 1;break;
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}