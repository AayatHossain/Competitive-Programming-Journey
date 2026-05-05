#include<bits/stdc++.h>
using namespace std;
const int n = 1e7+1;
vector<bool> p(n,true);
signed main(){
    for(int i = 2; i*i<=n;i++){
        if(p[i]){
            for(int j=i*i; j<=n;j+=i){
                p[j]=false;
            }
        }
    }

    int c = 0;
    for(int i = 2; i < n;i++){
        if(p[i]){
            c++;
            if(c%100 == 1){
                cout<<i<<endl;
            }
        }
    }
    return 0;
}