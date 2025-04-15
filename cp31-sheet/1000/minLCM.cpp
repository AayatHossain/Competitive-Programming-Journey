#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
       long long n;
       cin>>n;
       long long x = n/2;
       if(x+x == n){
        cout<<x<<" "<<x<<endl;
       }else{
        long long l1 = lcm(x+1, x);
        long long l2 = lcm(x+2, x-1);
        if(x-1==0){
            l2 = LLONG_MAX;
        }
        if(n-1 < l1 && n-1 < l2){
            cout<<n-1<<" "<<1<<endl;
        }else{
            if(l2==LLONG_MAX){
                cout<<x+1<<" "<<x<<endl;
            }else{
                if(l1< l2){
                    cout<<x+1<<" "<<x<<endl;
                }else{
                    cout<<x+2<<" "<<x-1<<endl;
                }
            }
        }
       }
    }
    return 0;
}