#include <bits/stdc++.h>
using namespace std;
#define int long long
string t;
int n;
const int N = 1e6 + 1;
int dp[N][3];
int f(int i, string temp)
{
    if (temp == "wow")
        return 1;
    if (i == n)
        return 0;

    int state = -1;
    if(temp==""){
        state = 0;
    }
    else if(temp=="w"){
        state = 1;
    }else if(temp == "wo"){
        state = 2;
    }

    if(dp[i][state] != -1)return dp[i][state];
    int ways = -1;
    
    if (t[i] == 'w')
    {
        if (temp == "")
        {
            ways = f(i + 1, temp + 'w');
            ways += f(i + 1, temp);
            
        }
        else if (temp == "wo")
        {
            ways = f(i + 1, temp + 'w');
            ways += f(i + 1, temp);
            
        }
    }
    else
    {
        if(temp=="w"){
            ways = f(i + 1, temp + 'o');
            ways += f(i + 1, temp);
            
        }
    }
    if(ways==-1){
        ways = f(i+1, temp);
    }
    return dp[i][state] = ways;
}
signed main()
{
    string s;
    cin >> s;
    memset(dp, -1, sizeof dp);

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == 'v' && s[i - 1] == 'v')
        {
            t += 'w';
        }
        else if (s[i] == 'o')
        {
            t += 'o';
        }
    }
    n = t.size();
    int ans = f(0, "");
    cout << ans << endl;
    return 0;
}