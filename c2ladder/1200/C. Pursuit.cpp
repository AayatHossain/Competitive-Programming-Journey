#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        vector<int> b(n+1);
        vector<int> pa(n+1);
        vector<int> pb(n+1);
        pa[0] = 0;
        pb[0] = 0;
        a[0] = 0;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
           
        }
        for(int i = 1; i <= n; i++){
            cin>>b[i];
            
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        for(int i = 1; i <= n; i++){
            pb[i] = pb[i-1] + b[i];
            pa[i] = pa[i-1] + a[i];
        }

        // for(auto x: pa){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: pb){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        int m = n;
        int moves = 0;
        while(1){
            int items = m - m/4;
            int bf = m-items;
            int v1 = pa[m] - pa[bf];
            // if(m==4){
            // cout<<m<<" "<<bf<<endl;
            // }
            int v2;
            if(items >= n){
                v2 = pb[n];
            } else{
                int indx = n-items;
                v2 = pb[n] - pb[indx];
            }
            // cout<<v1<<" "<<v2<<endl;
            if(v1 >= v2){
                break;
            }else{
                moves++;
                m++;
                a.push_back(100);
                pa.push_back(pa[m-1]+100);
            }
        }
        cout<<moves<<endl;
    }
    return 0;
}