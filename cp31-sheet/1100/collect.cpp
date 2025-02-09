#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<pair<long long,long long>> a;
        for(long long i = 0; i < n; i++){
            long long m;
            cin>>m;
            a.push_back(make_pair(m, i));
        }
        sort(a.begin(), a.end());
        vector<long long> prefix(n);
        prefix[0] = a[0].first;
        for(long long i = 1; i < n; i++){
            pair<long long, long long> p = a[i];
            prefix[i] = prefix[i-1] + p.first;
        }
         vector<pair<long long,long long>> ans(n);
        
         for(long long i = n-1; i >= 0; i--){
            pair<long long, long long> p = a[i];
            if(i==n-1){
                ans[i] = make_pair(a[i].second, n-1);
                continue;
            }else{
                if(prefix[i] >= a[i+1].first){
                    ans[i] = make_pair(a[i].second, ans[i+1].second);
                }else{
                    ans[i] = make_pair(a[i].second, i);
                }
            }
         }
         sort(ans.begin(), ans.end());
         for(long long i = 0; i < n; i++){
            cout<<ans[i].second<<" ";
         }
         cout<<endl;

    }
    return 0;
}