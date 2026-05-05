#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    set<int> s;
    int j = 0;
    int ans = INT_MIN;
    
    for(int i = 0; i < n; i++){
        if(s.find(a[i])==s.end()){
            s.insert(a[i]);
            ans = max(ans, i-j+1);
        }else{
            while(s.find(a[i])!=s.end()){
                s.erase(a[j]);
                j++;
            }
            s.insert(a[i]);
            ans = max(ans, i-j+1);

        }
    }
    cout<<ans<<endl;
}