#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        vector<int> sorted(n);
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            a[i] = abs(x); sorted[i] = abs(x);
        }
        
        sort(sorted.begin(), sorted.end());
        if(n==1){
            cout<<"YES"<<endl;
            continue;
        }
        if(n > 2 && a[0]==sorted[n-1]){
            cout<<"NO"<<endl;
            continue;
        }

        int val = a[0];
        int index = -1;
        for(int i = 0; i < n; i++){
            if(sorted[i]==val){
                index = i+1; break;
            }
        }
        int right = n - index;
        int req;
        if(n&1){req = n/2;}else{req = n/2 - 1;};
        if(right >= req){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}