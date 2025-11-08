#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,m;
    while(cin>>n>>m && n!=0 && m!=0){
        map<int,int> M;
        int s = 0;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            M[x]++;
            s+=x;
        }
        for(int i = 0; i < m; i++){
            int x; cin>>x;
            if(M[x]==0){
                s+=x;
            }else{
                M[x]--;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}