#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
vector<bool>p(N+1,true);
vector<int>pc(N+1,0);
vector<vector<int>> ppref(11, vector<int>(N,0));
int a,b,n;

void sieve(){
    p[0]=false; p[1]=false;
    for(int i=2;i*i<=N;i++){
        if(p[i]){
            
            for(int j=i*i; j<=N; j+=i){
                p[j]=false;
            }
        }
    }
    
}
void sieve2(){

    for(int i=0; i<=N; i++){
        if(p[i]){
            pc[i]=1;
        }
    }


    for(int i=2;i+i<=N; i++){
        if(p[i]){
            for(int j=i+i; j<=N;j+=i){
                pc[j]++;
            }
        }
    }
    // for(int i = 0; i <= 10; i++){
    //     cout<<pc[i]<<" ";
    // }

    ppref[0][0]=1;

    for(int i=0; i<=10;i++){

        for(int j=1;j<=N;j++){
            if(pc[j]==i){
                ppref[i][j]=ppref[i][j-1]+1;
            }else{
                ppref[i][j]=ppref[i][j-1];
            }
        }
    }
    // for(int i=0; i<=10;i++){
        
    //     for(int j=0;j<=10;j++){
    //         cout<<ppref[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

signed main(){
    sieve();
    sieve2();
    int t; cin>>t;
    while(t--){
        cin>>a>>b>>n;
        cout<<ppref[n][b] - ppref[n][a-1]<<endl;
    }
    return 0;
}