#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+1;
vector<int> fact(N);
const int mod = 998244353;

void calc(){
    fact[0]=1; fact[1]=1;
    for(int i = 2; i <= N; i++){
        fact[i]= (fact[i-1] * i)%mod;
    }   
}

signed main(){
    calc();
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int cnt = 0;
        int ways = 0;
        int tmp = 1;
        for(int i = 1; i < s.size();i++){
            
            if(s[i]==s[i-1]){
                tmp++;
            }else if(tmp>1){
                cnt = cnt + tmp-1;
                ways = (ways + fact[tmp])%mod;
                tmp = 1;
                // cout<<ways<<endl;
            }
        }
        if(tmp > 1){
            cnt = cnt + tmp-1;
            ways = (ways + fact[tmp]*(tmp-1))%mod;
            tmp = 1;
        }
        if(ways==0){
            ways = 1;
        }
        cout<<cnt<<" "<<ways<<endl;
    }
}