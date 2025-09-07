#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+1;
vector<bool> p(N+1, true);
void sieve(){
    for(int i=2;i*i<=N;i++){
        if(p[i]){
            for(int j=i*i; j<=N;j+=i){
                p[j]=false;
            }
        }
    }
}
void f(int n){
    cout<<1;
    for(int i=2; i*i<=N && n>1;i++){
        if(p[i]){
            while(n%i == 0){
                cout<<" x "<<i;
                n/=i;
            }
        }
    }
    cout<<endl;
}
signed main(){
    int n; 
    while(cin>>n){
        f(n);
    }
    return 0;
}