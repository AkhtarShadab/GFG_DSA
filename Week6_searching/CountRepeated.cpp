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
pair<long, long> RepeatCount(long *arr, int n) {

	pair<long, long> p = { -1, -1};
	bool check = false;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] != arr[i - 1])
		{
			continue;
		}
		else {
			p.first = arr[i];
			if (check == false) {
				p.second = 2;
				check = true;
			}
			else p.second++;
		}
	}
	return p;
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
		int n;
		cin >> n;
		long a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		cout << RepeatCount(a, n).first << RepeatCount(a, n).second;
	}
	return 0;
}
