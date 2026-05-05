#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        n+=2;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int s1=0, s2=0, s=0;
        for(int i = 0; i < n; i++){
            if(i != n-2){
                s1+=a[i];
            }
            if(i!=n-1){
                s2+=a[i];
            }
            s+=a[i];
        }
        // cout<<s1<<" "<<s2<<" "<<s<<endl;
        int f = 0;
        int v = -1;
        for(int i = 0; i < n; i++){
            if(i!=n-2){
                int ns = s1 - a[i];
                if(ns==a[n-2]){
                    v = a[i];
                    a[i] = -1;
                    f = 1;
                    a[n-2] = -1;
                    break;

                }
            }
            if(i!=n-1){
                int ns = s2 - a[i];
                if(ns==a[n-1]){
                    v = a[i];
                    a[i] = -1;
                    f = 1;
                    a[n-1] = -1;
                    break;

                }
            }
        }
        if(f){
            for(auto x: a){
                if(x != -1){
                    cout<<x<<" ";
                }
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }

    }
    return 0;
}