#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int mx = (n*(n-1))/2;

        int l = 0, r=0, steps = 0;
        int i1 = -1, i2 = -1;
        for(int i = 0; i <= mx; i++){
            l = r + 1;
            r = l + steps;
            // cout<<l<<" "<<r<<" "<<steps<<endl;
            if(k >= l && k <= r){
                i1 = n - (steps+1);
                i2 = n-(k-l);
                break;
            }
            steps++;
        }
        // cout<<i1<<" "<<i2<<endl;
        for(int i = 1; i <= n; i++){
            if(i==i1){
                cout<<'b';
            }else if(i==i2){
                cout<<'b';
            }else{
                cout<<'a';
            }
        }
        cout<<'\n';
    }
    return 0;
}