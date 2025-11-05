#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
vector<int> p(N);
void s(){
    for(int i = 0; i <= N; i++){
        p[i]=i;
    }
    for(int i = 2; i*i<=N; i++){
        if(p[i]==i){
            for(int j = i; j <= N; j+=i){
                if(p[j]!=j){
                    continue;
                }
                p[j]=i;
            }
        }
    }
}
signed main(){
    int t; cin>>t;
    s();
    while(t--){
        int n,m; cin>>n>>m;
        // cout<<p[n]<<endl;
        if(p[n] >= 2 && p[n] <= m){
           cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        
    }
    return 0;
}