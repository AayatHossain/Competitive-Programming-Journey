#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,s;cin>>n>>s;
    vector<pair<int,int>> b(n);
    for(int i = 0; i < n; i++){
       int x; cin>>x;
       b[i]={x,i};
    }
    sort(b.begin(),b.end());
    int x=-1,y=-1,z=-1;
    for(int i = 0; i < n-2; i++){
        int j = i+1,k=n-1;
        int temp;
        while(j<k){
            
            temp = b[j].first+b[k].first;
            if(temp==(s-b[i].first)){
                
                x=b[i].second;y=b[j].second;z=b[k].second;
                break;
            }else if(temp > s-b[i].first){
                k--;
            }else{
                j++;
            }
        }
    }
    if(x==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<x+1<<" "<<y+1<<" "<<z+1<<endl;
    }
    return 0;
}