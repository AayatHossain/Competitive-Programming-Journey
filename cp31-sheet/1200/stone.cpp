#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, q; cin>>n>>q;
    vector<int> a(n);
    vector<int> lfqIndex(n, -1);
    vector<int> lfqValue(n);
    int lsqIndex = -1, lsqValue = -1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin>>x; sum += x; a[i] = x;
    }
    lfqValue = a;

    for(int i = 0; i < q; i++){
        int x;cin>>x;
        if(x==1){
            int indx, val; cin>>indx>>val;
            indx--;
            if(lsqIndex > lfqIndex[indx]){
                sum += val - lsqValue;
                
            }else{
                sum += val - lfqValue[indx];
                
            }
            cout<<sum<<endl;
            lfqIndex[indx] = i;
            lfqValue[indx] = val;
        }else{
            int val;cin>>val;
            sum = n*val;
            lsqIndex = i;
            lsqValue = val;
            cout<<sum<<endl;
        }
    }
    return 0;
}


//red coder code

    // #include<iostream>
    // #include<cstring>
    // using namespace std;
    
    // int n,q,last;
    // int num[200005],cntn[200005];
    // int cnt;
    // long long sum;
    
    // int main(){
    //     cin>>n>>q;
    //     for(int i=1;i<=n;i++){
    //         cin>>num[i];
    //         sum+=num[i];
    //     }
    //     while(q--){
    //         int t;
    //         cin>>t;
    //         if(t==1){
    //             int i,x;
    //             cin>>i>>x;
    //             if(cntn[i]<cnt){
    //                 cntn[i]=cnt;
    //                 num[i]=last;
    //             }
    //             sum+=x-num[i];
    //             num[i]=x;
    //         }else{
    //             int x;
    //             cin>>x;
    //             sum=1LL*n*x;
    //             last=x;
    //             cnt++;
    //         }
    //         cout<<sum<<endl;
    //     }
    //     return 0;
    // }


