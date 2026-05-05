#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int l,r,L,R;
       cin>>l>>r;
       cin>>L>>R;
       int nL = max(L,l);
       int nR = min(r,R);
       if(nL > nR){
          cout<<-1<<end;
       }else{
          
       }

    }
    return 0;
}
