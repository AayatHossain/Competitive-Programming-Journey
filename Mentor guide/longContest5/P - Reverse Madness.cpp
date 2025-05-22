#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        vector<int>a(k);
        vector<int>b(k);
        for(int i = 0; i < k; i++){
            cin>>a[i];
            a[i]--;
        }
        for(int i = 0; i < k; i++){
            cin>>b[i];
            b[i]--;
        }
        int q;cin>>q;
        vector<int> count(n, 0);
        for(int i = 0; i < q; i++){
            int x; cin>>x;
            count[x-1]++;
        }
        string ans = "";
        for(int i = 0; i < k; i++){
            string sub = s.substr(a[i], b[i] - a[i] + 1);
            int left = a[i];
            int right = b[i];
            int sum = 0;
            for(int j = left; j <= (left+right)/2; j++){
                sum += count[j] + count[right-j+left];
                if(sum%2){
                    swap(sub[j-left], sub[right - j]);
                }
            } 
            ans += sub;
        }
        cout<<ans<<endl;
    }
    return 0;
}