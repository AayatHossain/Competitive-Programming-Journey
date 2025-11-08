#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1299709;
vector<bool> ip(N+1,true);
vector<int> p;
void sieve(){
    for(int i = 2; i*i<=N; i++){
        if(ip[i]){
            // p.push_back(i);
            for(int j = i*i; j<= N; j+=i){
                ip[j]=false;
            }
        }
    }
    for(int i = 2; i <= N; i++){
        if(ip[i]){
            p.push_back(i);
        }
    }
}
signed main(){
    sieve();
    int x;
    int m = p.size();
    while(cin>>x && x!=0){
        int indx = lower_bound(p.begin(),p.end(),x) - p.begin();
        int ans;
        // cout<<indx<<" "<<p[indx]<<endl;
        // cout<<m<<" "<<p[m-1]<<endl;
        if(p[indx]==x){
            ans = 0;
        }else if(p[indx]>x && indx-1 >= 0){
            ans = p[indx] - p[indx-1];
        }else if(indx>=m-1){
            ans = x - p[m-1];
        }else{
            ans = p[indx];
        }

        cout<<ans<<endl;
    }
    return 0;
}