#include <bits/stdc++.h>
using namespace std;
#define int long long
bool palindrome(string s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i]!=s[j]){
            return false;
        }else{
            i++; j--;
        }
    }
    return true;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;cin>>n;string s;cin>>s;
        int ans = LLONG_MAX;
        if(palindrome(s)){
            cout<<0<<endl;
            continue;
        }
        for(char c = 'a'; c <= 'z'; c++){
            string newString;
            for(int j = 0; j < n; j++){
                if(s[j] != c){
                    newString+=s[j];
                }
            }
            if(palindrome(newString)){
                int count = 0;
                int i = 0, j = s.size() - 1;
                while(i < j){
                    if(s[i]==s[j]){
                        i++; j--;
                    }else if(s[i]==c && s[j] != c){
                        i++; count++;
                    }else{
                        j--; count++;
                    }
                }
            //    if(count==1){
            //     cout<<c<<endl;
            //    }
                ans = min(ans, count);
            }
        }
        if(ans==LLONG_MAX){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }

    }
}