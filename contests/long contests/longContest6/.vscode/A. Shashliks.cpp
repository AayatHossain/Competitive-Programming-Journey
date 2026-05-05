#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int k,a,b,x,y;cin>>k>>a>>b>>x>>y;
        int c = 0;
        int cu,prod;
        if(x<y){
            if(k >= a){
                cu = k-a;
                prod = cu/x;
                prod++;
                c+=prod;
                k -= prod*x;
            }
            if(k >= b){
                cu = k-b;
                prod = cu/y;
                prod++;
                c+=prod;
                k -= prod*y;
            }
        }else{
            
            if(k >= b){
                cu = k-b;
                prod = cu/y;
                prod++;
                c+=prod;
                k -= prod*y;
            }
            if(k >= a){
                cu = k-a;
                prod = cu/x;
                prod++;
                c+=prod;
                k -= prod*x;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}