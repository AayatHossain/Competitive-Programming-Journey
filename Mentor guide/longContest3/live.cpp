#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; char c; string s;cin>>n>>c>>s;
        char last, secLast;
        secLast = s[n-2];
        last = s[n-1];
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != c){count++;}
        }
        if(count==0){
            cout<<0<<endl;
        }else{
            vector<int> ans;
            bool ok = false;
            for(int i = 2; i <= n; i++){
                ok = false;
                for(int j = i; j <= n; j+=i ){
                    if(s[j-1] == c){
                        ok = true;
                    }else{
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    ans.push_back(i);
                    break;
                }
            }
            if(!ok){
                ans.push_back(n-1);
                ans.push_back(n);
            }
            cout<<ans.size()<<endl;
            for(auto x: ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }

    }
}