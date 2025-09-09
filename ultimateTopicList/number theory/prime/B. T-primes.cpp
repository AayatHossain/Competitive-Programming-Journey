#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+1;
vector<bool>p(N,true);
void sieve(){
    p[0]=false;
    p[1]=false;
    for(int i=2;i*i<=N;i++){
        if(p[i]){
            for(int j=i*i;j<=N;j+=i){
                p[j]=false;
            }
        }
    }
}
signed main(){
    sieve();
    int n; cin>>n;
    for(int i =0;i<n;i++){
        int x; cin>>x;
        int y = sqrt(x);
        // cout<<y<<" "<<p[y]<<endl;
        if(p[y] && y*y==x){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}