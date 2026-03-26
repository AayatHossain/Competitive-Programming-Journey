#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<bool> p(N+1,true);
// vector<int> c(N+1,0);
void sieve(){
    p[0]=false;
    p[1]=false;
    for(int i = 2; i <= N; i++){
        if(p[i]){
            for(int j = i+i; j <= N; j+=i){
                p[j]=false;
            }
        }
    }
}
int count(int n){
    vector<int> c(n+1,0);
    for(int i = 2; i <= n; i++){
        
            for(int j = i+i; j <= n; j+=i){
                if(p[j/i]){
                    c[j]++;
                }
            }
            if(p[i]){
                c[i]++;
            }
        
    }
    for(int i = 3; i <= n; i++){
        c[i] = c[i-1] + c[i];
    }
    return c[n];
}
signed main(){
    int t; cin>>t;
    sieve();
    while(t--){
        int n; cin>>n;
        int ans = count(n);
        cout<<ans<<endl;
    }
    return 0;
}