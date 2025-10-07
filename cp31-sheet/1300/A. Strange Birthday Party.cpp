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
        sort(c.begin(),c.end());
        int i = 0,j=0;

        int s = 0;
        while(i < n && j < m){
            // cout<<k[i]-1<<" "<<j<<" "<<s<<endl;
            if(k[i]-1 >=j){
                s+=c[j];
                i++; j++;
            }else{
                s+=c[k[i]-1];
                

                i++;
            }
        }
        while(i < n){
            s+=c[k[i]-1];
            i++;
        }
        cout<<s<<endl;


    }
    return 0;
}