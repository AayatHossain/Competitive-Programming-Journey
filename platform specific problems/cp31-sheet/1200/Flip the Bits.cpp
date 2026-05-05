#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string a,b;cin>>a>>b;
        map<int,int> m;
        set<int> s;
        for(int i = 0;i < n; i++){
            if(a[i]=='0'){
                m[0]++;
            }else{
                m[1]++;
            }
            if(m[0]==m[1]){
                s.insert(i);
            }
        }
        string normal, flipped, bnormal;
        bool possible = true;
        for(int i = 0 ; i < n; i++){
            normal += a[i];
            if(a[i]=='1'){
                flipped += '0';
            }else{
                flipped += '1';
            }
            bnormal += b[i];
            if(s.find(i)!=s.end()){
                if(normal==bnormal || flipped == bnormal){
                    normal.clear();
                    flipped.clear();
                    bnormal.clear();
                    continue;
                }else{
                    possible = false;
                    break;
                }
            }
        }
        if(normal != bnormal){
            possible = false;
        }
        if(possible){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
}