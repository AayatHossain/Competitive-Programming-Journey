#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        string p,s; cin>>p>>s;
        int n = p.size();
        int m = s.size();
        vector<pair<char,int>> a; 
        vector<pair<char,int>> b;
        for(int i = 0; i < n; i++){
            char c = p[i];
            int j = i;
            int cnt = 0;
            while(j < n-1 && p[j]==p[j+1]){
                j++;
            }
            cnt = j - i + 1;
            a.push_back({c,cnt});
            i = j;
        } 
        for(int i = 0; i < m; i++){
            char c = s[i];
            int j = i;
            int cnt = 0;
            while(j < m-1 && s[j]==s[j+1]){
                j++;
            }
            cnt = j-i + 1;
            b.push_back({c,cnt});
            i = j;
        } 
        // for(auto x: b){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        int i = 0;
        int f = 1;
        while(i < a.size()){
            if(i == b.size()){
                break;
            }
            if(a[i].first==b[i].first && b[i].second >= a[i].second && b[i].second <= 2*a[i].second ){
                i++;
            }else{
                f=0;
                break;
            }
        }
        if(i < a.size() || i < b.size()){
            f=0;
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}