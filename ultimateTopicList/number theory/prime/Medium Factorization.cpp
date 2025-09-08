#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+1;
vector<int> p(N+1, 1);
void spd(){
    for (int i = 0; i <= N; i++) {
        p[i] = i;
    }
    
    for (int i = 2; i * i <= N; i++) {
        if (p[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (p[j] == j) {
                    p[j] = i;
                }
            }
        }
    }
}
void f(int n){
    vector<int> primes;
    while(n > 1){
        primes.push_back(p[n]);
        n /= p[n];
    }
    printf("1");
    for(int i = 0; i < primes.size(); i++){
        printf(" x %lld",primes[i]);
    }
    printf("\n");
}
signed main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; 
    spd();
    while(scanf("%lld", &n)==1) {
        f(n);
        // cout<<p[12]<<endl;
    }
    return 0;
}