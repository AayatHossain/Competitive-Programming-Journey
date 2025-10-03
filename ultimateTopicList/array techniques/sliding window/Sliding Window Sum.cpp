#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, k; cin>>n>>k;
    int a,b,c,x; cin>>x>>a>>b>>c;
    vector<int> arr(n+1);
    arr[1] = x;
    for(int i = 2; i <= n; i++){   
        arr[i] = (a*arr[i-1] + b)%c;
    }
    int ans = 0;
    int cs = 0;
    for(int i = 1; i <= n; i++){
        if(i <= k){
            cs+=arr[i];
            if(i==k){
                ans ^=cs;
            }
        }else{
            cs += (arr[i] - arr[i-k]);
            ans ^= cs;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}