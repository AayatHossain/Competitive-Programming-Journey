#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,m,i,j,d;
        cin>>n>>m>>i>>j>>d;
        int left = j-d;
        int right = j+d;
        int up = i - d;
        int bot = i+d;
        if((left >1 && bot <n)||(right <m && up > 1)){
            cout<<(n-1) + (m-1)<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}