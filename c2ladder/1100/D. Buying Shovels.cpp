#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int mn = n;
        for(int i = 1; i*i<=n; i++){
            if(n%i==0){
                int v1 = i;
                if(v1<=k)
                    mn = min(n/v1,mn);

                int v2 = n/i;
                if(v2<=k)
                    mn = min(mn,n/v2);
                
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}