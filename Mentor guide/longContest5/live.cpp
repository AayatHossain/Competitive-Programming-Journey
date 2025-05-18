#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        int moves = 0;
        int i = a, j = b;
        int right,left,up,down;
        while(!(n==1 && m==1)){
            right = (m-j)*n;
            left = (j-1)*n;
            up = (i-1)*m;
            down = (n-i)*m;
            vector<pair<int,char>> v(4);
            v[0] = {right,'r'};
            v[1] = {left,'l'};
            v[2] = {up,'u'};
            v[3] = {down,'d'};
            sort(v.begin(), v.end());
            auto x = v[3];
            char c = x.second;
            if(c=='u'){
                n=n-i+1;
            }else if(c=='d'){
                n=i;
            }else if(c=='l'){
                m=m-j+1;
            }else{
                m=j;
            }
            i = n/2 + 1;
            j = m/2 + 1;
            moves++;
        }
        cout<<moves<<endl;
    }
    return 0;
}