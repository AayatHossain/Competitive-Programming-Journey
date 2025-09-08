#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+1;
vector<bool> p(N+1,true);
vector<int> pr;
void sieve(){
    p[0]=false; p[1]=false;
    for(int i = 2; i*i <= N; i++){
        if(p[i]){
            for(int j=i*i; j<=N; j+=i){
                p[j]=false;
            }
        }
    }
    for(int i = 2; i<= N; i++){
        if(p[i]){
            pr.push_back(i);
            // cout<<i<<" ";
        }
    }
}
int f(int n){
    int c = 0;
    int mx = LLONG_MIN;
    for(int v: pr){
        int x = v;
        mx = max(mx, v);
        if(n%v==0 && n > 1){
            while(n%v == 0 ){
                
                // if(v*v > n){
                //     break;
                // }
                c++;
                // if(c==7){
                //     cout<<n<<" "<<v<<endl;
                // }
                n/=v;
                // p[v]=false;
                v*=x;
                
            }
            // c--;
        }
    }
    if(n > mx){
        // cout<<n<<endl;
        c++;
    }
    return c;
}
signed main(){
    sieve();
    int n; cin>>n;
    
    cout<<f(n)<<endl;
    
    return 0;
}