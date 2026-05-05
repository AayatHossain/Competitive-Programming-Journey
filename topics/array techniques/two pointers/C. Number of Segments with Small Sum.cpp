#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, s; cin>>n>>s;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int cs = 0;
    int j = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cs+=a[i];
        if(cs > s){
            while(j<=i && cs > s ){
                cs-=a[j];
                j++;
            }
            
        }
        if(cs!=0){
                ans += i-j+1;
        }
        //    if(i==5){
        //     cout<<j<<" "<<i<<endl;
        //    }

    }
    cout<<ans<<endl;
    return 0;
}