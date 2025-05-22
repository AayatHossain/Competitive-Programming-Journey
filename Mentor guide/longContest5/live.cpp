#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int n, int m, int i, int j){
    int moves = 0;
    int right,left,up,down;
        while(n * m > 1){
            i = (n+1)/2;
            j = (m+1)/2;

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
            moves++;
        }
        return moves;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        int ans = LLONG_MAX;
        ans = min(ans, check(n-a+1, m, a, b));
        ans = min(ans, check(a, m, a, b));
        ans = min(ans, check(n, m-b+1, a, b));
        ans = min(ans, check(n, b, a, b));
        cout<<ans+1<<endl;
    }
    return 0;
}