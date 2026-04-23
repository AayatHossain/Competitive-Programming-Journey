//nlogn and 1. sort and 2p

class Solution {
  public:
    bool findPair(vector<int> &a, int x) {
        // code here
        int n = a.size();
        sort(a.begin(),a.end());
        int i = 0, j = 1;
        while(i < n && j < n){
            if(i==j){
                j++;continue;
            }
            if(a[j]-a[i] == x)return true;
            else if(a[j]-a[i] < x)j++;
            else i++;
        }
        return false;
        
    }
};



//n and n. hashset

class Solution {
  public:
    bool findPair(vector<int> &a, int x) {
        // code here
        int n = a.size();
        set<int> s;
        s.insert(a[0]);
        for(int i = 1; i < n; i++){
            int v1 = a[i]+x;
            int v2 = a[i]-x;
            if(s.find(v1)!=s.end())return true;
            if(s.find(v2)!=s.end())return true;
            s.insert(a[i]);
        }
        return false;
        
    }
};
