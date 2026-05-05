#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> k(n);
        vector<int> c(m);
        for(int i = 0; i < n; i++)cin>>k[i];
        for(int i = 0; i < m; i++)cin>>c[i];

        sort(k.rbegin(),k.rend());
        int j = 0;
        int s = 0;
        for(int i = 0; i < n; i++){
            if(k[i]-1 >=j){
                s+=c[j];
                j++;
            }else{
                s+=c[k[i]-1];
            }
        }
        cout<<s<<endl;




    }
    return 0;
}