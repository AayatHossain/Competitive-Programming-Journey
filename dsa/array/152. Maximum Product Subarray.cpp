//ON AND O1

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int c = 0;
        int mx = a[0];
        int mn = a[0];
        c = mx;
        for(int i = 1; i < n; i++){
            int temp = mn;
            mn = min(mn*a[i], min(mx*a[i], a[i]));
            mx = max(temp*a[i], max(mx*a[i], a[i]));
            c = max(c,mx);
        }
        return c;

    }
};