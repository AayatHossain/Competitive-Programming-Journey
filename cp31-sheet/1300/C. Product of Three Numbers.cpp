#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> primes;
vector<bool> p(N,true);

void sieve(){
    for(int i = 2; i <= N; i++){
        if(p[i]){
            for(int j = i+i; j<=N; j+=i){
                p[j]=false;
            }
        }
    }
    for(int i = 2; i <= N; i++){
        if(p[i]){
            primes.push_back(i);
        }
    }

}
signed main(){
    // for(int i = 1; i <= 100; i++){
    //     for(int j = 2; j <= 100; j++){
    //         for(int k =2; k <= 100; k++){
    //             for(int l = 2; l <= 100; l++){
    //                 if(j*k*l==i && j!=k && k!=l && j!=l){
    //                     cout<<j<<" "<<k<<" "<<l<<" "<<i<<endl;
    //                 }
    //             }
    //         }
    //     }
    // }
    sieve();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int,int> m;
        for(auto x: primes){
            while(n > 1 && n%x==0){
                // cout<<"BEfore"<<" "<<n<<endl;
                m[x]++;
                n/=x;
                // cout<<"after"<<" "<<n<<endl;

            }
        }
        if(n > 1){
            m[n]++;
        }
        int f = 0;
        int s = 0;
        if(m.size() >= 3){
            f=1;
        }else{
            
            for(auto x: m){
                s+=x.second;
            }
            if(s>=4){
                f=1;
            }
        }
        // cout<<m.size()<<endl;
        // cout<<s<<endl;

        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}