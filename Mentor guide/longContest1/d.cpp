#include <bits/stdc++.h>
using namespace std;
signed main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    string large, small;
    if(n >= m){
        large = s; small = t;
    }else{
        large = t; small = s;
    }
    
    while(large.size() > 0){
        if(large != small){
            if(large.size()<small.size()){
                large.clear();
                break;
            }
            cout<<large.size()<<endl;
            break;
        }else{
            large.pop_back();
        }
    }
    if(large.size()==0){cout<<-1<<endl;}
    return 0;
}