#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count = 0;
        unordered_set<char> us;
        for(int i = 0; i < n; i++){
            if(us.find(s[i]) == us.end()){
                us.insert(s[i]);
                count += n-i;

            } 
        }
        cout<<count<<endl;
    }
    return 0;
}
