#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    int mn = INT_MAX;
    int ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        if(i < k){
            ans += a[i];
            if(i==k-1){
                if(ans<mn){
                    mn = ans;
                    j = i-k+1;
                }
            }
        }else{
            ans-=a[i-k];
            ans+=a[i];
            if(ans<mn){
                    mn = ans;
                    j = i-k+1;
            }
        }
    } 
    cout<<j+1<<endl;
    return 0;
}