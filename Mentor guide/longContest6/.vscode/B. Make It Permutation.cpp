#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int l1 = n-1, r1 = n;
        int l2 = 1; int r2 = l1-1;
        cout<<2*n-2<<endl;
        for(int i = 1; i < n; i++){
            cout<<i<<" "<<l1<<" "<<r1<<endl;
            l1--;
            if(r2 == 0)continue;
            cout<<i<<" "<<l2<<" "<<r2<<endl;
            r2--;
        }
        cout<<n<<" "<<1<<" "<<n-1<<endl;
    }
    return 0;
}