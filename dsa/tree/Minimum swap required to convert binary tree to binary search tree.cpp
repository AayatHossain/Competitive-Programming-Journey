// User function Template for C++
class Solution {
  public:
    void inorder(vector<int> &arr, vector<int> &a,int i, int n){
        if(i >= n)return;
        
        inorder(arr,a,2*i+1,n);
        a.push_back(arr[i]);
        inorder(arr,a,2*i+2,n);
    }
    
    int swaps(vector<int> &a){
        int n = a.size();
        int ans = 0;
        vector<pair<int,int>> b(n);
        for(int i = 0; i < n; i++){
            b[i] = {a[i], i};
        }
        sort(b.begin(),b.end());
        
        vector<int> v(n,0);
        for(int i = 0; i < n; i++){
            if(v[i] || b[i].second==i)continue;
            
            int j = b[i].second;
            int cycle = 0;
            while(!v[j]){
                v[j] = 1;
                j = b[j].second;
                cycle++;
            }
            if(cycle > 1){
                ans += cycle - 1;
            }
        }
        return ans;
    }
    
    int minSwaps(vector<int>& arr) {
        // Write your code here
        vector<int> a;
        int n = arr.size();
        inorder(arr,a, 0,n);
        int res = swaps(a);
        return res;
    }
};