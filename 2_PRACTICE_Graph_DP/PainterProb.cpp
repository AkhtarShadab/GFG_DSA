#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// } Driver Code Ends
//User function template for C++

class Solution
{
public:
	bool is_Possible(int arr[], int n, int k, ll val)
	{
		// cout << val << endl;
		int check = 1;
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + arr[i] < val) sum += arr[i];
			else {
				check++;
				sum = arr[i];
			}
			// cout << sum << " ";

		}
		// cout << endl;
		if (check > k) return false;
		return true;
	}
	long long minTime(int arr[], int n, int k)
	{
		// code here
		// return minimum time
		int maxi = arr[0], sum = arr[0];
		for (int i = 1; i < n; ++i)
		{
			maxi = max(maxi, arr[i]);
			sum += arr[i];
		}
		if (k >= n) return maxi;

		ll lo = maxi;
		ll hi = sum;
		ll mid;
		while (lo <= hi)
		{
			mid = lo + (hi - lo) / 2;
			if (is_Possible(arr, n, k, mid)) hi = mid - 1;
			else lo = mid + 1;
			// cout << lo << " " << hi << endl;
		}
		// cout << endl << endl;
		// cout << mid << endl;
		if (lo == maxi) return lo;
		return hi;

	}
};
// 35 32 32
//{ Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int k, n;
		cin >> k >> n;

		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
		cout << endl;
	}
	return 0;
}