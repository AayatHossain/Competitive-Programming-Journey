#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        int a[3];
        memset(a, 0, sizeof a);
        int v = 1;
        int i = 0;
        int moves = 0;
        while(1){
            if(i==0){
                a[i]=v; i++;
            }else if(i==1){
                a[i] = a[i-1] * 2 - 1; i++;
            }else{
                a[i] = a[i-1] + 1; 
                v = a[i] + 1;
                i = 0; 
            }
            moves++;
            // for(int i = 0; i < 3; i++){
            //     cout<<a[i]<<" ";
            // }
            // cout<<endl;

            if(a[0] >= x || a[1] >=x || a[2] >= x){
                break;
            }
            
        }
        int count = 0;
        for(int i = 0; i < 3; i++){
            if(a[i] == x){
                count++;
            }
        }
        cout<<moves + (3 - count)<<endl;
    }
    return 0;
}