#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        deque<int> dq;
        dq.push_back(a[0]);
        for(int i = 1; i < n; i++){
            if(dq.front() > a[i]){
                dq.push_front(a[i]);
            }else{
                dq.push_back(a[i]);
            }
        }
        while(!dq.empty()){
            cout<<dq.front()<<" ";
            dq.pop_front();
        }
        cout<<endl;
    }
    return 0;
}