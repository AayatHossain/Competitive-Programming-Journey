#include<bits/stdc++.h>
using namespace std;
signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    int c = 1;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        } 
        vector<int> pmn(n+1,INT_MAX);
        vector<int> pmx(n+1,INT_MIN);

        vector<int> smn(n+1,INT_MAX);
        vector<int> smx(n+1,INT_MIN);

        pmn[1] = a[1];
        pmx[1] = a[1];

        for(int i = 2; i <= n; i++){
            pmn[i] = min(pmn[i-1],a[i]);
            pmx[i] = max(pmx[i-1],a[i]);
        }

        smn[n] = a[n];
        smx[n] = a[n];
        for(int i = n-1; i >= 1; i--){
            smn[i] = min(smn[i+1],a[i]);
            smx[i] = max(smx[i+1],a[i]);
        }

        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(i>1 && i < n){
                int valid = pmx[i-1] < a[i] && smn[i+1] > a[i] && smx[i+1] > a[i];
                if(valid){
                    ans = i; break;
                }
            }else if(i==1){
                int valid = smn[i+1] > a[i] && smx[i+1] > a[i];
                if(valid){
                    ans = i; break;
                }
            }else{
                int valid = pmx[i-1] < a[i];
                if(valid){
                    ans = i; break;
                }
            }
        }
        if(ans==-1){
            cout<<"Case "<<c<<": "<<"Humanity is doomed!"<<'\n';
        }else{
            cout<<"Case "<<c<<": "<<ans<<'\n';
        }
        c++;
    }
    return 0;
}

