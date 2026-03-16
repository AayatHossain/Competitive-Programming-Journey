//ON AND O1 XOR SOLUTION

vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int n = a.size();
    unsigned int x = 0;
    for(int i = 1; i <= n; i++){
        x ^= i;
        x ^= a[i-1];
    }
    vector<int> ans(2,0);
    x &= -x;
    for(int i = 0; i < n; i++){
        if(x&a[i]){
            ans[1] ^= a[i]; 
        }else{
            ans[0] ^= a[i];
        }
        
        
        if(x&(i+1)){
            ans[1] ^= (i+1); 
        }else{
            ans[0] ^= (i+1);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(ans[1]==a[i]){
            swap(ans[0],ans[1]);
            break;
        }
    }
    
    return ans;
}




//ON AND O1 MY SOLUTION. SUM METHOD

vector<int> Solution::repeatedNumber(const vector<int> &a) {
    
    int n = a.size();
    long long sn=0,sc=0,sn2=0,sc2=0;
    for(int i = 0 ;i < n; i++){
        sc += a[i];
        sc2+= 1LL*a[i]*a[i];
    }
    
    sn = 1LL*n*(n+1)/2;
    sn2 = 1LL*n*(n+1)*(2*n+1)/6;
    
    long long bpa = (sn2-sc2)/(sn-sc);
    long long bma = sn-sc;
    
    int b = (bpa+bma)/2;
    int aa = bpa - b;
    
    return {aa,b};
}



