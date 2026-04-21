class Solution {
  public:
    int findSubarray(vector<int> &a) {
        // code here.
        int n = a.size();
        unordered_map<long long,long long> m;
        m[0] = 1;
        long long s = 0;
        long long res = 0;
        for(int i = 0; i < n; i++){
            s += a[i];
            if(m.find(s)!=m.end()){
                res += m[s];
            }
            m[s]++;
        }
        return res;
    }
};