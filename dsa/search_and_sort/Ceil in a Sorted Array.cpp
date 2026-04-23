//logn and 1
// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& a, int x) {
        // code here
        int n = a.size();
        int l = 0, r = n-1;
        int m; 
        int ans = INT_MAX;
        while(l <= r){
            m = l+(r-l)/2;
            if(a[m] >= x){
                ans = m;
                r = m-1;
            }else{
                l = m + 1;
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};