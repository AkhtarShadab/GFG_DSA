#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
ll binary_exponentiation(ll a, ll b, ll m)
{
	ll ans = 1;
	while (b)
	{
		if (b % 2 == 1)
		{
			ans = (ans * a) % m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return ans;
}
long long countPairs(int X[], int Y[], int m, int n)
{
	//Your code here
	vector<int> arr(5);
	sort(Y, Y + n);
	for (int i = 0; i < n; ++i)
	{
		switch (Y[i]) {
		case 0: arr[0]++;
			break;
		case 1: arr[1]++;
			break;
		case 2: arr[2]++;
			break;
		case 3: arr[3]++;
			break;
		case 4: arr[4]++;
			break;
		default: break;
		}
	}
	long long ans = 0;
	for (int i = 0; i < m; ++i)
	{
		if (X[i] > 1)
		{
			ans += (long long)(arr[0] + arr[1]);
		}
		switch (X[i]) {
		case 0: break;
		case 1: ans += (long long)arr[0];
			break;
		case 2: ans = ans - (long long)(arr[4] + arr[3]);
			break;
		case 3: ans += (long long)arr[2];
			break;
		}
		if (X[i] > 1)
		{
			long long len = Y + n - upper_bound(Y, Y + n, X[i]);
			ans += len;
		}
		// cout << ans << endl;
	}
	return ans;
}

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
		int n, m;
		cin >> m >> n;
		int x[m], y[n];
		for (int i = 0; i < m; ++i)
		{
			cin >> x[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> y[i];
		}
		cout << countPairs(x, y, m, n);
	}
	return 0;
}


