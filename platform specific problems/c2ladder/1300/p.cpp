#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,l,r; cin>>n>>l>>r;
        vector<int> a(n+1);
        int f = 1;
        if((r-l)%2==0){
            f = 0;
        }
        if(f){
            for(int i = l; i <= r; i++){
                a[i] = 1;
            }
        }else{
            if(l==r){
                a[l]=1;
            }else{
                a[l]=1;
                a[l+1]=3;
                a[l+2]=2;
                for(int i = l+3; i <= r; i++){
                    a[i]=1;
                }
            }
        }
        int v = 4;
        for(int i = 1; i<=n; i++){
            if(a[i]==1 || a[i]==3 || a[i]==2){
                continue;
            }else{
                a[i]=v;
                v++;
            }
        }
        for(int i = 1; i <= n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}