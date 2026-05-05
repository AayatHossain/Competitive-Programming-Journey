#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        map<int,int> mm;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            mm[x%m]++;
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            if(mm.find(i)!=mm.end()){

                int v;
                if(i==0){
                    v = 0;
                }else{
                    v = m-i;
                }
                if(i==v){
                    mm[i] = 0;
                    ans++;
                // cout<<i<<" "<<ans<<endl;
                    
                    continue;
                }
                if(mm.find(v)!=mm.end() && mm[v] != 0){
                    ans++;
                    if(mm[i]>mm[v]){
                        ans+= mm[i] - (mm[v]+1);
                        mm[v] = 0;
                        mm[i] = 0;
                    }else if(mm[i] < mm[v]){
                        ans += mm[v] - (mm[i]+1);
                        mm[v] = 0;
                        mm[i] = 0;
                    }else{
                        mm[i] = 0;
                        mm[v] = 0;
                    }
                }else{
                    ans += mm[i];
                    mm[i] = 0;
                }
                // cout<<i<<" "<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}