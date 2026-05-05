#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
vector<int> spf(N);
void sieve(){
    for(int i = 0; i <= N; i++){
        spf[i] = i;
    }
    for(int i = 2; i*i <= N; i++){
        if(spf[i]==i){
            for(int j = i; j <= N; j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}

signed main(){
    sieve();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        map<int,int> m;
        for(int i =0;i<n;i++){
            int v = a[i];
            while(v>1){
                m[spf[v]]++;
                v/=spf[v];
            }
        }
        int f = 1;
        for(auto x: m){
            if(x.second % n !=0){
                f = 0;
                break;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}