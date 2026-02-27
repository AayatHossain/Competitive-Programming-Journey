#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        multiset<int> ms;
        for(int i = 0; i < n; i++){
            int x;cin>>x;
            ms.insert(x);
        }
       
        int h = 1;
        int cw = w;
        while(1){
            auto it = ms.upper_bound(cw);
            if(it==ms.begin()){
                h++;
                cw = w;
            }else{
                it--;
                int v = *it;
                cw-=v;
                ms.erase(it);
            }

            if(ms.size()==0){
                break;
            }
        }
        cout<<h<<endl;
    }
    return 0;
}