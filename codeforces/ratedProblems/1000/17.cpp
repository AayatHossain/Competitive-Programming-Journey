#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int count = 0;
        while(n > 0){
            if(n <= k){
                n = 0; count++;break;
            }else if(n % 2 == 0){
                if(k%2==0){
                    n -= k;
                }else{
                    n-=(k-1);
                }
            }else{
                if(k%2!=0){
                    n -= k;
                }else{
                    n-=(k-1);
                }
            }
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}