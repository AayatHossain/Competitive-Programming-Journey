#include <bits/stdc++.h>
using namespace std;

string findSmallestMultiple(int n, const vector<int>& forbidden_digits) {
    vector<bool> forbidden(10, false);
    for (int d : forbidden_digits) {
        forbidden[d] = true;
    }
    
    vector<int> allowed_digits;
    for (int i = 0; i < 10; i++) {
        if (!forbidden[i]) {
            allowed_digits.push_back(i);
        }
    }
    
    if (allowed_digits.empty()) return "-1";
    
    vector<int> parent(n, -1);
    vector<int> digit_used(n, -1);
    vector<bool> visited(n, false);
    
    queue<int> q;
    
    for (int d : allowed_digits) {
        if (d == 0) continue;
        
        int rem = d % n;
        if (rem == 0) {
            return to_string(d);
        }
        
        if (!visited[rem]) {
            visited[rem] = true;
            parent[rem] = -1;
            digit_used[rem] = d;
            q.push(rem);
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int d : allowed_digits) {
            int v = (u * 10 + d) % n;
            
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                digit_used[v] = d;
                
                if (v == 0) {
                    string result;
                    int current = v;
                    while (current != -1) {
                        result += char('0' + digit_used[current]);
                        current = parent[current];
                    }
                    reverse(result.begin(), result.end());
                    return result;
                }
                
                q.push(v);
            }
        }
    }
    
    return "-1";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    int case_num = 1;
    
    while (cin >> n >> m) {
        vector<int> forbidden(m);
        for (int i = 0; i < m; i++) {
            cin >> forbidden[i];
        }
        
        string result = findSmallestMultiple(n, forbidden);
        cout << "Case " << case_num++ << ": " << result << '\n';
    }
    
    return 0;
}