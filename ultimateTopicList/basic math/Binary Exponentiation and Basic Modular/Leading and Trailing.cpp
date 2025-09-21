#include<bits/stdc++.h>
using namespace std;
#define int long long
int exp(int a, int b){
    int res =1;
    while(b>0){
        if(b&1){
            res = (res*a)%1000;
        }
        a = (a*a)%1000;
        b/=2;
    }
    return res;
}
signed main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;

        double x = k*log10(n);
        double f = x - floor(x);
        int ld = floor(pow(10,f+2));
        int td = exp(n,k);
        cout << ld << "..." << setw(3) << setfill('0') << td << endl;

    }
}