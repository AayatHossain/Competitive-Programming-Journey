#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int f = 0;
        for (int i = 0; i < n - 1; i++)
        {
            string t;
            t += s[i];
            t += s[i + 1];
            // cout<<t<<endl;
            if (t == "01" || t== "10")
            {
                f = 1;
                break;
            }
        }
        if (!f)
        {
            cout << s << endl;
        }
        else
        {
            // cout<<f<<endl;
            string u;
            u+=s[0];
            for(int i = 1; i < n; i++){
                if(s[i]==s[i-1] && s[i]=='1'){
                    u+="01";
                }
                else if(s[i]==s[i-1] && s[i]=='0'){
                    u+="10";
                }else{
                    u+=s[i];
                }
            }
            cout<<u<<endl;
        }
    }
    return 0;
}