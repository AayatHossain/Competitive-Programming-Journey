#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n, m;cin>>n>>m;
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> change;
        for(int i = 0; i < n; i++){
            int x;cin>>x;
            q.push(x);
        }
        for(int i = 0; i < m; i++){
            int x;cin>>x;
            change.push_back(x);
        }
        // sort(change.begin(), change.end());
        int i = 0;
        while(i < m){
            q.pop();
            q.push(change[i]);
            i++;
        }
        int sum = 0;
        while(!q.empty()){
            sum += q.top();
            q.pop();
        }
        cout<<sum<<endl;
    }
    return 0;
}