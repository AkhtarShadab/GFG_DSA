#include <bits/stdc++.h>
#include <climits>
// Use Gap Method
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

void merge(long long arr1[], long long arr2[], int n, int m)
{
	// code here
	int a1[n + m];
	int ptr1 = 0, ptr2 = 0, it = 0;
	while (ptr1 != n && ptr2 != m)
	{
		if (arr1[ptr1] < arr2[ptr2]) {
			a1[it] = arr1[ptr1];
			ptr1++;
		}
		else {
			a1[it] = arr2[ptr2];
			ptr2++;

		}
		it++;

	}
	if (ptr1 == n)
	{
		while (ptr2 != m) {
			a1[it] = arr2[ptr2];
			ptr2++;
			it++;
		}
	}
	else {
		while (ptr1 != n) {
			a1[it] = arr1[ptr1];
			ptr1++;
			it++;
		}
	}
	for (int i = 0; i < n + m; ++i)
	{
		cout << a1[i] << " ";
	}


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
		cin >> n >> m;
		ll arr1[n];
		ll arr2[m];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr1[i];
		}


		for (int i = 0; i < m; ++i)
		{
			cin >> arr2[i];
		}
		merge(arr1, arr2, n, m);
	}
	return 0;
}
