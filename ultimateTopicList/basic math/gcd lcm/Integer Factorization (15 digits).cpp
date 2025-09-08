#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e7;
vector<int> p(N+1,1);
vector<int> primes;
void spd(){
    
    
    for (int i = 2; i * i <= N; i++) {
        if (p[i] == 1) {
            
            for (int j = i * i; j <= N; j += i) {
                p[j]=0;
            }
        }
    }
    for(int i = 2; i <= N; i++){
        if(p[i]==1){
            primes.push_back(i);
        }
    }
}
void f(int n){
    map<int,int> m;
    for(int i = 0; i < primes.size(); i++){
        int v = primes[i];
        if(v*v > n){
            break;
        }
        while(n%v==0){
            m[v]++;
            n/=v;
        }
    }
    if(n > 1){
        m[n]++;
    }
    for(auto x: m){
        cout<<x.first<<"^"<<x.second<<" ";
    }
    cout<<'\n';
}
signed main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; 
    spd();
    while(scanf("%lld", &n)==1 && n!=0) {
        f(n);
        // cout<<p[12]<<endl;
    }
    return 0;
}