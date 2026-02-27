#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        string s; cin>>s;
        int n = s.size();
        queue<pair<int,int>>q;
        int l = -1, r = -1;
        for(int i = 0; i < n; i++){
            l=i;
            while(i < n && s[i]=='1'){
                i++;
            }
            r=i-1;
            
            if(r>=l){
                q.push({l+1,r+1});
            }
            
            
        }
      
        if(q.empty()){
            cout<<0<<endl;
            continue;
        }
        int cnt = 1;
        int extra = 0;
        l = q.front().second;
        r=-1;
        q.pop();
        while(!q.empty()){
            int r = q.front().first;
            int gap = r-l-1;
            if(b*gap <= a){
                extra += b*gap;
            }else{
                cnt++;
            }
            l = q.front().second;
            q.pop();
        }
        cout<<cnt*a + extra<<endl;
    }
    return 0;
}