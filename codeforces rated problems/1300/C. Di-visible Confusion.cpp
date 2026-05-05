#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        int cnt = 0;
        int f = 1;
        for(int i = 1; i <= n; i++){
            int index = i + 1;
            if(a[i]%index != 0){
                cnt++;
            }else{
                bool ok = false;
                for(int j = 1; j <= cnt; j++){
                    if(a[i] % (index - j)!=0){
                        ok = true;
                        cnt++;
                        break;
                    }
                }
                if(!ok){
                    f = 0;
                    break;
                }
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        

    }
    return 0;
}