#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m; cin>>n>>m;
    char a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }


    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    set<string> s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i+(m-1)< n && j+m-1 < n){
                string str;
                for(int k = i; k <= i+m-1; k++){
                    for(int l = j; l <= j+m-1; l++){
                        if(a[k][l]=='#'){
                            str+='B';
                        }else{
                            str+='W';
                        }
                    }
                }
                // if(str =="WBBB"){
                //     cout<<i<<" "<<j<<endl;
                // }
                s.insert(str);
            }
        }
    }
    cout<<s.size()<<endl;
    // for(auto x: s){
    //     cout<<x<<endl;
    // }
    
    return 0;
}