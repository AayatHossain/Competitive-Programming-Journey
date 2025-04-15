#include <bits/stdc++.h>
using namespace std;
signed main()
{
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            string y;
            int z;
            cin >> y >> z;
            m[y] = z;
        }
        else if (x == 1)
        {
            string y;
            cin >> y;
            if (m.find(y) != m.end())
            {
                cout<< m[y] << endl;
            }else{
                cout<<"0"<<endl;
            }
        }else if(x==2){
            string y; cin>>y;
            m.erase(y);
        }else{
            string left,right; cin>>left>>right;
            auto itB = m.lower_bound(left);
            auto itE = m.upper_bound(right);
            for(auto it = itB; it != itE; it++){
                pair<string,int> p = *it;
                cout<<p.first<<" "<<p.second<<endl;
            }
            
        }
        
    }
    return 0;
}