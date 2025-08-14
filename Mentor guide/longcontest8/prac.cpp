#include<bits/stdc++.h>
using namespace std ;

#define int long long 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n ; cin >> n ;
    vector<int>v(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> v[i];
    }
    map<int ,int>mp;
    int sum = 0 ;
    int l = 0 , r = 0 ;
    int ans = 0 ;
    while ( l < n && r < n){
         sum += v[r];
        //  cout << sum << '\n';
         if ( sum > 3 ){
            while ( sum >= 2 ){
                sum -= v[l];
                mp[v[l]]--;
                if ( (mp[0]>0&&mp[1]==2) or (mp[0]>0&&mp[1]==1&&mp[2]==1) ){
                    ans++;
                }
                l++;
            }
            r++;
         }
         else {
                mp[v[r]]++;
                if ( (mp[0]>0&&mp[1]==2) or (mp[0]>0&&mp[1]==1&&mp[2]==1) ){
                    ans++;
                }
                r++;
         }
        //  cout << r << '\n';
    }

    cout << ans << '\n';
    
    return 0 ;
}