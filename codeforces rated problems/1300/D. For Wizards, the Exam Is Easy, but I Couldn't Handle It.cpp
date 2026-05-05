#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int x,y; cin>>x>>y;
        // int n = abs(x)+abs(y);
        int d = abs(x-y);
        int c = 0;
        if(d == 0){
            c = 1;
        }else{
            for(int i = 1; i * i <= d; i++){
                if(d % i == 0){
                    c++;
                    if(i * i != d) c++;
                }
            }
        }
        cout<<c<<endl;
        if(x >= y){
            for(int i = 0; i < x; i++){
                cout<<1<<" ";
            }
            for(int i = 0; i < y; i++){
                cout<<-1<<" ";
            }
            cout<<endl;
        }else{
            for(int i = 0; i < y; i++){
                cout<<-1<<" ";
            }
            for(int i = 0; i < x; i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}