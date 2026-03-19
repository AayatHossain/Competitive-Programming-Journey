#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> primes;
vector<bool> p(1e5+1, true);

void sieve(){
    p[0]=false;
    p[1]=false;
    for(int i = 2; i <= 1e5; i++){
        if(p[i]){
            primes.push_back(i);
            for(int j = i+i; j <= 1e5; j+=i){
                p[j] = false;
            }
        }
    }
}

signed main(){
    int t ;cin>>t; 
    sieve();
    while(t--){
        int n; cin>>n;
        set<int> s;
        for(int i = 0; i < primes.size(); i++){
            if(primes[i] > n){
                break;
            }
            if(n > 0 && n%primes[i]==0){
                s.insert(primes[i]);
            }
            while(n > 0 && n % primes[i]==0){

                n /= primes[i];
            }
        }
        if(n > 1){
            s.insert(n);
        }
        int ans = 1;
        for(auto x: s){
            ans *= x;
        }
        cout<<ans<<endl;
    }
}