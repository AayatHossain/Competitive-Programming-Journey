#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n, k; cin>>n>>k;
    int a,b,c,x; cin>>x>>a>>b>>c;
    vector<int> arr(n+1);
    arr[1] = x;
    for(int i = 2; i <= n; i++){   
        arr[i] = (a*arr[i-1] + b)%c;
    }
    // for(auto x: arr){
    //     cout<<x<<" ";
    // }
    deque<int> dq;
    for(int i = 1; i <= k; i++){
        if(dq.empty()){
            dq.push_back(arr[i]);
        }else if(dq.back() >= arr[i]){
            while(dq.back() >= arr[i]){
                dq.pop_back();
            }
        }
    }
    return 0;
}