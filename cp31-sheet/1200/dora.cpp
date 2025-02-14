#include<bits/stdc++.h>
using namespace std;

int bS(int s, int e, vector<pair<int,int>> b, int v){
    int mid;
    while(s <= e){
        mid = (s+e)/2;
        if(b[mid].first == v){
            return b[mid].second;
        }else if(b[mid].first < v){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return - 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<pair<int,int>> b;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            b.push_back(make_pair(a[i], i));
        }
        sort(b.begin(), b.end());
        int start = 0;
        int end = n-1;
        int max = n;
        int min = 1;
        int flag = 0;
        while(start < end){
            
            int maxI = bS(start, end, b,max);
            int minI = bS(start, end, b, min);
            
            // if(max==6 && min==5){
            //     cout<<maxI<<" "<<minI<<" ";
            //     cout<<endl;
            // }
            if(maxI==-1 || minI== -1){
                break;
            }


            int startChanged = 0;
            int endChanged = 0;
            if(maxI==start && startChanged==0){
                start++;
                startChanged = 1;
                max--;
            }
            if(maxI==end && endChanged==0){
                end--;
                endChanged = 1;
                max--;
            }
            if(minI==start && startChanged==0){
                start++;
                startChanged = 1;
                min++;
            }
            if(minI==end && endChanged==0){
                end--;
                endChanged = 1;
                min++;
            }
            // cout<<start<<" "<<end<<"with max and min = "<<max<<" "<<min<<endl;
            if(startChanged==0 && endChanged==0){
                cout<<min<<" "<<max<<endl;
                flag = 1;
                break;
            }
            
        }
        if(!flag){
            cout<<-1<<endl;
        }
    }
    return 0;
}