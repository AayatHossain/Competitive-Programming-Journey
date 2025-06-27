#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        int z = (a*b)*2;
        int x = a;
        int y = z-x;
        cout<<"YES"<<endl;
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
    return 0;
}