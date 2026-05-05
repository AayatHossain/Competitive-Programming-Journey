#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        int mn = LLONG_MAX;
        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && a[j]==a[i]){
                j++;
            }
            j--;
            if(i==0 && j==n-1){
                mn = 0;
                break;
            }
            int cost = (i)*a[i] + (n-j-1)*a[j];
            // if(i==2){
            //     cout<<i<<" "<<j<<" "<<cost<<endl;
            // }
            mn = min(mn, cost);
            i=j;
        }
        cout<<mn<<endl;
    }
    return 0;
}