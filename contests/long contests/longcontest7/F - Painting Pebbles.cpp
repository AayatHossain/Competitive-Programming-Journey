#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    int mx = -1;
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    if(mx>=k-1 || n==1){
        cout<<"YES"<<endl;
        for(int i =0; i < n; i++){
            int v = a[i];
            int c = 1;
            while(v>0){
                if(c==k){
                    cout<<c<<" ";
                    c = 1;
                    v--;
                    continue;
                }
                cout<<c<<" ";
                c++;
                v--;
            }
            cout<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}