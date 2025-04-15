#include<bits/stdc++.h>
using namespace std;
signed main(){
   vector<int> a;
   int n;cin>>n;
   for(int i = 0; i < n; i++){
        int x; cin>>x;
        if(x==0){
            int y; cin>>y; a.push_back(y);
        }else if(x==1){
            int y; cin>>y; cout<<a[y]<<endl;
        }else{
            a.pop_back();
        }
   }
    return 0;
}