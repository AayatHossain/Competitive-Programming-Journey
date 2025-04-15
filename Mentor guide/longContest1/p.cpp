#include<bits/stdc++.h>
using namespace std;
signed main(){
   set<int> s;
   int n;cin>>n;
   for(int i = 0; i < n; i++){
        int x; cin>>x;
        if(x==0){
            int y; cin>>y; s.insert(y);
            cout<<s.size()<<endl;
        }else if(x==1){
            int y; cin>>y; 
            if(s.find(y) != s.end()){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
   }
    return 0;
}