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



