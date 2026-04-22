class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& a) {
        // Code here
        int n = a.size();
        vector<int> b = a;
        sort(b.begin(),b.end());
        int cnt = 0;
        vector<bool> vis(n,false);
        map<int,int> m;
        for(int i = 0; i < n; i++){
            m[a[i]]=i;
        }
        for(int i = 0; i < n; i++){
            if(vis[i] || a[i]==b[i])continue;
            int j = i;
            int cs = 0;
            while(!vis[j]){
                vis[j]=true;
                j = m[b[j]];
                cs++;
            }
            if(cs > 1)cnt+=cs-1;
        }
    
        return cnt;
    }
};