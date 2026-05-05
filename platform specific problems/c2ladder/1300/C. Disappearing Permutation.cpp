#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> p(n+1);
        for(int i = 1; i <= n; i++)cin>>p[i];

        vector<int> d(n+1);
        for(int i = 1; i <= n; i++)cin>>d[i];

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            a[p[i]] = i;
        }
        // cout<<n<<endl;
        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        int ans = 0;
        for(int i = 1; i <= n; i++){
            int curr = d[i];
            
            if(a[curr]==curr){
                cout<<ans<<" ";
                continue;
            }

            int c = 0;
            while(a[curr] != curr){    
                c++;
                int curr2 = a[curr];
                a[curr] = curr;
                curr = curr2;
            }

            // a[curr] = curr;
            // c++;

            ans += c;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}