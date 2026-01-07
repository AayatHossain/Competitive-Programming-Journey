#include<bits/stdc++.h>
using namespace std;
bool p(int n){
    if(n < 2)return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i==0)return false;
    }
    return true;
}
signed main(){
    int l = 10, r = 1000;
    int c = 0;
    for(int i =l; i<=r; i++){
        if(p(i)){
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}