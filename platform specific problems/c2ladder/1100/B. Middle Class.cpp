#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        vector<int> a(n);
        vector<int> p(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
            
        }
        sort(a.rbegin(),a.rend());
        for(int i = 0; i < n; i++){
            if(i!=0){
                p[i]=p[i-1]+a[i];
            }else{
                p[i]=a[i];
            }
        }
        int ans = -1;
        for(int i = n-1; i >= 0; i--){
            double v = p[i]/(i+1);
            if(v >= x){
                ans = i+1;
                break;
            }
        }
        if(ans == -1){
            ans = 0;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}