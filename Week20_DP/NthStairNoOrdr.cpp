#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
class Solution
{
public:
	//Function to count number of ways to reach the nth stair.

	long long countWays(int m)
	{
		// your code here
		if (m < 3) return m;
		long long ans = 2;
		for (int i = 3; i <= m; ++i)
		{
			if (i % 2 == 0) ans++;
		}
		return ans;
	}
};
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
		int m;
		cin >> m;
		Solution ob;
		cout << ob.countWays(m) << endl;

	}
	return 0;
}
