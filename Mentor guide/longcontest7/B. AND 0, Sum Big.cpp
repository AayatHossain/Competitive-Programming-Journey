#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9+7;
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int ans = 1;
        for(int i = 0; i < k; i++){
            ans = (ans*n)%N;
        }
        cout<<ans<<endl;;
    }
    return 0;
}