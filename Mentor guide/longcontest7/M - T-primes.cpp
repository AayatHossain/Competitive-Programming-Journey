#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+1;
vector<bool> primes(N, false);

bool isPrime(int x){
    if(x <= 1)return false;
    for(int i = 2; i <= sqrt(x); i++ ){
        if(x%i==0)return false;
    }
    return true;
}

void sieve(){
    for(int i = 1; i <=N; i++){
        if(!primes[i]){
            if(isPrime(i)){
                primes[i] = true;
                for(int j = i+i; j <= N; j+=i){
                    primes[j] = false;
                }
            }
        }
    }
}

bool ps(int x){
    int y = sqrt(x);
    bool valid = primes[y];
    return y*y==x && valid;
}
signed main(){
    sieve();
    int n;cin>>n;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        if(ps(x) && x != 1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}