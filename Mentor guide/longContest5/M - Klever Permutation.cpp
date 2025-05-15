#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int large = n;
        int small = 1;
        vector<int> ans(n+1);
        set<int> s;
        int i = 1;
        while(s.size() != n){
            if(i % 2 != 0){
                int j = i;
                while(j <= n){
                    s.insert(small);
                    ans[j] = small;
                    small++;
                    j+=k;
                }
            }else{
                int j = i;
                while(j <= n){
                    s.insert(large);
                    ans[j] = large;
                    large--;
                    j+=k;
                }
            }
            i++;
        }
        for(int i = 1; i <= n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}