#include<bits/stdc++.h>
using namespace std;

int calc(int l,int r, int n, int k){
    int free = 0;
    
    if(l > 1 && r < n){
        free = max(0, r-l+1 - 2*k);
    }else if(l == 1 && r < n){
        free = max(0, r-l+1 - k);
    }else if(l != 1 && r == n){
        free = max(0, r-l+1 - k);
    }else{
        free=n;
    }
    return (free+k)/(k+1);
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        vector<int> pos;
        for(int i = 0; i < n; i++){
            if(s[i]=='0')pos.push_back(i+1);
        }
        // for(auto x: pos){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        int m = pos.size();
        int sum = 0;
        for(int i = 0; i < m; i++){
            int l = i;
            while(i+1<m && pos[i] + 1 == pos[i+1])
            {
                i++;
            }
            if(i>= l){
                int right = pos[i];
                int left = pos[l];
                // cout<<left<<" "<<right<<endl;
                sum+=calc(left,right,n,k);
            }
            
        }
        cout<<sum<<endl;
    }
    return 0;
}