#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, s; cin>>n>>s;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    int j = 0;
    int cs = 0;
    int ans = INT_MAX;
    for(int i=0 ; i < n; i++){
        cs += a[i];
        
        while(j <= i && cs - a[j] >= s){
            cs-=a[j];
            j++;
            
        }
        if(cs >= s){
            ans = min(ans, i-j+1);
        }
    }   
    if(ans==INT_MAX){
        ans = -1;
    }
    cout<<ans<<endl;
    return 0;
}