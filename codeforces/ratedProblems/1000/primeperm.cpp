#include <bits/stdc++.h>
using namespace std;

int prime(int n)
{
    if (n <= 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }else{
            vector<int> a(n+1, -1);
            if(n >= 3){
                int mid = n / 2 + 1;
                for(int i = 1; i <= n; i++){
                    a[i] = i;
                }
                int temp = a[1];
                a[1] = a[2];
                a[2] = temp;


                temp = a[3];
                a[3] = a[n];
                a[n] = temp;

                 temp = a[mid];
                a[mid] = a[2];
                a[2] = temp;


                
            }else{
                a[1] = 2;
                a[2] = 1;
            }
            for(int i = 1; i <= n; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}