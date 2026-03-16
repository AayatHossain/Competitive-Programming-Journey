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



//REVERSE THINKING BY GFG

function maxProfit(prices) {
    let minSoFar = prices[0];
    let res = 0;

    
    for (let i = 1; i < prices.length; i++) {
        
        // Update the minimum value seen so far  
        minSoFar = Math.min(minSoFar, prices[i]);

        // Update result if we get more profit                
        res = Math.max(res, prices[i] - minSoFar);
    }
    return res;
}

//Driver Code
const prices = [7, 10, 1, 3, 6, 9, 2];
console.log(maxProfit(prices));