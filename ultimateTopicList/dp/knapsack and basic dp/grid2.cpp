#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;  

long long fact[MAX];
long long invFact[MAX];


long long modPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}


void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i-1] * i % MOD;

    invFact[MAX-1] = modPow(fact[MAX-1], MOD-2);
    for (int i = MAX-2; i >= 0; i--)
        invFact[i] = invFact[i+1] * (i+1) % MOD;
}


long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}

int main() {
    precompute();

    int h,w,n; cin>>h>>w>>n;
    int v = 0;
    for(int i = 0; i< n; i++){
       
        int r,c; cin>>r>>c;
        // int rp = nCr(r,c) + nCr(h-r+1, w-c+1);
        int rp = 0;
        int nr = h-r+1;
        int nc = w-c+1;
        rp = nCr(r+c-2, c-1) * nCr(nr+nc-2,nc-1);
        v+=rp;
    }
    int total = nCr(h+w-2,h-1) -v;
    cout<<total<<endl;

    return 0;
}
