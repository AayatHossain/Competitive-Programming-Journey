#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int moves = 0;
        if(n%2 != 0){
            n-=k; moves++;
        }
        if(n > 0){
            int temp = n / (k-1);
            moves += temp;
            n = n - (k-1)*temp;
            if(n > 0){
                moves ++;
            }
        }
        cout<<moves<<endl;
    }
    return 0;
}