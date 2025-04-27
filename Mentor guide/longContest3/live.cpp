#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int i = 0, j = 1;
        set<string> se;
        bool flag = 0;
        string last;
        string secondlast;
        while (j < n)
        {
            string subStr;
            subStr += s[i];
            subStr += s[j];
            
            if (se.find(subStr) != se.end())
            {
                   
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                
            }
            else
            {
                se.insert(subStr);
                // cout<<subStr<<endl;
                if(j < n && s[j] == s[j+1] && s[j]==s[i]){
                    i = j + 1;
                    j = i + 1;
                }else{
                    i++;j++;
                }
            }
           
        }
        if (!flag)
        {
            cout << "NO" << endl;
        }
    }
}