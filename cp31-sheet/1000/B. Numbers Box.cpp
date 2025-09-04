#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int sum = 0;
        int neg = 0;
        int mn = INT_MAX;
        int z = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x; cin>>x;
                mn = min(mn, abs(x));
                if(x < 0){
                    neg++;
                }
                if(x==0){
                    z++;
                }
                sum+=abs(x);

            }
        }
        if(neg%2==0){
            cout<<sum<<endl;
        }else if(z>0){
            cout<<sum<<endl;
        }else{
            cout<<sum-2*mn<<endl;
        }
    }
    return 0;
}