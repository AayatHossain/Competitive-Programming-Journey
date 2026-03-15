//suffix max and iterate from right to left

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int mx = a[n-1];
        int ans = -1;
        for(int i = n-2;i >= 0; i--){
            int v = mx - a[i];
            ans = max(ans,max(v,0));
            // cout<<mx<<" "<<a[i]<<endl;
            mx = max(a[i],mx);
        }
        if(ans==-1)ans = 0;
        return ans;
    }
};