#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+1;
vector<int> a(N);
int n;
bool ok(int m){

    vector<bool> v(n+1,false);
    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(a[i]<=m){
            v[i]=true;
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        int valid1 = u>1 && !v[u-1] && abs(a[u]-a[u-1]) <= m;
        int valid2 = u<n && !v[u+1] && abs(a[u]-a[u+1]) <= m;
        if(valid1){
            q.push(u-1);
            v[u-1]=true;
        }
        if(valid2){
            q.push(u+1);
            v[u+1]=true;
        }
        
    }
    for(int i = 1; i<=n; i++){
        if(!v[i]){
            return false;
        }
    }
    return true;
}

signed main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   
    
    int t; cin>>t;
    int c = 1;
    while(t--){
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        int l = 0, r = 1e9;
        int m;
        while(l+1<r){
            m = l+(r-l)/2;
            if(ok(m)){
                r = m;
            }else{
                l = m;
            }
        }

        cout<<"Case #"<<c<<": "<<r<<endl;
        c++;
    }
    
  
    
    return 0;
}