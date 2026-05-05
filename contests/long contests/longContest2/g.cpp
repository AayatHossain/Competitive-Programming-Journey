#include <bits/stdc++.h>
using namespace std;
#define int long long

int find(vector<pair<int,int>> &b, int n, int x){
    int l = -1, r = n;
    int mid;
    while(r > l + 1){
        mid = l + (r-l)/2;
        int left = b[mid].first;
        int right = b[mid].second;
        if((x > left && x > right) || (x >=left && x <= right)){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];

    vector<pair<int,int>>b;
    b.push_back(make_pair(1, a[0]));
    for(int i = 1; i < n; i++){
        pair<int,int> prev = b[i-1];
        b.push_back(make_pair(prev.second+1, prev.second + a[i]));
    }
    // for(auto x: b){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }


    int m;cin>>m;
    for(int i = 0; i < m; i++){
        int x;cin>>x;
        int indx = find(b,n,x);
        cout<<indx+1<<endl;
    }
    return 0;
}