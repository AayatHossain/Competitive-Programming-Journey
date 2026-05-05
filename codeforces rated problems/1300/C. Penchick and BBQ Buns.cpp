#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n&1){
            if(n%6==1 || n%6==3){
                cout<<-1<<endl;
                continue;
            }
            int a = 1, b = 2;
            int i;
            for( i =1; i+6 <= n; i+=6){
                for(int j= 1; j<=3; j++){
                    cout<<a<<" "<<b<<" ";
                }
                a+=2;
                b+=2;
            }
            i-=6;
            if(n-i+1==2){
                cout<<a<<" "<<a<<endl;
            }else if( n-i+1==3){
                cout<<a<<" "<<a<<" "<<a<<endl;
            }else if(n-i+1==4){
                cout<<a<<" "<<b<<" "<<a<<" "<<b<<endl;
            }else{
                cout<<a<<" "<<b<<" "<<a<<" "<<b<<" "<<a<<endl;
            }

        }else{
            for(int i =1; i <= n/2; i++){
                cout<<i<<" "<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}