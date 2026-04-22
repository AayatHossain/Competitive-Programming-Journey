https://www.naukri.com/code360/problems/make-array-elements-equal_1806889?leftPanelTabValue=PROBLEM

//nlogn and 1
#include <bits/stdc++.h> 
int findMinimumCost(vector<int> &a, int n)
{
	sort(a.begin(),a.end());
	int v = a[n/2];
	int c = 0;
	for(int i = 0; i < n; i++){
		c += abs(a[i] - v);
	}
	return c;
}


//same complexity but cost = left + right approach
#include <bits/stdc++.h> 

int findMinimumCost(vector<int> &a, int n)
{
	int ans = INT_MAX;
	int right = 0;
	for(int i = 0; i < n; i++)right+=a[i];

	int left = 0;
	sort(a.begin(),a.end());
	for(int i = 0; i < n; i++){
		right -= a[i];

		int cl = i*a[i] - left;
		int cr = right - (n-i-1)*a[i];
		int c = cl+cr;

		left += a[i];

		ans = min(ans, c);
	}
	return ans;
}




