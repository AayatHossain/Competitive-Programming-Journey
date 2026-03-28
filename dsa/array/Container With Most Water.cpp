class Solution {
public:
    int maxArea(vector<int>& a) {
        int l = 0, r = a.size()-1;
        int mx = INT_MIN;
        while(l < r){
            mx = max(mx, min(a[l],a[r])*(r-l));
            if(a[l] < a[r])l++;
            else r--;
        }
        return mx;
    }
};