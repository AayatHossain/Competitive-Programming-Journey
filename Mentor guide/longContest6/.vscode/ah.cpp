#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
bool palin(int i, int j)
{
   
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int f(int b, int e)
{
    if(palin(b,e) && b <= e){
        string temp;
        for(int i = b; i <= e; i++){
            temp+=s[i];
        }
        cout<<temp<<endl;
        return 1;
    }
    if(b > e)return 0;
    if(s[b]==s[e]){
        int v1 = f(b+1, e);
        int v2 = f(b, e-1);
        return v1+v2;
    }else{
        int v1 = f(b+1, e);
        int v2 = f(b, e-1);
        int v3 = f(b+1, e-1);
        return v1+v2+v3;
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
        cout << "Case " << c << ": " << f(0, n-1) << endl;
        c++;
    }
}