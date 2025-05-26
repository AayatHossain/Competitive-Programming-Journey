#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int flag = 0;
        sort(a.begin(), a.end());
        int ans = LLONG_MAX;
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= i; j--){
                if((a[i] + a[j]) % 2 == 0){
                    ans = min(ans, i+(n-j-1));
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}