#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500000;
vector<int> p(N+1,1);
void weirdSieve(){
    p[0]=0; p[1]=0;
    for(int i = 2; i <= N; i++){
        for(int j = 2*i; j<=N; j+=i){
            p[j] += i;
        }
    }
}

signed main(){
    weirdSieve();
    int t; scanf("%lld",&t);
    while(t--){
        int n; scanf("%lld",&n);
        printf("%lld\n",p[n]);
              
    }
    return 0;
}
