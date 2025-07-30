#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t ; cin>>t;
    while(t--){
        int x; cin>>x;
        // int v = 0;
        int i = 1;
        int a = 0;
        int v=0;
        while(v < x){
            a++;
            v = (i*(i+1))/2;
            i++;

        }
        if(v==x+1)a++;
        cout<<a<<endl;
    }
    return 0;
}