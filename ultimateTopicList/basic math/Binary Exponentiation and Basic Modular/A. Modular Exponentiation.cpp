#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m;
    cin>>n>>m;
    if(n < 27){
        cout<<m % (int)pow(2,n)<<endl;
    }else{
        cout<<m<<endl;
    }
    return 0;
}