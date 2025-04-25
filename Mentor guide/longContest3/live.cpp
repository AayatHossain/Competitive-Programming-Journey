#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        set<int> s;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(b[i] != -1){
                s.insert(a[i] + b[i]);
                sum = a[i] + b[i];
            }
        }
        if(s.size() > 1){
            cout<<0<<endl;
        }else if(s.size() == 1){
            int possible = 1;
            for(int i = 0; i < n; i++){
                int req = sum - a[i];
                if(!(req >= 0 && req <= k)){
                    cout<<0<<endl;
                    possible = 0;
                    break;
                }
            }
            if(possible){
                cout<<1<<endl;
            }
        }else{
            if(a.size()==1){
                cout<<k+1<<endl;
            }else{
                int minV = INT_MAX;
                int maxV = INT_MIN;
                for(int i = 0; i < n ; i++){
                    minV = min(a[i], minV);
                    maxV = max(a[i] , maxV);
                }
                int cap = maxV - minV;
                cout<<k - cap + 1<<endl;
            }
        }

    }
}