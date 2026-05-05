#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9;

int lb(int k, int l1, int r1, int l2, int r2){
    int s = l1, e = r1;
    int m;
    int ans = LLONG_MAX;
    while(s <= e){
        m = s + (e-s)/2;
        if(m*k >= l2 && m*k <= r2){
            ans = m;
            e = m-1;
        }else if(m*k > r2){
            e = m-1;
        }else if(m*k < l2){
            s = m+1;
        }
    }
    if(ans==LLONG_MAX){
        return -1;
    }
    return ans;
}

int ub(int k, int l1, int r1, int l2, int r2){
    int s = l1, e = r1;
    int m;
    int ans = LLONG_MIN;
    while(s <= e){
        m = s + (e-s)/2;
        if(m*k >= l2 && m*k <= r2){
            ans = m;
            s = m+1;
        }else if(m*k > r2){
            e = m-1;
        }else if(m*k < l2){
            s = m+1;
        }
    }
    if(ans==LLONG_MIN){
        return -1;
    }
    return ans;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int k,l1,r1,l2,r2; cin>>k>>l1>>r1>>l2>>r2;
        int ans = 0;
        for(int i = 1; i <= max(r1,r2); i*=k){
            int lowerVal = lb(i,l1,r1,l2,r2);
            if(lowerVal==-1)continue;
            int upperVal = ub(i,l1,r1,l2,r2);
            ans += upperVal - lowerVal + 1;
        }
        cout<<ans<<endl;


    }  
    return 0;
}