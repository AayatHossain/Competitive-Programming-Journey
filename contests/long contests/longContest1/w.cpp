#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string s;
    cin >> s;
    map<char, int> m;
    int n = s.size();
    for (auto x : s)
    {
        m[x]++;
    }
    int c1 = 0, cOdd = 0, c2 = 0;
    for (auto x : m)
    {
        
        if (x.second % 2)
        {
            cOdd++;
        }
    }

    if (((n & 1) == 0 && cOdd > 0) || cOdd > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    
    else
    {
        string s1, s2;
        char mid = 'a';
        for (auto x : m)
        {
            string s(x.second/2, x.first);
            s1 = s1 + s;
            s2 = s + s2;
            if(x.second & 1){
                mid = x.first;
            }
            
        }
        string ans;
        if(cOdd >= 1){
            ans = s1 + mid + s2;
        }else{
            ans = s1 + s2;
        }
        cout<<ans<<endl;
            
    }

    return 0;
}