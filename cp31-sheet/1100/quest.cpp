#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        vector<int> prefixSum(n);
        vector<int> prefixMax(n);
        prefixSum[0] = a[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + a[i];
        }
        prefixMax[0] = b[0];
        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i-1], b[i]);
        }
        // for(int i = 0; i < n; i++){
        //     cout<<prefixSum[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < n; i++){
        //     cout<<prefixMax[i]<<" ";
        // }
        int maxV  = -1;
        int start = k;
        if(k > n){
            start=n;
        }
        for(int i = start-1; i >= 0; i--){
            int movesLeft = k-(i+1);
            int total = prefixSum[i];
            total += movesLeft*prefixMax[i];
            maxV = max(total, maxV);
        }
        
        cout<<maxV<<endl;
    }
    return 0;
}