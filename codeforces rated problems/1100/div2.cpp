#include<bits/stdc++.h>
using namespace std;
#define int long long

int pS(int sum){
    int root = sqrt(sum);
    if(root*root==sum){
        return 1;
    }else{
        return 0;
    }
}

signed main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i;
        }
        if(pS(sum)){
            cout<<-1<<endl;
            continue;
        }

        set<int> nums;
        for(int i = 0; i < n; i++){
            nums.insert(n-i);
        }
        vector<int> a;
        int prefix = 0;
        while(!nums.empty()){
            for(auto it = nums.rbegin(); it != nums.rend(); ++it){
                int num = *it;
                if(!pS(prefix + num)){
                    prefix += num;
                    a.push_back(num);
                    nums.erase(num);
                    break;
                }
            }
        }
    
            // for(int i = 0; i< numbers.size(); i++){
            //     int m = numbers[i];
            //     if(!pS(prefix + m) && (used.find(m) == used.end())){
            //         a.push_back(m);
            //         prefix += m;
            //         used.insert(m);
            //         i=-1;
            //         if(a.size() == n){
            //             break;
            //         }
            //     }
            // }
        
        for(int i = 0; i < n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}