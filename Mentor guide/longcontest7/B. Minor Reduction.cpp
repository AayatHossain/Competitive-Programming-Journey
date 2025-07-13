#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int f = 0;
        for (int i = s.size() - 2; i >= 0; i--)
        {
            int v1 = s[i] - '0';
            int v2 = s[i + 1] - '0';
            int v = v1 + v2;
            if (v >= 10)
            {
                s[i + 1] = v % 10 + '0';
                v /= 10;
                s[i] = v + '0';
                f = 1;
                break;
            }
        }
        if (!f)
        {
            int v1 = s[0] - '0';
            int v2 = s[1] - '0';
            int v = v1 + v2;
            s[1] = v % 10 + '0';
            
        }
        int num = 0;
       
        int start = 0;
        if(!f){
            start = 1;
        }
        for(int i = start; i < s.size(); i++){
            cout<<s[i];
        }
        cout<<endl;
    }
}