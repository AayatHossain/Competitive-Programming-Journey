#include<bits/stdc++.h>
using namespace std;
vector<bool> primes(1001, true);

void sieve(){
    primes[0] = false;
    primes[1] = false;
    for(int i = 2; i*i <= 1001; i++){
        if(primes[i]){
            for(int j = i*i; j <= 1001; j+=i){
                primes[j] = false;
            }
        }
    }
}

int bfs(int s, int t){
    queue<int> q;
    vector<bool> vis(1001,false);
    q.push(s);
    vis[s] = true;
    int moves = 0;
    while(!q.empty()){
        int size = q.size();
        // vector<int> l;
        for(int i = 0; i < size; i++){
            int x = q.front();
            // l.push_back(x);

            q.pop();
            // cout<<x<<endl;
            if(x==t){
                return moves;
            }
            vector<int>pF;
            for(int i = 1; i < x; i++){
                if(x % i == 0 && primes[i]){
                    pF.push_back(i);
                }
            }

            for(auto add: pF){
                int nX = x + add;
                
                int valid = nX <= t && vis[nX]==false;
                if(valid){
                    q.push(nX);
                    vis[nX] = true;
                }
            }
        }
        
        moves++;
    }
    return -1;
}


signed main(){
    int t;cin>>t;
    sieve();
    int c = 1;
    while(t--){
        int s,t;cin>>s>>t;
        int moves = bfs(s,t);
        cout<<"Case "<<c<<": "<<moves<<endl;
        c++;
        
    }
    return 0;
}