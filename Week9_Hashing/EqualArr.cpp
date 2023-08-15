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
bool check(vector<ll> A, vector<ll> B, int N) {
	//code here
	unordered_map<ll, int> mp;
	for (int i = 0; i < N; ++i)
	{
		mp[A[i]]++;
		mp[B[i]]--;
	}
	for (auto i = mp.begin(); i != mp.end(); ++i)
	{
		if (i->second != 0) return 0;
	}
	return 1;
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
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> b[i];
		}
		cout << check(a, b, n);
	}
	return 0;
}
