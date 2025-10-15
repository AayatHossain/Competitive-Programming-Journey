#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        map<int,int> cnt1;
        map<int,int> cnt2;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            cnt1[a[i]]++;
        }
        int f = 1;
        for(int i = 0; i < n; i++){
            if(cnt1[a[i]]%k != 0){
                f=0;
                break;
            }
        }
        if(!f){
            cout<<0<<'\n'; continue;
        }
        int ans = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            cnt2[a[i]]++;
            while(j <= i && cnt2[a[i]] > cnt1[a[i]]/k ){
                cnt2[a[j]]--;
                j++;
            }
            ans += i-j+1;
        }
        cout<<ans<<'\n';

    }
    return 0;
}