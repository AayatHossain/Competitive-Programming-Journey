#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;string s;cin>>s;
        set<int> se;
        for(int i = 0; i < n-1; i++){
            se.insert(s[i]);
        }
        if(se.find(s[n-1]) != se.end()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;

        }
    }
    return 0;
}