#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    int it = 1;
    while(t--){
        string str;
        getline(cin, str);
        int n;cin>>n;
        vector<int> s(n+1, 0);
        vector<int> e(n+1, 0);
        int clock = 0;
        int total = 0;
        for(int i = 0; i < n; i++){
            int u,v,w;
            cin>>u>>v>>w;
            if(s[u] || e[v]){
                s[v] = e[u] = 1;
                clock += w;
            }else{
                s[u] = e[v] = 1; 
            }
            total += w;
        }
        cout<<"Case "<<it<<": "<<min(clock, total - clock)<<endl;
        it++;
    }
    return 0;
}