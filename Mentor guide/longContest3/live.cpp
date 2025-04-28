#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;cin>>n;
        string s; cin>>s;
        int z = 0;
        for(int i = 0; i < n; i++){
            if(s[i]=='0'){
                z++;
            }
        }
        if(z==1){
            cout<<"BOB"<<endl;
        }else if(z % 4 == 0){
            cout<<"DRAW"<<endl;
        }else if(z % 2 == 0){
            cout<<"BOB"<<endl;
        }else{
            cout<<"ALICE"<<endl;
        }
    }
}