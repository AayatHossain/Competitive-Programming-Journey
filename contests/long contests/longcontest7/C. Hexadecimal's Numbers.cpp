#include<bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
void f(int v){
    if(v<=n){
        ans++;
    }else{
        return;
    }
    f(v*10 + 0);
    f(v*10 + 1);
}
signed main(){
    cin>>n;
    f(1);
    cout<<ans<<endl;
    return 0;
}