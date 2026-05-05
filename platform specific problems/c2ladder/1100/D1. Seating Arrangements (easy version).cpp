#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> a(m);
        for(int i  =0; i < m; i++){
            cin>>a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        map<int, vector<int>> mm;
        for(int i = 0; i < m; i++){
            mm[b[i]].push_back(i);
        }
        // for(auto x: mm){
        //     cout<<x.first<<": ";
        //     for(auto y: x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        int c = 0;
        vector<int> res(m,-1);
        for(int i = 0; i < m; i++){
            int index = mm[a[i]].at(mm[a[i]].size()-1);
            for(int j = 0; j < index; j++){
                if(res[j]!=-1)c++;
            }
            res[index] = a[i];
            mm[a[i]].pop_back();
            // cout<<index<<" "<<c<<endl;
        }
        // for(auto x: res)cout<<x<<" ";
        // cout<<endl;
        cout<<c<<endl;
    }
    return 0;
}