#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 15;
vector<int> a(N);
int dp[15][1<<15];
int n;
int b[15][15];

int countShots(int i, int j){
    int dmg = b[i][j];
    int targetdmg=a[j];
            // cout<<i<<" "<<j<<" "<<a[j]<<" "<<shots<<endl;
            // cout<<i<<" "<<j<<" "<<dmg<<" "<<targetdmg<<endl;

    if(dmg==0){
        return targetdmg;
    }else{
        // cout<<(targetdmg/dmg)+(targetdmg%dmg!=0)<<endl;
        return (targetdmg/dmg)+(targetdmg%dmg!=0);
    }
}

int f(int i, int mask){
    if((mask==((1<<n)-1)))return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans = LLONG_MAX;
    for(int j = 0; j < n; j++){
        if(((mask & (1<<j))==0) && i!=j){
            int shots = countShots(i,j);
            ans = min(ans, shots + f(j,(mask | (1<<j))));
        }
    }
    return dp[i][mask] = ans;
}

signed main(){
    int t; cin>>t;
    int c = 1;
    while(t--){
        string s; getline(cin,s);
    // cin.ignore(); 
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
           
                cin>>s;
                for(int k = 0; k < s.size();k++){
                    b[i][k]=s[k]-'0';
                }
            
        }
        
        // for(int i = 0; i < n; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<b[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        memset(dp, -1, sizeof dp);
        int ans = LLONG_MAX;
        for(int i = 0; i < n; i++){
            int mask = (0 | (1<<i));
            ans = min(ans, a[i]+f(i,mask));
            // cout<<ans<<endl;
        }
        cout<<"Case "<<c<<": "<<ans<<endl;
        c++;
    }
    return 0;
}