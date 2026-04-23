nlogn and 1
class Solution {
  public:
    bool isPossible(int k, vector<int> &a, vector<int> &b) {
        // Your code goes here
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        int n = a.size();
        for(int i = 0; i < n; i++){
            if(a[i]+b[i] < k)return false;
        }
        return true;
    }
};