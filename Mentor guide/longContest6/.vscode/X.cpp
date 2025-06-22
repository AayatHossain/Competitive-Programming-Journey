#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 160;
char a[N][N];

signed main(){
   
    int n,m;cin>>n>>m;
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            
        }
    }
    int moves = 0;
    int ci = 0, cj = 0;
    for(int i = 0; i < n; i++){
        if((i & 1)==0){
            for(int j = 0; j < m; j++){
                if(a[i][j]=='W'){
                    moves += abs(i-ci) + abs(j-cj);
                    ci = i; cj = j;
                }
            }
        }else{
            for(int j = m-1; j >= 0; j--){
                if(a[i][j]=='W'){
                    moves += abs(i-ci) + abs(j-cj);
                    ci = i; cj = j;
                }
            }
        }
    }
    cout<<moves<<endl;

}