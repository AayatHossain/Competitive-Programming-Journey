class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int ans = INT_MAX;
        int n = a.size();
        for(int i = m-1; i < n; i++){
            ans = min(ans, a[i] - a[i-(m-1)]);
        }
        return ans;
    }
};