#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int k = 2e6;
        int mx = *max_element(a.begin(), a.end());
        int mn = *min_element(a.begin(), a.end());
        if(mx==mn){
            cout<<-1<<endl;
        }else{
            while(k >= 1){
                int f = 1;
                for(int i = 0; i < n; i++){
                    int s = a[i];
                    int d = a[i] - mn;
                    if(d%k != 0){
                        f = 0;
                        break;
                    }
                }
                if(f){
                   
                    break;
                }
                k--;
            }
            cout<<k<<endl;
        }
    }
}