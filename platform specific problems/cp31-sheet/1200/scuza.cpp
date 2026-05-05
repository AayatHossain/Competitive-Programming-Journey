#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long p,q;
        cin>>p>>q;
        vector<long long> a(p);
        vector<long long> b(q);
        for(long long i = 0; i < p; i++){
            cin>>a[i];
        }
        for(long long i = 0; i < q; i++){
            cin>>b[i];
        }
        vector<long long> pref(p);
        pref[0] = a[0];
        for(long long i = 1; i < p; i++){
            pref[i] = pref[i-1] + a[i];
        }
        vector<long long> mV(p);
        mV[0] = a[0];
        for(long long i = 1; i < p; i++){
            mV[i] = max(mV[i-1], a[i]);
        }
        for(long long i = 0; i < q; i++){
            auto it = upper_bound(mV.begin(), mV.end(), b[i]);
            long long index = it - mV.begin();
            index--;
            long long ans;
            if(index==-1){
                ans = 0;
            }else{
                ans = pref[index];
            }
            cout<<ans<<" "; 
        }
        cout<<endl;
    }
    return 0;
}