#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int n,x,y,z; cin>>n>>x>>y>>z;
    vector<int> a(n);
    vector<int> b(n);
    
    for(int i= 0; i < n; i++){
        cin>>a[i];
    }
    for(int i= 0; i < n; i++){
        cin>>b[i];
    }

    set<int> s;
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        pq.push({a[i],-i});
    } 

    for(int i = 0; i < x; i++){
        int v = -pq.top().second;
        s.insert(v);
        // cout<<v<<endl;
        pq.pop();
    }

    priority_queue<pair<int,int>> pq2;
    while(!pq.empty()){
        int index = -pq.top().second;
        pq.pop();

       
        // s.insert(index);
        pq2.push({b[index], -index});
    }




    //english
    for(int i = 0; i < y; i++){
        int v = -pq2.top().second;
        s.insert(v);
        
        pq2.pop();
    }

    priority_queue<pair<int,int>> pq3;
    while(!pq2.empty()){
        int index = -pq2.top().second;
        //  cout<<index<<endl;
        pq2.pop();

        // s.insert(index);
        pq3.push({b[index]+a[index], -index});
    }


    for(int i = 0; i < z; i++){
        int v = -pq3.top().second;
        s.insert(v);
        pq3.pop();
    }

    for(auto x: s){ 
        cout<<x+1<<endl;
    }



    return 0;
}