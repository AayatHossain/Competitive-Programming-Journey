#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int n = 5e6;
vector<int> p(n+1,1); 
vector<int> pf(n+1,0); 
vector<int> cnt(n+1,0); 
void spf(){
    p[0]=0; p[1]=0;
    for(int i=2;i<=n;i++){
        p[i]=i;
    }
    for(int i = 2; i*i<=n; i++){
        if(p[i]==i){
            for(int j=i*i; j<=n; j+=i){
                if(p[j]==j){
                    p[j]=i;
                }
            }
        }
    }
}

void pref(){
    cnt[0]=0, cnt[1]=0;
    for(int i = 2; i <= n; i++){
        cnt[i] = 1 + cnt[i/p[i]];
    }

    for(int i = 1; i <= n;i++){
        pf[i] =pf[i-1]+cnt[i];
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    spf();
    pref();
    int t;
    cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        cout<<pf[a]-pf[b]<<'\n';
    }
    return 0;
}