#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 51;
int dp[N][N][N];
string s;
int n;
bool isVowel(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int f(int i, int v, int c)
{
    if (v == 3 || c == 5)
        return 2;

    if (i == n)
        return 1;

    if (dp[i][v][c] != -1)
        return dp[i][v][c];

    if (isVowel(s[i]))
    {
        return dp[i][v][c] = f(i + 1, v + 1, 0);
    }
    else if (s[i] == '?')
    {
        int p1 = f(i + 1, v + 1, 0);
        int p2 = f(i + 1, 0, c + 1);
        
        if(p1==p2){
            return dp[i][v][c] = p1;
        }else if(p1==0 || p2 == 0){
            return dp[i][v][c] = 0;
        }else{
            return dp[i][v][c] = 0;
        }
    }
    else
    {
        return dp[i][v][c] = f(i + 1, 0, c + 1);
    }
}
signed main()
{
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        cin >> s;
        n = s.size();
        memset(dp, -1, sizeof dp);
        int ans = f(0, 0, 0);
        if (ans == 0)
        {
            cout << "Case " << c << ": " << "MIXED" << endl;
            c++;
        }
        else if (ans == 1)
        {
            cout << "Case " << c << ": " << "GOOD" << endl;
            c++;
        }
        else
        {
            cout << "Case " << c << ": " << "BAD" << endl;
            c++;
        }
    }
    return 0;
}