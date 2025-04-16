#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        string s,t;cin>>s>>t;
        int hasA = 0;
        for(int i = 0; i < t.size(); i++){
            if(t[i]=='a'){
                hasA = 1;
                break;
            }
        }
        if(hasA && t.size() > 1){
            cout<<-1<<endl;
        }else if(hasA && t.size() == 1){
            cout<<1<<endl;
        }else{
            cout<<(long long) pow(2, s.size())<<endl;
        }
    }
    return 0;
}