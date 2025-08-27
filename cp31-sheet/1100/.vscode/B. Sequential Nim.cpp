#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
       int n; cin>>n;
       int i=-1;
       for(int j = 0; j < n; j++){
         int x; cin>>x;
         if(x>1 && i==-1){
            i=j+1;
           
         }
       }
       
    //    cout<<i<<endl;
       int f = 0;
       if((i%2 && i != -1) || (i==-1 && n%2)){
        f = 1;
       }
       if(f)cout<<"First"<<endl;
       else cout<<"Second"<<endl;
    }
    return 0;
}