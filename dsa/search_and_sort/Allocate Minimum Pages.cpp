class Solution {
  public:
    bool ok(vector<int> &a, int n, int k, int m){
        int curr = 0;
        int cnt = 1;
        for(int i = 0; i < n; i++){
            curr += a[i];
            
            if(curr > m){
                cnt++;
                curr = a[i];
                if(curr > m)return false;
            }
        }
        return cnt <= k;
    }
    int findPages(vector<int> &a, int k) {
        // code here
        int n = a.size();
        if(k > n)return -1;
        int mx = INT_MIN;
        int s = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx,a[i]);
            s+=a[i];
        }
        int l = mx, r = s;
        int ans = INT_MAX;
        int m;
        while(l <= r){
            m = l + (r-l)/2;
            if(ok(a,n,k,m)){
                ans = min(ans, m);
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
        
    }
};