#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin>>n;
    int g = 0;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        g = gcd(g, x);
    }
    // cout<<g<<endl;
    int c = 0;
    for(int i = 1; i*i <= g; i++){
        if(g%i == 0){
            if(g/i == i){
                c++;
            }else{
                c+=2;
            }
        }
    }
    cout<<c<<endl;
    return 0;
}