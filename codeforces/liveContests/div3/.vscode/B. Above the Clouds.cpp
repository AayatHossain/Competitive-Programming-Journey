#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string s; cin>>s;
        set<char> se;
        se.insert(s[0]);
        se.insert(s[n-1]);
        int flag = 0;
        for(int i = 1; i < s.size()-1; i++){
            if(se.find(s[i]) != se.end()){
                flag = 1; break;
            }else{
                se.insert(s[i]);
            }
        }
        
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}