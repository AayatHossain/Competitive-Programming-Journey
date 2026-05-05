#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int a, int b){
    int c = 1;
    int t = 1;
    int cnt = 0;
    while(1){
        if(t){
            if(a-c < 0){
                break;
            }
            a-=c;
        }else{
            if(b - c < 0){
                break;
            }
            b-=c;
        }
        t = !t;
        c*=2;
        cnt++;
    }
    return cnt;
}
signed main(){
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        cout<<max(f(a,b),f(b,a))<<endl;
    }
    return 0;
}