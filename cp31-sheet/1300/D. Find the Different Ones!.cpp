#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        stack<pair<int,int>> s;
        vector<int> res(n,-1);
        s.push({a[0],1});
        for(int i=1;i<n;i++){
            
                while(!s.empty() && a[i]!=s.top().first){
                    int indx = s.top().second;
                    res[indx-1]=i+1;
                    s.pop();
                }
                s.push({a[i],i+1});
            
        }
        // for(auto x: res){
        //     cout<<x<<" ";
        // }
        int q; cin>>q;
        int l, r;
        while(q--){
            cin>>l>>r;
            int nr = res[l-1];
            if(nr <= r && nr != -1){
                cout<<l<<" "<<nr<<endl;
            }else{
                cout<<-1<<" "<<-1<<endl;
            }
        }
    }
    return 0;
}