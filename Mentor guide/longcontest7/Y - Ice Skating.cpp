#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<pair<int,int>> a(n);
    for(int i = 0;  i < n; i++){
        int x,y;cin>>x>>y;
        a[i] = {x, y};
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            
            int x1 = abs(a[i].first);
            int x2 = abs(a[j].first);
            int y1 = abs(a[i].second);
            int y2 = abs(a[j].second);
            cout<<x1<<" "<<y1<<endl;
            cout<<x2<<" "<<y2<<endl;
            if(x1!=x2 && y1!=y2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}