#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        multiset<int> ms;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            ms.insert(a[i]);
        }
        int mn1 = LLONG_MAX;
        int mn2 = LLONG_MAX;

        mn1 = min(mn1, a[n-1]);
        for(int i = 0; i < n-1; i++){
            mn1 = min(mn1, a[i]);
            for(int j = i+1; j < n; j++){
                int diff = abs(a[i]-a[j]);
                mn1 = min(mn1, diff);


                auto it = ms.lower_bound(diff);
                if(it != ms.end()){
                    int val = *it;
                    mn2 = min(mn2, abs(diff - val));
                }
                if(it != ms.begin()){
                    it--;
                    int val = *it;
                    mn2 = min(mn2, abs(diff - val));
                }
                

            }
        }
        if(k >= 3){
            cout<<0<<endl;
        }else if(k == 2){
            cout<<min(mn1,mn2)<<endl;
        }else{
            cout<<mn1<<endl;
        }
    }
    return 0;
}