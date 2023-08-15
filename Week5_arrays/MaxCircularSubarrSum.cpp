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
ll kadanes(int a[], int n)
{
	long long maxisf = INT_MIN, maxeh = 0;

	for (int i = 0; i < n; i++) {
		maxeh  += a[i];
		if (maxisf < maxeh)
			maxisf = maxeh;

		if (maxeh < 0)
			maxeh = 0;
	}
	return maxisf;
}
ll MaxCircularSubSum(int a[], int n)
{
	// Min sub array sum
	long long minsf = INT_MAX, mineh = 0, sum = 0;

	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
		mineh += a[i];
		if (minsf > mineh)
			minsf = mineh;
		if (mineh > 0)
			mineh = 0;
	}
	if (sum == minsf)
		return kadanes(a, n);
	return max(sum - minsf, kadanes(a, n)) ;
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
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << MaxCircularSubSum(arr, n);
	}
	return 0;
}
