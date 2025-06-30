#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main()
{
    string n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int n1, n2;
    n1 = 0;
    n2  = 0;
    int m = 10;
    int flag = 0;
    for(int i = 0; i < n.size(); i++){
        n1 = (n1*m + (n[i] -'0'))%mod;

        if(n1 % a == 0){
            if(n[i+1]=='0'){
                continue;
            }
            int m2 = 10;
            for(int j = i+1; j < n.size(); j++){
                n2 = (n2*m2 + (n[j] -'0'))%mod;
               
            }
            if(n2 % b == 0 && n2 != 0){
                cout<<"YES"<<endl;
                cout<<n1<<endl;
                cout<<n2<<endl;
                flag = 1;
                break;
            }
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
    }
    

    return 0;
}