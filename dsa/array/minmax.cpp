class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i = 0; i < (int)arr.size(); i++){
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }
        return {mn,mx};
    }
};