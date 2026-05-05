#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    string s, t;
    cin >> s >> t;

   
    int i = 0, j = 0;
    while (i < s.size() && s[i] == '0') i++;
    while (j < t.size() && t[j] == '0') j++;

    s = s.substr(i);
    t = t.substr(j);

  
    if (s.empty() && t.empty()) {
        cout << "=" << endl;
        return 0;
    }

    
    if (s.size() > t.size()) {
        cout << ">" << endl;
    } else if (s.size() < t.size()) {
        cout << "<" << endl;
    } else {
      
        if (s > t) cout << ">" << endl;
        else if (s < t) cout << "<" << endl;
        else cout << "=" << endl;
    }

    return 0;
}
