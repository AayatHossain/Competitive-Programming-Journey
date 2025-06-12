#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+7;
int n;
signed main(){
    cin>>n;
    int f = 0, s = 0;
    while(n >= 0){
        if(n % 7 == 0){
            s = n / 7; 
            n = 0; break;
        }
        f++; n -= 4;
    }
    if(!n){
        for(int i = 0; i < f; i++){
            cout<<4;
        }
        for(int i = 0; i < s; i++){
            cout<<7;
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
}