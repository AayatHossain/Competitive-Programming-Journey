#include <bits/stdc++.h>
using namespace std;

#define int long long

bool process(vector<int>& arr, int k) {
    map<int, int> freq;

    // Initialize frequency map
    for (int x : arr) freq[x]++;

    while (true) {
        // Skip if empty (shouldn't happen)
        if (freq.empty()) return true;

        int minVal = freq.begin()->first;
        int maxVal = freq.rbegin()->first;

        // Base case: difference already within k
        if (maxVal - minVal <= k) return true;

        bool changed = false;

        // Try to decrease min if > 0
        if (minVal > 0 && (maxVal - (minVal - 1) <= k)) {
            int count = freq[minVal];
            freq[minVal] -= count;
            if (freq[minVal] == 0) freq.erase(minVal);
            freq[minVal - 1] += count;
            changed = true;
        }
        // Else try to decrease max
        else if (maxVal > 0 && ((maxVal - 1) - minVal <= k)) {
            int count = freq[maxVal];
            freq[maxVal] -= count;
            if (freq[maxVal] == 0) freq.erase(maxVal);
            freq[maxVal - 1] += count;
            changed = true;
        }

        // Neither option was possible, exit
        if (!changed) return false;
    }
}

signed main() {
    int t;cin>>t;
    while(t--){
        int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    bool ok = process(arr, k);
    cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
