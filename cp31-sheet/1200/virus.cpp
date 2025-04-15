#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> a(m);
        vector<int> b;
        for(int i = 0; i < m; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        for(int i = 1; i < m; i++){ 
            b.push_back(a[i] - a[i-1] - 1);
        }
        b.push_back(n - a[m-1] + a[0] - 1);
        sort(b.rbegin(), b.rend());
        // for(int i = 0; i < b.size(); i++){
        //     cout<<b[i]<<" ";
        // }
        int lost = 0; int saved = 0;
        for(int i = 0; i < b.size(); i++){
            int left = b[i] - lost;
            if(left == 1){
                saved++;
            }else if(left >= 2){
                saved += (left - 1);
            }
            lost += 4;
        }
        cout<<n - saved<<endl;
    }
    return 0;
}