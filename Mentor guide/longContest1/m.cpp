#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int L, R;
        cin >> L >> R;
        int sum = 0;
        for (int i = L; i < R + 1; i++)
        {
            string str = to_string(i);
            string str1 = str;
            reverse(str.begin(), str.end());

            if (str1 == str)
            {
                sum = sum + stoi(str);
            }
        }
        cout << sum << endl;
    }
    return 0;
}