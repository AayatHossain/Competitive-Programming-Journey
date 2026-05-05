#include <bits/stdc++.h>
using namespace std;
signed main()
{
    
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; i < n - 2; i++)
        {
            string t;
            t += s[i];
            t += s[i + 1];
            t += s[i + 2];
            if (t == "abc")
                c++;
        }
        // cout << c << endl;
        while (q--)
        {
            int index;
            char ch;
            cin >> index >> ch;
            index--;
            if (n == 1 || n == 2)
            {
                cout << 0 << endl;
            }
            else
            {
                int before = 0, after = 0;
                string s1,s2,s3;
                if(index-2>=0){
                    s1+=s[index-2];
                    s1+=s[index-1];
                    s1+=s[index];
                }
                if(index-1>=0 && index +1 < n){
                    s2+=s[index-1];
                    s2+=s[index];
                    s2+=s[index+1];
                }
                if(index +2 < n){
                    s3+=s[index];
                    s3+=s[index+1];
                    s3+=s[index+2];
                }
                if(s1=="abc" || s2=="abc"||s3=="abc")before = 1;

                s[index]=ch;
                s1="";s2="",s3="";
                if(index-2>=0){
                    s1+=s[index-2];
                    s1+=s[index-1];
                    s1+=s[index];
                }
                if(index-1>=0 && index +1 < n){
                    s2+=s[index-1];
                    s2+=s[index];
                    s2+=s[index+1];
                }
                if(index +2 < n){
                    s3+=s[index];
                    s3+=s[index+1];
                    s3+=s[index+2];
                }
                if(s1=="abc" || s2=="abc"||s3=="abc")after = 1;

                if(!before && after){
                    c++;
                }else if(before && !after){
                    c--;
                }
                cout<<c<<endl;
                
            }
        }
}
