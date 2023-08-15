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
int maxind(int A[], int N)
{
	int Lmin[N], Rmax[N];
	int res = 0;
	for (int i = 0; i < N; ++i)
	{
		if (i == 0)
		{
			Lmin[i] = A[i];
			Rmax[N - 1 - i] = A[N - 1 - i];
		}
		else
		{
			Lmin[i] = min(A[i], Lmin[i - 1]);
			Rmax[N - 1 - i] = max(Rmax[N - i], A[N - 1 - i]);
		}
	}
	for (int i = 0, j = 0 ; i < N && j < N ;)
	{
		if (Lmin[i] <= Rmax[j])
		{
			res = max(res, j - i);
			j++;
		}
		else
		{
			i++;
		}
	}
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << maxind(a, n);
	return 0;
}
