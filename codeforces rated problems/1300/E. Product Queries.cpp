#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<int> a;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            a.insert(x);
        }
        vector<int> b;
        for(auto x: a){
            b.push_back(x);
        }
        int m = b.size();
        vector<int> c(n+1,INT_MAX);
        for(int i = 0; i < m; i++){
            if(b[i]==1)continue;
            
            int cnt = 1;
            for(int j = b[i]; j <= n; j*=b[i]){
                c[j] = cnt;
                cnt++;
            }
        }
        // for(auto x: c){
        //     cout<<x<<" ";
        // }
        if(b[0]==1)c[1]=1;

        for(int i = 2; i <= n; i++){
            for(int j = 2; j*j <= i; j++){
                if(i%j != 0)continue;
                int d1 = j;
                int d2 = i/d1;

                if(c[d1] != INT_MAX && c[d2]!=INT_MAX){
                    c[i] = min(c[i], c[d1]+c[d2]);
                    // if(c[6]==5){
                    //     cout<<i<<" "<<d1<<endl;
                    // }
                }

            }
        }
        for(int i = 1; i <=n; i++){
            if(c[i]==INT_MAX)c[i]=-1;
            cout<<c[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}