#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    map<int, vector<pair<int,int>>> m;
    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            m[a[i]+a[j]].push_back({i,j});
        }
    }
    for(int i = 0; i < n; i++){
        for(int j=i+3; j < n;j++){
            if(m.find(k - (a[i]+a[j])) != m.end()){
                for(auto p: m[k-(a[i]+a[j])]){
                    int k = p.first;
                    int l = p.second;
                    if(k>i && l < j){
                        cout<<i+1<<" "<<k+1<<" "<<l+1<<" "<<j+1<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    

    return 0;
}