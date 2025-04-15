#include<bits/stdc++.h>
using namespace std;
signed main(){
   map<string, int> m;
   int n;cin>>n;
   for(int i = 0; i < n; i++){
        int x; cin>>x;
        if(x==0){
            string y; int z; cin>>y>>z;
            m[y] = z;
        }else if(x==1){
            string y; cin>>y;
            cout<<m[y]<<endl;
        }
   }
    return 0;
}