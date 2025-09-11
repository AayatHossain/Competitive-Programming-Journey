#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
          string s;
        cin >> s;
        n=s.size();
        set<char> se;
        int k=0;
        for(int i=0;i<n;i++){
            if(se.find(s[i])==se.end()){
                se.insert(s[i]);
            }else{
                k=i;
                break;
            }
        }
        int f =1;
        for(int i=k;i<n;i++){
            if(s[i]!=s[i-k]){
                f=0;
                break;
            }
        }
        // cout<<k<<endl;
        cout<< (f? "Yes" : "No")<<endl;
    
    }

    return 0;
}