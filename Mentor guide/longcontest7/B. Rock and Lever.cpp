#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.rbegin(), a.rend());
        int i = 31;
        int v = a[0];
        int ans = 0;
        vector<int> bits(33, 0);
        for(int i = 0; i < n; i++){
            int highest = -1;
            for(int j = 31; j>= 0; j--){
                if((1<<j)&a[i]){
                    highest = j;
                    break;
                }
            }
            if(highest!=-1){
                bits[highest]++;
            }
        }
        for(int i = 0; i < 33; i++){
            int c = bits[i];
            // cout<<c<<" "<<endl;
            ans += (c*(c-1))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}