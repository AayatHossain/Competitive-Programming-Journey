#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        string s; cin>>s;
        int n = s.size();
        vector<int> pos;
        for(int i= 0 ; i < n; i++){
            if(s[i]=='1')pos.push_back(i);
        }
        int c = 0;
        if(pos.size()==0){
            cout<<0<<endl;
            continue;
        }
        c = a;
        for(int i= 1; i < pos.size(); i++){
            int gap = pos[i] - pos[i-1] - 1;
            if(b*gap <= a){
                c += b*gap;
            }else{
                c+=a;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}