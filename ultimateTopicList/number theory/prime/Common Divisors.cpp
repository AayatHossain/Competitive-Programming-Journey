#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
map<int,int> m;
void sieve(){
    m[0]=0; m[1]=0;
    for(int i = 1; i<=N; i++){
        for(int j = i; j <= N; j+=i){
            m[i]+=j;
        }
    }
}
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i <n;i++){
        cin>>a[i];
    }
    return 0;
}