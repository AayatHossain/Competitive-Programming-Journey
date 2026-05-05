#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin>>n;
    for(int k = 1; k <= n; k++){
        int n1 = ((k*k*k*k) - (k*k))/2;
        int n2 = 4 * max(k-1,(long long)0) * max(k-2,(long long)0);
        cout<<n1-n2<<endl;
    }
    return 0;
}