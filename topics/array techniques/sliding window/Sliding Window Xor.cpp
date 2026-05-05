#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> b(32,0);

void put(int x){
    for(int i = 0;i < 32; i++){
        if(x & (1LL<<i)){
            b[i]++;
        }
    }
}

void rem(int x){
    for(int i = 0;i < 32; i++){
        if(x & (1LL<<i)){
            b[i]--;
        }
    }
}

int calc(){
    int v = 0;
    for(int i = 0;i < 32; i++){
        if(b[i]&1){
            v += (1LL<<i);
        }
    }
    return v;
}

signed main(){

    ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n, k; cin>>n>>k;
    int a,b,c,x; cin>>x>>a>>b>>c;
    vector<int> arr(n+1);
    arr[1] = x;
    for(int i = 2; i <= n; i++){   
        arr[i] = (a*arr[i-1] + b)%c;
    }
    
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(i <= k){
            put(arr[i]);
            if(i==k){
                int v = calc();
                ans ^= v;
            }
        }else{
            
                put(arr[i]);
                rem(arr[i-k]);
                int v = calc();
                ans ^= v;
            
        }
    }
    cout<<ans<<'\n';

    
    return 0;
}