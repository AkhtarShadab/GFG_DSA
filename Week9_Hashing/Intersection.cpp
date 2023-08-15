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
int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
	// Your code goes here
	unordered_set<int> st;
	int mini = min(n, m);
	int count = 0;
	if (mini == n)
	{
		for (int i = 0; i < n; ++i)
		{
			st.insert(a[i]);
		}
		for (int i = 0; i < m; ++i)
		{
			if (st.count(b[i])) count++;
		}
	}
	else {
		for (int i = 0; i < n; ++i)
		{
			st.insert(a[i]);
		}
		for (int i = 0; i < m; ++i)
		{
			if (st.count(b[i])) {count++; st.erase(st.find(b[i]));}
		}

	}
	return count;
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
		int arr[n], brr[m];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> brr[i];
		}
		cout << NumberofElementsInIntersection(arr, brr, n, m);

	}
	return 0;
}
