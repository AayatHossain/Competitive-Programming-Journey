#include <bits/stdc++.h>
using namespace std;
#define int long long
void print(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void print(vector<vector<int>> &a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void print(set<int> &a)
{
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}
void print(map<int, int> &a)
{
    for (auto x : a)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
}


bool func1(string s, int n){
    if(n >= 5){
        for(int i = 2; i < n-2; i++){
            string t;
            t+=s[i-2];
            t+=s[i-1];
            t+=s[i];
            t+=s[i+1];
            t+=s[i+2];
            if(t=="11011"){
                return false;
            }
        }
        return true;

    }else{
        return true;
    }
}

bool func2(string s, int n){
    if(n >= 4){
            string t;
            t+=s[0];
            t+=s[1];
            t+=s[2];
            t+=s[3];
            if(t=="1011"){
                return false;
            }else{
                return true;
            }
           

    }else{
        return true;
    }
}


bool func3(string s, int n){
    if(n >= 4){
            string t;
            t+=s[n-4];
            t+=s[n-3];
            t+=s[n-2];
            t+=s[n-1];
            if(t=="1101"){
                return false;
            }else{
                return true;
            }
           

    }else{
        return true;
    }
}

bool func4(string s, int n){
    if(n >= 8){
        for(int i =0;i<=n-8;i++){
            if(s.substr(i,8)=="10101011"){
                return false;
            }
        }
        return true;
    }else{
        return true;
    }
    
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n; cin>>n;
        string s; cin>>s;
        if(n==1){
            cout<<"YES"<<endl;
            continue;
        }
        vector<vector<bool>> dp(n, vector<bool>(2,false));
        int l = 0, r = 1;
        if(s[0]=='0'){
            dp[0][l] = true;
            dp[0][r] = true;
        }
        if(s[n-1]=='0'){
            dp[n-1][l] = true;
            dp[n-1][r] = true;
        }

        if(s[0]=='1'){
            dp[0][l] = true;
            dp[0][r] = false;
        }
        if(s[n-1]=='0'){
            dp[n-1][l] = false;
            dp[n-1][r] = true;
        }
        int f = 1;
        for(int i = 1; i < n-1; i++){
            if(s[i]==s[i-1] && s[i]=='1'){
                if(i-2 >= 0 && dp[i-2][l]==0 && dp[i-1][r]==1){
                    f = 0;
                    break;
                }
                dp[i][l]=false;
                dp[i][r]=false;
            }else if(s[i]=='1'){
                dp[i][l]=dp[i-1][l];
                dp[i][r]=dp[i-1][r];
            }

            if(s[i]=='0'){
                if(dp[i-1][l]){
                    dp[i][r]=true;
                }
                if(dp[i-1][r]){
                    dp[i][l]=true;
                }
                if(!dp[i-1][l] && !dp[i-1][r]){
                    dp[i][r]=true;
                    dp[i][l]=false;
                }
            }
            
        }
        if(!f){
            cout<<"NO"<<endl;
            continue;
        }
        int f1 = 1;
        if(s[n-1]=='1' && !dp[n-2][l]){
            f1 = 0;
        }
        
        // for(int i = 0; i < n; i++){
        //     cout<<dp[i][l]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < n; i++){
        //     cout<<dp[i][r]<<" ";
        // }
        // cout<<endl;
        
        if(f1 ){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}