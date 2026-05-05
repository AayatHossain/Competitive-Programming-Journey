#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    if(n&1){
        cout<<4*n<<endl;
    }else{
        cout<<4*n - 4 <<endl;
    }
    return 0;
}