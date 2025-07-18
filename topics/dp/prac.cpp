#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i]==1){
                continue;
            }
            int c = 0;
            while(i < n && c < k){
                if(a[i]==1 || c==k){
                    break;
                }else{
                    i++;
                    c++;
                }
            }
            i--;
            if(c==k){
                ans++; i++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}