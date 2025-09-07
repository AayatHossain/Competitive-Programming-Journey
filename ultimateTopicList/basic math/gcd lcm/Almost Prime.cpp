#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> p(n+1,1);
    for(int i=2;i<=n;i++){
        if(p[i]==1){
            for(int j=i;j<=n;j+=i){
                p[j]++;
            }
        }
    }
    int c=0;
    for(int i = 2; i <= n; i++){
        if(p[i]-1==2){
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}