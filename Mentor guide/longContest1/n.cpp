#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    string s, t;
    cin >> s >> t;
    vector<int> ans;
    
    string r;
    for (int i = 0; i < t.size(); i++)
    {
        r += t[i];
    }
    int k = 0, l = t.size() - 1;
    string temp;
    for(int i = 0; i < s.size(); i++){
       temp += s[i];
       if(i==l){
            while(l < s.size()){
                if(temp==r){
                    ans.push_back(k);
                }
                k++;l++;
                temp.erase(0,1);
                temp.push_back(s[l]);

            }
            i = l;
       }
        
    }



    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    // cout<<(int)'0'<<endl;
    return 0;
}