#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int ans = 0;
        if(n==k){
            int j = 1;
            for(int i = 1; i < n; i+=2){
                if(a[i]!=j){
                    ans=j;
                    break;
                }else{
                    j++;
                }
            }
            if(!ans)ans=(n/2)+1;
        }else{
            ans = 2;
            for(int i = 1; i < n; i++){
                if(a[i] > 1){
                    int need = k-2;
                    if(need <= n-i-1){
                        ans = 1;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}