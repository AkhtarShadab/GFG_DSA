#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long countWays(int n, int k) {
		// code here
		if (n == 1) return k;
		long long same[n], diff[n], total[n];

		same[0] = 0;
		diff[0] = k;
		total[0] = k;
		same[1] = k;
		diff[1] = k * (k - 1);
		total[1] = same[1] + diff[1];
		for (int i = 2; i < n; i++)
		{
			diff[i] = (((diff[i - 2] + diff[i - 1]) % mod) * (k - 1)) % mod;
			same[i] = diff[i - 1];
			total[i] = (same[i] + diff[i]) % mod;
		}
		return total[n - 1];
	}
};

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
		int n, k;
		cin >> n >> k;
		Solution ob;
		cout << ob.countWays(n, k) << endl;
	}
	return 0;
}