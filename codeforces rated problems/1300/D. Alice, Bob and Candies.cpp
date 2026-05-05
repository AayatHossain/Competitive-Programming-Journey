#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int t = 1,i=1,j=n-1,m=1,al=a[0],b=0,lal=al,lb=0,s=0;
        while((i<n && j>=0) && (i<=j)){
            if(t){
                lb = 0;
                while(j>=0 && j >= i && lb <= lal){
                    lb+=a[j];
                    j--;
                }
                b+=lb;
                t=0;
            }else{
                lal = 0;
                while(i<n && i<=j && (lal <= lb)){
                    lal+=a[i];
                    i++;
                }
                al+=lal;
                t=1;
            }
            m++;
        // cout<<m<<" "<<al<<" "<<b<<'\n';
            
        }
        cout<<m<<" "<<al<<" "<<b<<'\n';
    }
    return 0;
}