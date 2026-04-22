// User function Template for C++

void f2(int expo, int a[], int n){
    vector<int> d(10,0);
    vector<int> output(n);
    for(int i = 0; i < n; i++){
        int dig = (a[i]/expo)%10;
        d[dig]++;
    }
    for(int i = 1; i < 10; i++){
        d[i]+=d[i-1];
    }
    
    for(int i = n-1; i >= 0; i--){
        int dig = (a[i]/expo)%10;
        int pos = d[dig];
        pos--;
        d[dig]--;
        output[pos] = a[i];
    }
    for(int i = 0; i < n; i++){
        a[i] = output[i];
    }
    return;
}

void f(int a[],int n){
    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        mx = max(mx,a[i]);
    }
    for(int i = 1; mx/i > 0; i*=10){
        f2(i,a,n);
    }
    return;
}

void radixSort(int a[], int n) {
    f(a,n);
    return;
    
}