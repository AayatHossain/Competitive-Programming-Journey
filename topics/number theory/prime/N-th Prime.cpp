#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+1;
vector<bool> p(N+1, true);
int n;
void sieve(){
    p[0]=false;
    p[1]=false;
    for(int i=0;i*i<=N;i++){
        if(p[i]){
            for(int j=i*i; j<=N;j+=i){
                p[j]=false;
            }
        }
    }    
}
signed main(){
    cin>>n;
    sieve();
    int c= 0;
    for(int i = 2; i <= N; i++){
        if(p[i])c++;
        if(c==n){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}