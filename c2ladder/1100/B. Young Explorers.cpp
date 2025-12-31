#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int c = 1;
        int ans = 0;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        for(int i = 0; i < n; i++){
           
            if(c==a[i]){
                ans++;B. Ashmal

                c = 1;
                continue;
            }
            c++;
        }
        cout<<ans<<endl;

    }
    return 0;
}