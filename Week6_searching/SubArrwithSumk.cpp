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
vector<int> subArraySumK(vector<int> arr, int n , long long s )
{
	long long sum = arr[0];
	int ptr1 = 0, ptr2 = 0;
	if (sum == s) return {1, 1};

	while (ptr2 < n - 1) {
		if (sum + arr[ptr2 + 1] <= s) {
			sum += arr[ptr2 + 1];
			ptr2++;
		}
		else {
			sum -= arr[ptr1];
			ptr1++;
		}
		if (sum == s) {
			return {ptr1 + 1, ptr2 + 1};
		}
	}
	return { -1};


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
		int n, s;
		cin >> n >> s;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		vector<int> ans = subArraySumK(a, n, s);
		for (auto x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}

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



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		int pref[n];
		for (int i = 0; i < n; ++i)
		{
			if (i == 0) pref[i] = a[i];
			pref[i] = a[i] + pref[i - 1];
		}
		int lo = 0;
		int hi = n - 1;
		while (lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;

		}

	}
}

