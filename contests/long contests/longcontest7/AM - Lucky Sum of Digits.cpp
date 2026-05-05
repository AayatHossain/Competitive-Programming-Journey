#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    string s;
    while(n % 7 != 0 && n > 0){
        s+='4';
        n-=4;
    }
    int c = n/7;
    for(int i = 0; i < c; i++){
        s+='7';
    }
    if( n < 0){
        cout<<-1<<endl;
    }else{
    cout<<s<<endl;

    }
    return 0;
}